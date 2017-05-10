#' Symbol table
#'
#' This returns the hash buckets of R's symbol table.
#'
#' @export
sym_table <- function() {
  .Call(robin_symbol_table)
}
