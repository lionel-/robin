#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <stdbool.h>

extern SEXP robin_symbol_table();

static const R_CallMethodDef call_entries[] = {
  {"robin_symbol_table", (DL_FUNC) &robin_symbol_table, 0},
  {NULL, NULL, 0}
};


void R_init_robin(DllInfo* dll) {
  R_registerRoutines(dll, NULL, call_entries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
