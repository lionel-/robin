#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <stdbool.h>

extern SEXP robin_prim_offset(SEXP);
extern SEXP sym_table();

static const R_CallMethodDef call_entries[] = {
  {"robin_prim_offset", (DL_FUNC) &robin_prim_offset, 1},
  {"robin_sym_table",   (DL_FUNC) &sym_table, 0},
  {NULL, NULL, 0}
};


void R_init_robin(DllInfo* dll) {
  R_registerRoutines(dll, NULL, call_entries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
