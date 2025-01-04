#' @title Ziggurat Pseudo Random Number Generators
#'
#' @description Pseudo random numbers drawn from one of three
#' distributions are offered, as proposed by Marsaglia and Tsang
#' (2000, <doi:10.18637/jss.v005.i08>) and improved by Leong et al
#' (2005, <doi:10.18637/jss.v012.i07>.
#'
#' @param n The size of the returned vector
#' @param s The chose seed
#'
#' @return A vector of pseudo random-number generated draws from either the Normal,
#' Exponential or Uniform distribution, as selected
zrnorm <- function(n) {
    .Call(zrnorm_impl, n)
}

#' @rdname zrnorm
zrexp <- function(n) {
    .Call(zrexp_impl, n)
}

#' @rdname zrnorm
zrunif <- function(n) {
    .Call(zrunif_impl, n)
}

#' @rdname zrnorm
zsetseed <- function(s) {
    invisible(.Call(zsetseed_impl, s))
}

## # ' @rdname zrnorm
## zgetseed <- function() {
##     .Call(zgetseed_impl)
## }
