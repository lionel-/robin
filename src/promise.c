#define R_NO_REMAP
#include <Rinternals.h>


SEXP robin_promise(SEXP env) {
  return Rf_findVar(Rf_install("expr"), env);
}

SEXP robin_prom_expr(SEXP env) {
  SEXP prom_inner = Rf_findVar(Rf_install("prom"), env);
  SEXP prom = Rf_findVar(PREXPR(prom_inner), PRENV(prom_inner));
  return PREXPR(prom);
}
SEXP robin_prom_env(SEXP env) {
  SEXP prom_inner = Rf_findVar(Rf_install("prom"), env);
  SEXP prom = Rf_findVar(PREXPR(prom_inner), PRENV(prom_inner));
  return PRENV(prom);
}

SEXP robin_lang_prom(SEXP env) {
  SEXP prom = robin_promise(env);
  SEXP args = PROTECT(Rf_list1(prom));
  SEXP lang = PROTECT(Rf_lcons(Rf_install("identity"), args));
  UNPROTECT(2);
  return lang;
}
