#' Primitive object
#'
#' This just grabs a primitive object (type BUILTINSXP or SPECIALSXP)
#' from the base environment.
#'
#' @param nm The name of an exported primitive as a string or symbol.
#' @export
prim <- function(nm) {
  if (is_primitive(nm)) {
    return(nm)
  }

  if (is_symbol(nm)) {
    nm <- as_string(nm)
  } else if (!is_string(nm)) {
    abort("`nm` must be a string or a symbol")
  }

  prim <- env_get(base_env(), nm)
  if (!is_primitive(prim)) {
    abort("`nm` does not refer to an exported primitive")
  }

  prim
}
#' Primitive object of internal function
#'
#' You normally don't see internal primitives in the wild as they stay
#' hidden in the bushes and only go out at night. `intl()` grabs them
#' for you.
#'
#' @param nm The name of the internal function, as a string or symbol.
#' @return A primitive object.
#' @export
#' @examples
#' intl("eval")
#' prim_ptr(intl("eval"))
intl <- function(nm) {
  if (is_string(nm)) {
    nm <- sym(nm)
  }
  .Call(robin_intl, nm)
}

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
  .Call(robin_prim_offset, robin::prim(prim))
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
  .Call(robin_prim_ptr, robin::prim(prim))
}

#' Invoke a primitive function
#'
#' @inheritParams prim_offset
#' @param ptr A pointer object to a primitive function.
#' @param call The quoted call that the primitive will think it was
#'   invoked with.
#' @param args A pairlist of arguments.
#' @param rho The environment that the primitive will think it was
#'   invoked in.
#' @export
#' @examples
#' prim_invoke(list, NULL, pairlist(1, "a"))
prim_invoke <- function(prim, call, args = NULL, rho = caller_env()) {
  stopifnot(is_pairlist(args))
  stopifnot(is_env(rho))
  .Call(robin_prim_invoke, robin::prim(prim), call, args, rho)
}
#' @rdname prim_invoke
#' @export
prim_ptr_invoke <- function(ptr, call, args = NULL, rho = caller_env()) {
  stopifnot(is_pairlist(args))
  stopifnot(is_env(rho))
  .Call(robin_prim_ptr_invoke, ptr, call, args, rho)
}
