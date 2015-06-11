#include "stack.h"

node_t *createNode()
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if(newNode == NULL)
    {
        abort();
    }
    newNode->next = NULL;
    return newNode;
}