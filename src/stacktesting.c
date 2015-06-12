#include "stacktesting.h"

void popItems(int amount)
{
    int i;
    for(i = 0; i < amount; i++)
    {
        node_t *item = pop();
        // pop return NULL if stack empty
        if(item != NULL)
        {
            printf("item->integer: %ld\n", item->integer);
            deleteNode(&item);
        }
    }
}

void printStack()
{
    node_t *head = NULL;
    for(head = getStack();head != NULL;head = head->next)
    {
        printf("%ld ", head->integer);
    }
}

void createStack(int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        node_t *node = createNode();
        node->integer = i;
        push(node);
    }
}

void stackDelete()
{
    deleteStack();
}

void stackTesting()
{
    // creating a stack
    printf("\ncreating a stack 10 long.\n");
    createStack(10);

    printf("items in stack: [");
    printStack();
    printf("]\n");

    printf("poping 3 items and printing.\n");
    popItems(3);

    printf("items in stack: [");
    printStack();
    printf("]\n");

    printf("pop more then available: \n");
    popItems(10);

    printf("create a stack and delete it. \n");
    printf("creating.\n");
    createStack(100);
    printf("stack: [");
    printStack();
    printf("]\n");
    printf("deleting stack.\n");
    stackDelete();
    printf("printing stack: [");
    printStack();
    printf("]\n");
    printf("stack deleted?: %s \n", getStack()==NULL ? "true" : "false");
}