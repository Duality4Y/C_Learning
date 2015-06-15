#include <stdio.h>
#include <ctype.h>
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

node_t *tokenize(char *buffer, int length)
{
    int i;
    for(i = 0;i < length;i++)
    {
        char data = buffer[i];
        if(isdigit(data))
        {
            node_t *num = createNode();
            char numbuff[21];
            int number = 0;
            int numi = 0;
            while(isdigit(data))
            {

            }
        }
    }
    return NULL;
}

int main(void)
{
    // stackTesting();
    // int newinput = readPrompt(input, INPUTSIZE);
    int newinput = 0;
    if(newinput > 0)
    {
        node_t *tokens = tokenize(input, newinput);
    }
    else if(newinput == -1)
    {
        printf("to much input.\n");
    }
	return 0;
}