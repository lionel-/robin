#define R_NO_REMAP
#include <Rinternals.h>

#define HSIZE 4119
extern SEXP* R_SymbolTable;

SEXP robin_symbol_table() {
  static SEXP table = NULL;
  if (!table) {
    table = Rf_allocVector(VECSXP, HSIZE);
    R_PreserveObject(table);

    for (int i = 0; i != HSIZE; ++i)
      SET_VECTOR_ELT(table, i, R_SymbolTable[i]);
  }

  return table;
}
