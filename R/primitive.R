#' Offset of primitive function
#'
#' This returns the offset of a primitive function in `R_FunTab`.
#'
#' @param prim A primitive function.
#' @export
#' @examples
#' prim_offset(base::c)
#' prim_offset(base::list)
prim_offset <- function(prim) {
  .Call(robin_prim_offset, prim)
}
