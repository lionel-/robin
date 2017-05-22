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
