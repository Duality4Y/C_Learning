#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct _node
{
    uint32_t integer;
    char character;
    char name[50];
    struct _node *next;
};

typedef struct _node node_t;

node_t *createNode();
void deleteNode();

void push(node_t *);
node_t *pop();

#endif