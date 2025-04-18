mmec <- function(fixed, random, rcov, data, W,
                 nIters=25, tolParConvLL = 1e-03,
                 tolParConvNorm = 1e-04, tolParInv = 1e-06,
                 naMethodX="exclude",
                 naMethodY="exclude",
                 returnParam=FALSE,
                 dateWarning=TRUE,
                 verbose=TRUE, addScaleParam=NULL,
                 stepWeight=NULL, emWeight=NULL, 
                 contrasts=NULL){

  my.date <- "2025-06-01"
  your.date <- Sys.Date()
  ## if your month is greater than my month you are outdated
  if(dateWarning){
    if (your.date > my.date) {
      cat("Version out of date. Please update sommer to the newest version using:\ninstall.packages('sommer') in a new session\n Use the 'dateWarning' argument to disable the warning message.")
    }
  }

  if(missing(data)){
    data <- environment(fixed)
    if(!missing(random)){
      data2 <- environment(random)
    }
    nodata <-TRUE
    cat("data argument not provided \n")
  }else{nodata=FALSE; data <- as.data.frame(data)}

  if(missing(rcov)){
    rcov = as.formula("~units")
  }

  #################
  ## do the needed for naMethodY and naMethodX
  dataor <- data
  provdat <- subdata(data, fixed=fixed, na.method.Y = naMethodY,na.method.X=naMethodX)
  data <- provdat$datar
  nonMissing <- provdat$good
  #################
  data$units <- levels(as.factor(paste("u",1:nrow(data),sep="")))
  #################
  ## get Y matrix
  response <- strsplit(as.character(fixed[2]), split = "[+]")[[1]]
  responsef <- as.formula(paste(response,"~1"))
  mfna <- try(model.frame(responsef, data = data, na.action = na.pass), silent = TRUE)
  if (is(mfna, "try-error") ) { # class(mfna) == "try-error"
    stop("Please provide the 'data' argument for your specified variables.\nYou may be specifying some variables in your model not present in your dataset.", call. = FALSE)
  }
  mfna <- eval(mfna, data, parent.frame())
  yvar <- sparse.model.matrix(as.formula(paste("~",response,"-1")),data)
  nt <- ncol(yvar)
  if(nt==1){colnames(yvar) <- response}
  Vy <- var(yvar[,1])
  # yvar <- scale(yvar)
  #################
  ## get Zs and Ks

  Z <- Ai <- theta <- thetaC <- thetaF <- sp <- list()
  Zind <- numeric()
  rTermsNames <- list()
  counter <- 1
  if(!missing(random)){ # if there's random effects

    yuyu <- strsplit(as.character(random[2]), split = "[+]")[[1]] # random parts
    rtermss <- apply(data.frame(yuyu),1,function(x){ # split random terms
      strsplit(as.character((as.formula(paste("~",x)))[2]), split = "[+]")[[1]]
    })

    for(u in 1:length(rtermss)){ # for each random effect
      checkvs <- intersect(all.names(as.formula(paste0("~",rtermss[u]))),c("vsc","spl2Dc")) # which(all.names(as.formula(paste0("~",rtermss[u]))) %in% c("vs","spl2Da","spl2Db")) # grep("vs\\(",rtermss[u])

      if(length(checkvs)==0){ ## if this term is not in a variance structure put it inside
        rtermss[u] <- paste("vsc( isc(",rtermss[u],") )")
      }
      ff <- eval(parse(text = rtermss[u]),data,parent.frame()) # evaluate the variance structure
      Z <- c(Z, ff$Z)
      Ai <- c(Ai, ff$Gu)
      theta[[u]] <- ff$theta
      thetaC[[u]] <- ff$thetaC
      thetaF[[u]] <- ff$thetaF
      sp[[u]] <- ff$sp # rep(ff$sp,length(which(ff$thetaC > 0)))
      Zind <- c(Zind, rep(u,length(ff$Z)))
      checkvs <- numeric() # restart the check
      ## names for monitor
      baseNames <- which( ff$thetaC > 0, arr.ind = TRUE)
      s1 <- paste(rownames(ff$thetaC)[baseNames[,"row"]], colnames(ff$thetaC)[baseNames[,"col"]],sep = ":")
      s2 <- paste(all.vars(as.formula(paste("~",rtermss[u]))),collapse=":")
      rTermsNames[[u]] <- paste(s2,s1,sep=":")

      counter <- counter + 1
    }
  }

  #################
  ## get Rs

  yuyur <- strsplit(as.character(rcov[2]), split = "[+]")[[1]]
  rcovtermss <- apply(data.frame(yuyur),1,function(x){
    strsplit(as.character((as.formula(paste("~",x)))[2]), split = "[+]")[[1]]
  })

  S <- list()
  Spartitions <- list()
  for(u in 1:length(rcovtermss)){ # for each random effect
    checkvs <- intersect(all.names(as.formula(paste0("~",rcovtermss[u]))),c("vsc","gvs","spl2Da","spl2Db")) # which(all.names(as.formula(paste0("~",rtermss[u]))) %in% c("vs","spl2Da","spl2Db")) # grep("vs\\(",rtermss[u])

    if(length(checkvs)==0){ ## if this term is not in a variance structure put it inside
      rcovtermss[u] <- paste("vsc( isc(",rcovtermss[u],") )")
    }

    ff <- eval(parse(text = rcovtermss[u]),data,parent.frame()) # evalaute the variance structure
    S <- c(S, ff$Z)
    Spartitions <- c(Spartitions, ff$partitionsR)
    ## constraint
    residualsNonFixed <- which(ff$thetaC != 3, arr.ind = TRUE)
    if(nrow(residualsNonFixed) > 0){
      ff$theta[residualsNonFixed] <- ff$theta[residualsNonFixed] * 5
    }
    theta[[counter]] <- ff$theta
    thetaC[[counter]] <- ff$thetaC
    thetaF[[counter]] <- ff$thetaF
    sp[[counter]] <- ff$sp#rep(ff$sp,length(ff$Z))

    baseNames <- which( ff$thetaC > 0, arr.ind = TRUE)
    s1 <- paste(rownames(ff$thetaC)[baseNames[,"row"]], colnames(ff$thetaC)[baseNames[,"col"]],sep = ":")
    s2 <- paste(all.vars(as.formula(paste("~",rcovtermss[u]))),collapse=":")
    rTermsNames[[counter]] <- paste(s2,s1,sep=":")

    checkvs <- numeric() # restart the check
    counter <- counter + 1
  }
  #################
  #################
  ## get Xs
  data$`1` <-1
  newfixed=fixed
  fixedTerms <- gsub(" ", "", strsplit(as.character(fixed[3]), split = "[+-]")[[1]])
  mf <- try(model.frame(newfixed, data = data, na.action = na.pass), silent = TRUE)
  mf <- eval(mf, parent.frame())
  X <-  Matrix::sparse.model.matrix(newfixed, mf, contrasts.arg=contrasts)


  partitionsX <- list()#as.data.frame(matrix(NA,length(fixedTerms),2))
  for(ix in 1:length(fixedTerms)){ # save indices for partitions of each fixed effect
    effs <- colnames(Matrix::sparse.model.matrix(as.formula(paste("~",fixedTerms[ix],"-1")), mf))
    effs2 <- colnames(Matrix::sparse.model.matrix(as.formula(paste("~",fixedTerms[ix])), mf))
    partitionsX[[ix]] <- matrix(which(colnames(X) %in% c(effs,effs2)),nrow=1)
  }
  names(partitionsX) <- fixedTerms
  classColumns <- lapply(data,class)

  for(ix in 1:length(fixedTerms)){ # clean column names in X matrix
    colnamesBase <- colnames(X)[partitionsX[[ix]]]
    colnamesBaseList <- strsplit(colnamesBase,":")
    toRemoveList <- strsplit(fixedTerms[ix],":")[[1]] # words to remove from the level names in the ix.th fixed effect
    # print(toRemoveList)
    if("1" %in% unlist(toRemoveList)){}else{toRemoveList <- all.vars(as.formula(paste("~",paste(toRemoveList, collapse = "+"))))}
    for(j in 1:length(toRemoveList)){
      if( toRemoveList[[j]] %in% names(classColumns) ){
        
        if( classColumns[[toRemoveList[[j]]]] != "numeric"){ # only remove the name from the level if is structure between factors, not for random regressions
          nc <- nchar(gsub(" ", "", toRemoveList[[j]], fixed = TRUE)) # number of letters to remove
          colnamesBaseList <- lapply(colnamesBaseList, function(h){
            if(is.na(h[j])){ # is the intercept? no
              return(h)
            }else{ # is the intercept? yes
              if(length(grep(toRemoveList[[j]],h[j])) == 1){ # if the factor word matches in the level
                if(nchar(h[j]) > nc){h[j] <- substr(h[j],1+nc,nchar(h[j]))}
              }
              return(h)
            }
          }) # only remove the initial name if the name is actually longer
        }
        
      }
    }
    colnames(X)[partitionsX[[ix]]] <- unlist(lapply(lapply(colnamesBaseList,na.omit), function(x){paste(x, collapse=":")}))
  }
  step1 <- gsub(" ", "", strsplit(as.character(fixed[3]), split = "[-]")[[1]])
  step2 <- unlist(apply(data.frame(step1),1,function(x){strsplit(as.character(x), split = "[+]")[[1]]}))
  intercCheck <- ifelse(length(intersect(c("1","-1"),step2)) == 0, TRUE, FALSE) # if length is zero it means that we have an intercept
  if(intercCheck){colnames(X)[1] <- "Intercept"}

  #################
  #################
  ## weight matrix

  if(missing(W)){
    x <- data.frame(d=as.factor(1:length(yvar)))
    W <- sparse.model.matrix(~d-1, x)
    useH=FALSE
  }else{
    W <- as(as(as( W ,  "dMatrix"), "generalMatrix"), "CsparseMatrix") # as(W, Class = "dgCMatrix")
    useH=TRUE
  }

  #################
  #################
  ## information weights

  if(is.null(emWeight)){
    initialEmSteps <- logspace(round(nIters*.8), 1, 0.009) # 80% of the iterations requested are used for the logarithmic decrease
    restEmSteps <- rep(0.009, nIters - length(initialEmSteps)) # the rest we assign a very small emWeight value
    emWeight <- c( initialEmSteps, restEmSteps) # plot(emWeight) # we bind both for the modeling
  }
  if(is.null(stepWeight)){
    w <- which(emWeight <= .04) # where AI starts
    if(length(w) > 1){ # w has at least length = 2
      stepWeight <- rep(.9,nIters);
      if(nIters > 1){stepWeight[w[1:2]] <- c(0.5,0.7)} # .5, .7
    }else{
      stepWeight <- rep(.9,nIters);
      if(nIters > 1){stepWeight[1:2] <- c(0.5,0.7)} # .5, .7
    }
    # stepWeight[1:3]=3
  }

  #################
  #################
  ## information weights
  theta <- lapply(theta, function(x){return(x*Vy)})

  if(returnParam){

    # args <- list(fixed=fixed, random=random, rcov=rcov, data=data, W=W,
    #              nIters=nIters, tolParConv=tolParConv, tolParInv=tolParInv,
    #              naMethodX=naMethodX,
    #              naMethodY=naMethodY,
    #              returnParam=returnParam,
    #              dateWarning=dateWarning,
    #              verbose=verbose)
    #
    # good <- provdat$good

    thetaFinput <- do.call(adiag1,thetaF)
    if(is.null(addScaleParam)){addScaleParam=0}
    thetaFinputSP <- unlist(sp)
    thetaFinput <- cbind(thetaFinput,thetaFinputSP)
    thetaFinput

    res <- list(yvar=yvar, X=X,Z=Z,Zind=Zind,Ai=Ai,S=S,Spartitions=Spartitions, W=W, useH=useH,
                nIters=nIters, tolParConvLL=tolParConvLL, tolParConvNorm=tolParConvNorm,
                tolParInv=tolParInv,
                verbose=verbose, addScaleParam=addScaleParam,
                theta=theta,thetaC=thetaC, thetaF=thetaFinput,
                stepWeight=stepWeight,emWeight=emWeight
    )
  }else{

    thetaFinput <- do.call(adiag1,thetaF)
    if(is.null(addScaleParam)){addScaleParam=0}
    thetaFinputSP <- unlist(sp)

    thetaFinput <- cbind(thetaFinput,thetaFinputSP)
    thetaFinput
    res <- .Call("_sommer_ai_mme_sp",PACKAGE = "sommer",
                 X,Z, Zind,
                 Ai,yvar,
                 S, Spartitions, W, useH,
                 nIters, tolParConvLL, tolParConvNorm,
                 tolParInv,theta,
                 thetaC,thetaFinput,
                 addScaleParam,
                 emWeight,
                 stepWeight,
                 verbose)

    # res <-ai_mme_sp(X=X,ZI=Z, Zind=Zind,
    #                 AiI=Ai,y=yvar,
    #                 SI=S, Spartitions,
    #                 H=W, useH=useH,
    #                 nIters=nIters, tolParConvLL=tolParConvLL,
    #                 tolParConvNorm=tolParConvNorm,
    #                 tolParInv=tolParInv,thetaI=theta,
    #                 thetaCI=thetaC,thetaF=thetaFinput,
    #                 addScaleParam=addScaleParam,
    #                 weightEmInf=emWeight,
    #                 weightInf=stepWeight,
    #                 verbose=verbose
    # )

    rownames(res$b) <- colnames(X)
    if(!missing(random)){
      rownames(res$u) <- unlist(lapply(Z, colnames))
    }
    rownames(res$monitor) <- unlist(rTermsNames)
    res$sigma <- res$monitor[,which(res$llik[1,] == max(res$llik[1,]))] # we return the ones with max llik
    res$data <- data
    res$y <- yvar
    res$partitionsX <- partitionsX
    uList <- uPevList <- vector(mode="list",length = length(res$partitions))
    if(!missing(random)){
      names(res$partitions) <- rtermss
      for(i in 1:length(res$partitions)){
        blupTable <- apply(res$partitions[[i]],1,function(x2){return(res$bu[x2[1]:x2[2]])})
        pevTable <- apply(res$partitions[[i]],1,function(x2){return(diag(res$Ci)[x2[1]:x2[2]])})
        if(length(blupTable) == 1){ # if is a single value instead of a matrix
          blupTable <- as.data.frame(blupTable);
          pevTable <- as.data.frame(pevTable); 
        }
        colnames(blupTable) <- colnames(pevTable) <- colnames(theta[[i]])
        rownames(blupTable) <- rownames(pevTable) <- colnames(Z[[which(Zind == i)[1]]])
        uList[[i]] <- blupTable; uPevList[[i]] <- pevTable
      }; blupTable=NULL; pevTable=NULL; names(uList) <- names(uPevList) <- rtermss
    }
    res$uList <- uList; res$uPevList <- uPevList
    if(!missing(random)){
      res$args <- list(fixed=fixed, random=random, rcov=rcov)
      res$Dtable <- data.frame(type=c(rep("fixed",length(res$partitionsX)),rep("random",length(res$partitions))),term=c(names(res$partitionsX),names(res$partitions)),include=FALSE,average=FALSE)
    }else{
      res$args <- list(fixed=fixed, rcov=rcov)
      res$Dtable <- data.frame(type=c(rep("fixed",length(res$partitionsX))),term=c(names(res$partitionsX),names(res$partitions)),include=FALSE,average=FALSE)
    }
    
    class(res)<-c("mmec")
  }
  return(res)
}
