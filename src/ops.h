#ifndef OPS_H
#define OPS_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

enum {ASSOC_NONE=0, ASSOC_LEFT, ASSOC_RIGHT};

typedef struct op_t
{
    char op;
    int perc;
    int assoc;
    int unary;
    int (*eval)(int a1, int a2);
} op_t;

op_t *getop(char);

int eval_uminus(int, int);
int eval_exp(int, int);
int eval_mul(int, int);
int eval_div(int, int);
int eval_mod(int, int);
int eval_add(int, int);
int eval_sub(int, int);

#endif