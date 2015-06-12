#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>
#include "types.h"

node_t *stack;

node_t *createNode();
void deleteNode(node_t**);
void deleteStack();

void push(node_t *);
node_t *pop();

node_t *getStack();

#endif