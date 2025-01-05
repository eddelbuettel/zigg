
#include <zigg>

#include <R.h>
#include <Rinternals.h>         					// for SEXP

typedef SEXP sexp;

static zigg::Ziggurat ziggurat; 					// static instance ensures initialization

extern "C" {

sexp zrnorm(sexp ns) {
    int n = Rf_asInteger(ns);
    SEXP v = PROTECT(Rf_allocVector(REALSXP, n));
    double* p = REAL(v);
    for (int i = 0; i < n; i++) {
        p[i] = ziggurat.rnorm();
    }
    UNPROTECT(1);
    return v;
}

sexp zrexp(sexp ns) {
    int n = Rf_asInteger(ns);
    SEXP v = PROTECT(Rf_allocVector(REALSXP, n));
    double* p = REAL(v);
    for (int i = 0; i < n; i++) {
        p[i] = ziggurat.rexp();
    }
    UNPROTECT(1);
    return v;
}

sexp zrunif(sexp ns) {
    int n = Rf_asInteger(ns);
    SEXP v = PROTECT(Rf_allocVector(REALSXP, n));
    double* p = REAL(v);
    for (int i = 0; i < n; i++) {
        p[i] = ziggurat.runi();
    }
    UNPROTECT(1);
    return v;
}

sexp zsetseed(sexp ss) {
    double sd = Rf_asReal(ss);
    uint32_t su = static_cast<uint32_t>(sd);
    ziggurat.setSeed(su);
    return R_NilValue;
}

}
