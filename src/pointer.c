#include "pointer.h"

SEXP function_ptr(DL_FUNC fn) {
  SEXP ptr = PROTECT(R_MakeExternalPtrFn(fn, R_NilValue, R_NilValue));

  SEXP ptr_obj = PROTECT(Rf_allocVector(VECSXP, 1));
  SET_VECTOR_ELT(ptr_obj, 0, ptr);

  Rf_setAttrib(ptr_obj, R_ClassSymbol, Rf_mkString("fn_pointer"));

  UNPROTECT(2);
  return ptr_obj;
}

SEXP prim_function_ptr(SEXP prim, DL_FUNC fn) {
  SEXP ptr = PROTECT(R_MakeExternalPtrFn(fn, R_NilValue, R_NilValue));

  SEXP ptr_obj = PROTECT(Rf_allocVector(VECSXP, 2));
  SET_VECTOR_ELT(ptr_obj, 0, ptr);
  SET_VECTOR_ELT(ptr_obj, 1, prim);

  SEXP ptr_nms = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_STRING_ELT(ptr_nms, 0, Rf_mkChar("ptr"));
  SET_STRING_ELT(ptr_nms, 1, Rf_mkChar("prim"));

  SEXP ptr_class = PROTECT(Rf_allocVector(STRSXP, 2));
  SET_STRING_ELT(ptr_class, 0, Rf_mkChar("prim_pointer"));
  SET_STRING_ELT(ptr_class, 1, Rf_mkChar("fn_pointer"));

  Rf_setAttrib(ptr_obj, R_NamesSymbol, ptr_nms);
  Rf_setAttrib(ptr_obj, R_ClassSymbol, ptr_class);

  UNPROTECT(4);
  return ptr_obj;
}
