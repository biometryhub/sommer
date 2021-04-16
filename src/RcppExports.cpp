// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// currentDateTime
const std::string currentDateTime();
RcppExport SEXP _sommer_currentDateTime() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(currentDateTime());
    return rcpp_result_gen;
END_RCPP
}
// seqCpp
arma::vec seqCpp(const int& a, const int& b);
RcppExport SEXP _sommer_seqCpp(SEXP aSEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int& >::type a(aSEXP);
    Rcpp::traits::input_parameter< const int& >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(seqCpp(a, b));
    return rcpp_result_gen;
END_RCPP
}
// mat_to_vecCpp
arma::vec mat_to_vecCpp(const arma::mat& x, const arma::mat& x2);
RcppExport SEXP _sommer_mat_to_vecCpp(SEXP xSEXP, SEXP x2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type x2(x2SEXP);
    rcpp_result_gen = Rcpp::wrap(mat_to_vecCpp(x, x2));
    return rcpp_result_gen;
END_RCPP
}
// vec_to_cubeCpp
arma::cube vec_to_cubeCpp(const arma::vec& x, const Rcpp::List& g);
RcppExport SEXP _sommer_vec_to_cubeCpp(SEXP xSEXP, SEXP gSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type g(gSEXP);
    rcpp_result_gen = Rcpp::wrap(vec_to_cubeCpp(x, g));
    return rcpp_result_gen;
END_RCPP
}
// varCols
arma::vec varCols(const arma::mat& x);
RcppExport SEXP _sommer_varCols(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(varCols(x));
    return rcpp_result_gen;
END_RCPP
}
// scaleCpp
arma::mat scaleCpp(const arma::mat& x);
RcppExport SEXP _sommer_scaleCpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(scaleCpp(x));
    return rcpp_result_gen;
END_RCPP
}
// makeFull
arma::mat makeFull(const arma::mat& X);
RcppExport SEXP _sommer_makeFull(SEXP XSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    rcpp_result_gen = Rcpp::wrap(makeFull(X));
    return rcpp_result_gen;
END_RCPP
}
// isIdentity_mat
bool isIdentity_mat(const arma::mat x);
RcppExport SEXP _sommer_isIdentity_mat(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(isIdentity_mat(x));
    return rcpp_result_gen;
END_RCPP
}
// isIdentity_spmat
bool isIdentity_spmat(const arma::sp_mat x);
RcppExport SEXP _sommer_isIdentity_spmat(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(isIdentity_spmat(x));
    return rcpp_result_gen;
END_RCPP
}
// isDiagonal_mat
bool isDiagonal_mat(const arma::mat x);
RcppExport SEXP _sommer_isDiagonal_mat(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(isDiagonal_mat(x));
    return rcpp_result_gen;
END_RCPP
}
// isDiagonal_spmat
bool isDiagonal_spmat(const arma::sp_mat x);
RcppExport SEXP _sommer_isDiagonal_spmat(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(isDiagonal_spmat(x));
    return rcpp_result_gen;
END_RCPP
}
// amat
arma::mat amat(const arma::mat& Xo, const bool& endelman, double minMAF);
RcppExport SEXP _sommer_amat(SEXP XoSEXP, SEXP endelmanSEXP, SEXP minMAFSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Xo(XoSEXP);
    Rcpp::traits::input_parameter< const bool& >::type endelman(endelmanSEXP);
    Rcpp::traits::input_parameter< double >::type minMAF(minMAFSEXP);
    rcpp_result_gen = Rcpp::wrap(amat(Xo, endelman, minMAF));
    return rcpp_result_gen;
END_RCPP
}
// dmat
arma::mat dmat(const arma::mat& Xo, const bool& nishio, double minMAF);
RcppExport SEXP _sommer_dmat(SEXP XoSEXP, SEXP nishioSEXP, SEXP minMAFSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Xo(XoSEXP);
    Rcpp::traits::input_parameter< const bool& >::type nishio(nishioSEXP);
    Rcpp::traits::input_parameter< double >::type minMAF(minMAFSEXP);
    rcpp_result_gen = Rcpp::wrap(dmat(Xo, nishio, minMAF));
    return rcpp_result_gen;
END_RCPP
}
// emat
arma::mat emat(const arma::mat& X1, const arma::mat& X2);
RcppExport SEXP _sommer_emat(SEXP X1SEXP, SEXP X2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X1(X1SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type X2(X2SEXP);
    rcpp_result_gen = Rcpp::wrap(emat(X1, X2));
    return rcpp_result_gen;
END_RCPP
}
// hmat
arma::mat hmat(const arma::mat& A, const arma::mat& G22, const arma::vec& index, double tolparinv, double tau, double omega);
RcppExport SEXP _sommer_hmat(SEXP ASEXP, SEXP G22SEXP, SEXP indexSEXP, SEXP tolparinvSEXP, SEXP tauSEXP, SEXP omegaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type G22(G22SEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type index(indexSEXP);
    Rcpp::traits::input_parameter< double >::type tolparinv(tolparinvSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type omega(omegaSEXP);
    rcpp_result_gen = Rcpp::wrap(hmat(A, G22, index, tolparinv, tau, omega));
    return rcpp_result_gen;
END_RCPP
}
// scorecalc
arma::rowvec scorecalc(const arma::mat& Mimv, const arma::mat& Ymv, const arma::mat& Zmv, const arma::mat& Xmv, const arma::mat& Vinv, int nt, double minMAF);
RcppExport SEXP _sommer_scorecalc(SEXP MimvSEXP, SEXP YmvSEXP, SEXP ZmvSEXP, SEXP XmvSEXP, SEXP VinvSEXP, SEXP ntSEXP, SEXP minMAFSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Mimv(MimvSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Ymv(YmvSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Zmv(ZmvSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Xmv(XmvSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Vinv(VinvSEXP);
    Rcpp::traits::input_parameter< int >::type nt(ntSEXP);
    Rcpp::traits::input_parameter< double >::type minMAF(minMAFSEXP);
    rcpp_result_gen = Rcpp::wrap(scorecalc(Mimv, Ymv, Zmv, Xmv, Vinv, nt, minMAF));
    return rcpp_result_gen;
END_RCPP
}
// gwasForLoop
arma::mat gwasForLoop(const arma::mat& M, const arma::mat& Y, const arma::mat& Z, const arma::mat& X, const arma::mat& Vinv, double minMAF, bool display_progress);
RcppExport SEXP _sommer_gwasForLoop(SEXP MSEXP, SEXP YSEXP, SEXP ZSEXP, SEXP XSEXP, SEXP VinvSEXP, SEXP minMAFSEXP, SEXP display_progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type M(MSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type Vinv(VinvSEXP);
    Rcpp::traits::input_parameter< double >::type minMAF(minMAFSEXP);
    Rcpp::traits::input_parameter< bool >::type display_progress(display_progressSEXP);
    rcpp_result_gen = Rcpp::wrap(gwasForLoop(M, Y, Z, X, Vinv, minMAF, display_progress));
    return rcpp_result_gen;
END_RCPP
}
// MNR
Rcpp::List MNR(const arma::mat& Y, const Rcpp::List& X, const Rcpp::List& Gx, const Rcpp::List& Z, const Rcpp::List& K, const Rcpp::List& R, const Rcpp::List& Ge, const Rcpp::List& GeI, const arma::vec& ws, int iters, double tolpar, double tolparinv, const bool& ai, const bool& pev, const bool& verbose, const bool& retscaled, const arma::vec& stepweight, const arma::vec& emupdate);
RcppExport SEXP _sommer_MNR(SEXP YSEXP, SEXP XSEXP, SEXP GxSEXP, SEXP ZSEXP, SEXP KSEXP, SEXP RSEXP, SEXP GeSEXP, SEXP GeISEXP, SEXP wsSEXP, SEXP itersSEXP, SEXP tolparSEXP, SEXP tolparinvSEXP, SEXP aiSEXP, SEXP pevSEXP, SEXP verboseSEXP, SEXP retscaledSEXP, SEXP stepweightSEXP, SEXP emupdateSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type Gx(GxSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type K(KSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type R(RSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type Ge(GeSEXP);
    Rcpp::traits::input_parameter< const Rcpp::List& >::type GeI(GeISEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type ws(wsSEXP);
    Rcpp::traits::input_parameter< int >::type iters(itersSEXP);
    Rcpp::traits::input_parameter< double >::type tolpar(tolparSEXP);
    Rcpp::traits::input_parameter< double >::type tolparinv(tolparinvSEXP);
    Rcpp::traits::input_parameter< const bool& >::type ai(aiSEXP);
    Rcpp::traits::input_parameter< const bool& >::type pev(pevSEXP);
    Rcpp::traits::input_parameter< const bool& >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< const bool& >::type retscaled(retscaledSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type stepweight(stepweightSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type emupdate(emupdateSEXP);
    rcpp_result_gen = Rcpp::wrap(MNR(Y, X, Gx, Z, K, R, Ge, GeI, ws, iters, tolpar, tolparinv, ai, pev, verbose, retscaled, stepweight, emupdate));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_sommer_currentDateTime", (DL_FUNC) &_sommer_currentDateTime, 0},
    {"_sommer_seqCpp", (DL_FUNC) &_sommer_seqCpp, 2},
    {"_sommer_mat_to_vecCpp", (DL_FUNC) &_sommer_mat_to_vecCpp, 2},
    {"_sommer_vec_to_cubeCpp", (DL_FUNC) &_sommer_vec_to_cubeCpp, 2},
    {"_sommer_varCols", (DL_FUNC) &_sommer_varCols, 1},
    {"_sommer_scaleCpp", (DL_FUNC) &_sommer_scaleCpp, 1},
    {"_sommer_makeFull", (DL_FUNC) &_sommer_makeFull, 1},
    {"_sommer_isIdentity_mat", (DL_FUNC) &_sommer_isIdentity_mat, 1},
    {"_sommer_isIdentity_spmat", (DL_FUNC) &_sommer_isIdentity_spmat, 1},
    {"_sommer_isDiagonal_mat", (DL_FUNC) &_sommer_isDiagonal_mat, 1},
    {"_sommer_isDiagonal_spmat", (DL_FUNC) &_sommer_isDiagonal_spmat, 1},
    {"_sommer_amat", (DL_FUNC) &_sommer_amat, 3},
    {"_sommer_dmat", (DL_FUNC) &_sommer_dmat, 3},
    {"_sommer_emat", (DL_FUNC) &_sommer_emat, 2},
    {"_sommer_hmat", (DL_FUNC) &_sommer_hmat, 6},
    {"_sommer_scorecalc", (DL_FUNC) &_sommer_scorecalc, 7},
    {"_sommer_gwasForLoop", (DL_FUNC) &_sommer_gwasForLoop, 7},
    {"_sommer_MNR", (DL_FUNC) &_sommer_MNR, 18},
    {NULL, NULL, 0}
};

RcppExport void R_init_sommer(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
