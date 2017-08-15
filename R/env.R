#' Mirror an environment
#'
#' A mirror is an environment that shares the same objects but not the
#' same parent. It is an efficient way of cloning an environment when
#' the purpose of the cloning is to have a different parent.
#'
#' @param env An environment to clone.
#' @param parent The parent of the new mirror environment.
#' @export
#' @examples
#' env <- env()
#' mirror <- env_mirror(env)
#'
#' # A mirror is like a shallow clone. The contents of the mirror are
#' # shared with the original environment:
#' mirror$a <- "foo"
#' env$a
#'
#' # On the other hand, the mirror can have a different parent:
#' parent.env(mirror) <- base_env()
#' parent.env(mirror)
#' parent.env(env)
env_mirror <- function(env, parent = env_parent(env)) {
  .Call(r_env_mirror, get_env(env), parent)
}
