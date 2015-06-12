#include "stack.h"

node_t *createNode()
{
    node_t *newNode = (node_t *)calloc(1, sizeof(node_t));
    if(newNode == NULL)
    {
        abort();
    }
    newNode->next = NULL;
    return newNode;
}

void deleteNode(node_t **node)
{
    free(*node);
}

void push(node_t *node)
{
    node_t *head = stack;
    while(head->next != NULL)
    {
        head = stack->next
    }
    head->next = node;
}

node_t *getStack(void)
{
    return stack;
}