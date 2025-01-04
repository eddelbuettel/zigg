
#include <zigg>
#include <tidy/globals.h>       // instead of header tidyCpp itself we include a subset directly
#include <tidy/defines.h>
#include <tidy/internals.h>
#include <tidy/numvec.h>
#include <tidy/protect.h>

typedef SEXP sexp;

static zigg::Ziggurat ziggurat; 					// static instance ensures initialization

extern "C" {

sexp zrnorm(sexp ns) {
    int n = R::asInteger(ns);
    R::Protect v = R::allocVectorNumeric(n);
    for (int i = 0; i < n; i++)
        R::numericPointer(v)[i] = ziggurat.rnorm();
    return v;
}

sexp zrexp(sexp ns) {
    int n = R::asInteger(ns);
    R::Protect v = R::allocVectorNumeric(n);
    for (int i = 0; i < n; i++)
        R::numericPointer(v)[i] = ziggurat.rexp();
    return v;
}

sexp zrunif(sexp ns) {
    int n = R::asInteger(ns);
    R::Protect v = R::allocVectorNumeric(n);
    for (int i = 0; i < n; i++)
        R::numericPointer(v)[i] = ziggurat.runi();
    return v;
}

sexp zsetseed(sexp ss) {
    double sd = R::asNumeric(ss);
    uint32_t su = static_cast<uint32_t>(sd);
    ziggurat.setSeed(su);
    return R_NilValue;
}

// sexp zgetseed(sexp ss) {
//     uint32_t su = ziggurat.getSeed();
//     double sd = static_cast<double>(su);
//     return R::scalarReal(sd);
// }

}
