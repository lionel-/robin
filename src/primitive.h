#ifndef ROBIN_PRIMITIVE_H
#define ROBIN_PRIMITIVE_H

#define R_NO_REMAP
#include <Rinternals.h>

// Taken from R 3.4.0 codebase


/* Information for Deparsing Expressions */
typedef enum {
    PP_INVALID  =  0,
    PP_ASSIGN   =  1,
    PP_ASSIGN2  =  2,
    PP_BINARY   =  3,
    PP_BINARY2  =  4,
    PP_BREAK    =  5,
    PP_CURLY    =  6,
    PP_FOR      =  7,
    PP_FUNCALL  =  8,
    PP_FUNCTION =  9,
    PP_IF       = 10,
    PP_NEXT     = 11,
    PP_PAREN    = 12,
    PP_RETURN   = 13,
    PP_SUBASS   = 14,
    PP_SUBSET   = 15,
    PP_WHILE    = 16,
    PP_UNARY    = 17,
    PP_DOLLAR   = 18,
    PP_FOREIGN  = 19,
    PP_REPEAT   = 20
} PPkind;

typedef enum {
    PREC_FN      = 0,
    PREC_EQ      = 1,
    PREC_LEFT    = 2,
    PREC_RIGHT   = 3,
    PREC_TILDE   = 4,
    PREC_OR      = 5,
    PREC_AND     = 6,
    PREC_NOT     = 7,
    PREC_COMPARE = 8,
    PREC_SUM     = 9,
    PREC_PROD    = 10,
    PREC_PERCENT = 11,
    PREC_COLON   = 12,
    PREC_SIGN    = 13,
    PREC_POWER   = 14,
    PREC_SUBSET  = 15,
    PREC_DOLLAR  = 16,
    PREC_NS      = 17
} PPprec;

typedef struct {
  PPkind kind;             /* deparse kind */
  PPprec precedence;       /* operator precedence */
  unsigned int rightassoc; /* right associative? */
} PPinfo;


typedef SEXP (*CCODE)(SEXP, SEXP, SEXP, SEXP);

typedef struct {
    char   *name;    /* print name */
    CCODE  cfun;     /* c-code address */
    int	   code;     /* offset within c-code */
    int	   eval;     /* evaluate args? */
    int	   arity;    /* function arity */
    PPinfo gram;     /* pretty-print info */
} FUNTAB;


extern FUNTAB R_FunTab[];


#endif
