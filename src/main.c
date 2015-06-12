#include <stdio.h>
#include "stack.h"
#include "types.h"
#include "stacktesting.h"

#define INPUTSIZE 200
char input[INPUTSIZE];

int readPrompt(char *buffer, int size)
{
    int index = 0;
    printf(">> ");
    char read = getchar();
    while(read != '\n')
    {
        if(read == EOF)
            break;
        else
        {
            if(index == size)
                return -1;
            else
            {
                buffer[index++] = (char)read;
                buffer[index] = '\0';
            }
        }
        read = getchar();
    }
    return index;
}

node_t *tokenize()
{
    return NULL;
}

int main(void)
{
    // stackTesting();
    int newinput = readPrompt(input, INPUTSIZE);
    if(newinput > 0)
    {
        //node_t *tokens = tokenize(input, newinput);
    }
    else if(newinput == -1)
    {
        printf("to much input.\n");
    }
	return 0;
}