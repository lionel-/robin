#include "pointer.h"

SEXP function_ptr(DL_FUNC fn) {
  SEXP ptr = PROTECT(R_MakeExternalPtrFn(fn, R_NilValue, R_NilValue));

  SEXP ptr_obj = PROTECT(Rf_allocVector(VECSXP, 1));
  SET_VECTOR_ELT(ptr_obj, 0, ptr);

  Rf_setAttrib(ptr_obj, R_ClassSymbol, Rf_mkString("fn_pointer"));

  UNPROTECT(2);
  return ptr_obj;
}
