#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <stdbool.h>


extern SEXP prim_invoke(SEXP, SEXP, SEXP, SEXP);
extern SEXP prim_ptr_invoke(SEXP, SEXP, SEXP, SEXP);
extern SEXP robin_intl(SEXP);
extern SEXP robin_prim_offset(SEXP);
extern SEXP robin_prim_ptr(SEXP);
extern SEXP sym_table();

static const R_CallMethodDef call_entries[] = {
  {"robin_intl",            (DL_FUNC) &robin_intl, 1},
  {"robin_prim_invoke",     (DL_FUNC) &prim_invoke, 4},
  {"robin_prim_ptr_invoke", (DL_FUNC) &prim_ptr_invoke, 4},
  {"robin_prim_offset",     (DL_FUNC) &robin_prim_offset, 1},
  {"robin_prim_ptr",        (DL_FUNC) &robin_prim_ptr, 1},
  {"robin_sym_table",       (DL_FUNC) &sym_table, 0},
  {NULL, NULL, 0}
};


void R_init_robin(DllInfo* dll) {
  R_registerRoutines(dll, NULL, call_entries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
