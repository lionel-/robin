
#' @export
promise <- function(expr) {
  .Call(robin_promise, get_env())
}

#' @export
prom_expr <- function(prom) {
  .Call(robin_prom_expr, get_env())
}
#' @export
prom_env <- function(prom) {
  .Call(robin_prom_env, get_env())
}
