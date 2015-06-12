#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

struct node_t
{
    long integer;
    char character;
    
    char name[50];

    int type;
    short precedence;
    short assoc;
    
    struct node_t *next;
};

typedef struct node_t node_t;

static node_t *stack = NULL;

node_t *createNode();
void deleteNode(node_t**);
void deleteStack();

void push(node_t *);
node_t *pop();

node_t *getStack();

#endif