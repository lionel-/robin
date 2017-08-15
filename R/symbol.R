#' Symbol table
#'
#' This returns the hash buckets of R's symbol table.
#'
#' @return A list of 4019 elements. Each element is a pairlist of
#'   symbols.
#' @export
sym_table <- function() {
  .Call(robin_sym_table)
}

#' @export
sym_unbound <- function() {
  .Call(robin_sym_unbound)
}

#' @export
is_missing_sym <- function(x) {
  .Call(robin_is_missing, x)
}
