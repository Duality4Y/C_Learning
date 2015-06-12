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
    *node = NULL;
}

void deleteStack()
{
    node_t *head = stack;
    node_t *prev = NULL;
    while(head != NULL)
    {
        prev = head;
        head = head->next;
        deleteNode(&prev);
    }
    deleteNode(&head);
    deleteNode(&stack);
}

void push(node_t *node)
{
    if(stack==NULL)
    {
        stack = node;
    }
    else
    {
        node_t *head = stack;
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = node;
    }
}

node_t *pop(void)
{
    if(stack == NULL)
    {
        printf("stack underflow\n");
        return NULL;
    }
    else if(stack->next == NULL)
    {
        // hold the stack reference.
        node_t *retnode = stack;
        // set the stack to null (empty)
        stack = NULL;
        // return the last node.
        return retnode;
    }
    else
    {
        // this one is tricky
        node_t *node = NULL;
        node_t *head = stack;
        // we traverse the list be stop one before last
        while(head->next->next != NULL)
        {
          head = head->next;
        }
        // we store the last one.
        node = head->next;
        // remove the link to it
        head->next = NULL;
        // and return the stored link
        // to be used in another node.
        return node;
    }
}

node_t *getStack(void)
{
    return stack;
}