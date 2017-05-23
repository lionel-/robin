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
  return prim_function_ptr(prim, (DL_FUNC) c_ptr);
}

// The primitive objects are stored in the tag field of symbols

SEXP robin_intl(SEXP sym) {
  if (TYPEOF(sym) != SYMSXP) {
    Rf_errorcall(R_NilValue, "`intl` must be a symbol");
  }

  SEXP intl = INTERNAL(sym);
  check_primitive(intl);
  return intl;
}
SEXP intl(const char* nm) {
  SEXP sym = Rf_install(nm);
  return robin_intl(sym);
}


static CCODE prim_holder = NULL;

SEXP prim_invoke(SEXP prim, SEXP call, SEXP args, SEXP rho) {
  check_primitive(prim);
  prim_holder = prim_ptr(prim);

  // The `op` parameter is the primitive object itself
  return prim_holder(call, prim, args, rho);
}
SEXP prim_ptr_invoke(SEXP ptr, SEXP call, SEXP args, SEXP rho) {
  if (!Rf_inherits(ptr, "prim_pointer"))
    Rf_errorcall(R_NilValue, "`ptr` must be a primitive function pointer");

  prim_holder = (CCODE) R_ExternalPtrAddrFn(VECTOR_ELT(ptr, 0));

  SEXP prim = VECTOR_ELT(ptr, 1);
  return prim_holder(call, prim, args, rho);
}
