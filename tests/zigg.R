
library(zigg)

N <- 1e5
zsetseed(12345)

rn <- zrnorm(N)
summary(rn)

re <- zrexp(N)
summary(re)

ru <- zrunif(N)
summary(ru)

zsetseed(12345)
all.equal(rn, zrnorm(N))
all.equal(re, zrexp(N))
all.equal(ru, zrunif(N))
