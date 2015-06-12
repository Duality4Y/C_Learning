#ifndef TYPES_H
#define TYPES_H

#include "ops.h"

enum {CHAR, INT, OP, FUNC};

typedef struct node_t
{
    long integer;
    char character;
    char name[50];
    int type;
    struct op_t *operator;
    struct node_t *next;
} node_t;

#endif