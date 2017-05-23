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

#' Function pointer of primitive function
#'
#' @inheritParams prim_offset
#' @return A list containing a pointer object to the C implementation
#'   of the primitive function.
#' @export
#' @examples
#' prim_ptr(base::c)
#' prim_ptr(base::list)
prim_ptr <- function(prim) {
  .Call(robin_prim_ptr, prim)
}
