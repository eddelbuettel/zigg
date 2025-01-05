
#include <ziggAPI.h>

extern "C" {
    SEXP ziggrnorm_impl(SEXP ns) {
        return R::zrnorm(ns);
    }

    SEXP ziggsetseed_impl(SEXP ns) {
        return R::zsetseed(ns);
    }
}
