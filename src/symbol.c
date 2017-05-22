#define R_NO_REMAP
#include <Rinternals.h>

#define HSIZE 4119
extern SEXP* R_SymbolTable;

SEXP sym_table() {
  SEXP table = PROTECT(Rf_allocVector(VECSXP, HSIZE));

  for (int i = 0; i != HSIZE; ++i)
    SET_VECTOR_ELT(table, i, R_SymbolTable[i]);

  UNPROTECT(1);
  return table;
}
