
#include <R.h>
#include <Rinternals.h>         /* for SEXP */
#include <R_ext/Rdynload.h>

SEXP zrnorm(SEXP ns);
SEXP zrexp(SEXP ns);
SEXP zrunif(SEXP ns);
SEXP zsetseed(SEXP ns);

static const R_CallMethodDef CallEntries[] = {
    {"zrnorm",   (DL_FUNC) &zrnorm,   1},
    {"zrexp",    (DL_FUNC) &zrexp,    1},
    {"zrunif",   (DL_FUNC) &zrunif,   1},
    {"zsetseed", (DL_FUNC) &zsetseed, 1},
    {NULL, NULL, 0}
};

void R_init_zigg(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
