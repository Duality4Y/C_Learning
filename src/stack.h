#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct node_t
{
    uint32_t integer;
    char character;
    char name[50];
    struct node_t *next;
};

typedef struct node_t node_t;

node_t *createNode();
void deleteNode();

void push(node_t *);
node_t *pop();

#endif