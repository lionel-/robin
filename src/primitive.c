#include <stdbool.h>

#include "pointer.h"
#include "primitive.h"


bool is_primitive(SEXP x) {
  return TYPEOF(x) == BUILTINSXP || TYPEOF(x) == SPECIALSXP;
}
void check_primitive(SEXP x) {
  if (!is_primitive(x))
    Rf_errorcall(R_NilValue, "`prim` must be a primitive function");
}

SEXP prim_sxp(const char* prim_nm) {
  SEXP prim = Rf_findVar(Rf_install(prim_nm), R_BaseEnv);
  check_primitive(prim);
  return prim;
}

int prim_offset(SEXP prim) {
  check_primitive(prim);
  return (int) CAR(prim);
}
SEXP robin_prim_offset(SEXP prim) {
  int offset = prim_offset(prim);
  return Rf_ScalarInteger(offset);
}

CCODE prim_ptr(SEXP prim) {
  check_primitive(prim);
  int offset = prim_offset(prim);
  return R_FunTab[offset].cfun;
}
SEXP robin_prim_ptr(SEXP prim) {
  CCODE c_ptr = prim_ptr(prim);
  return function_ptr((DL_FUNC) c_ptr);
}
