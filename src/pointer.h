#ifndef ROBIN_POINTER_H
#define ROBIN_POINTER_H

#define R_NO_REMAP
#include <Rinternals.h>
#include <Rversion.h>
#include <R_ext/Rdynload.h>


#if (defined(R_VERSION) && R_VERSION < R_Version(3, 4, 0))
typedef union {void* p; DL_FUNC fn;} fn_ptr;

SEXP R_MakeExternalPtrFn(DL_FUNC p, SEXP tag, SEXP prot) {
  fn_ptr ptr;
  ptr.fn = p;
  return R_MakeExternalPtr(ptr.p, tag, prot);
}
DL_FUNC R_ExternalPtrAddrFn(SEXP s) {
  fn_ptr ptr;
  ptr.p = EXTPTR_PTR(s);
  return ptr.fn;
}
#endif

SEXP function_ptr(DL_FUNC fn);
SEXP prim_function_ptr(SEXP prim, DL_FUNC fn);


#endif
