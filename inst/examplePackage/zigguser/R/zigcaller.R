
ziggrnorm <- function(n) {
    .Call(ziggrnorm_impl, n)
}

ziggsetseed <- function(n) {
    invisible(.Call(ziggsetseed_impl, n))
}
