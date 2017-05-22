#define R_NO_REMAP
#include <Rinternals.h>
#include <stdbool.h>


bool is_primitive(SEXP x) {
  return TYPEOF(x) == BUILTINSXP || TYPEOF(x) == SPECIALSXP;
}

SEXP prim(const char* prim_nm) {
  SEXP prim = Rf_findVar(Rf_install(prim_nm), R_BaseEnv);

  if (!is_primitive(prim))
    Rf_errorcall(R_NilValue, "`prim` must be a primitive function");

  return prim;
}

int prim_offset(SEXP prim) {
  if (!is_primitive(prim))
    Rf_errorcall(R_NilValue, "`prim` must be a primitive function");

  return (int) CAR(prim);
}

SEXP robin_prim_offset(SEXP prim) {
  int offset = prim_offset(prim);
  return Rf_ScalarInteger(offset);
}
