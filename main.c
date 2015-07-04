#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAB "\t"
int read = 0;
int Lcount = 0;

char *str_malloc_refs[50];
// str malloc ptr index
int smpi = 0;

void Block();
void DoIf();

void GetChar()
{
    read = fgetc(stdin);
}

void Error(char *s)
{
    printf("\n Error: %s.\n", s);
}

void Abort(char *s)
{
    Error(s);
    exit(1);
}

void Expected(char *s)
{
    char message[50];
    sprintf(message, "%s Expected", s);
    Abort(message);
}

void Match(char mc)
{
    if(read == mc)
    {
        GetChar();
    }
    else
    {
        char message[50];
        sprintf(message, "%c", mc);
        Expected(message);
    }
}

bool IsAlpha(char c)
{
    return isalpha(c);
}

bool IsDigit(char c)
{
    return isdigit(c);
}

char GetName()
{
    if(!IsAlpha(read))
    {
        Expected("Name");
    }
    char data = toupper(read);
    GetChar();
    return data;
}

char GetNum()
{
    if(!IsDigit(read))
    {
        Expected("Integer");
    }
    char data = read;
    GetChar();
    return data;
}

void Emit(char *s)
{
    printf(TAB"%s", s);
}

void EmitLn(char *s)
{
    char message[50];
    sprintf(message, "%s\n", s);
    Emit(message);
}

char *NewLabel(void)
{
    char *string = (char *)malloc(sizeof(char)*4);
    sprintf(string, "L%d", Lcount);
    // increase label count.
    Lcount++;
    // keep reference for freeing later on.
    str_malloc_refs[smpi] = string;
    smpi++;
    return string;
}

void PostLabel(char *s)
{
    printf("%s:\n", s);
}

void Init()
{
    GetChar();
}

void Other()
{
    char message[50];
    sprintf(message, "%c", GetName());
    EmitLn(message);
}

void Block()
{
    while( read != 'e')
    {
        switch(read)
        {
            case 'i':
                DoIf();
                break;
            default:
                Other();
                break;
        }
    }
}

void Condition()
{
    EmitLn("<condition>");
}

void DoIf()
{
    char *label;
    Match('i');
    label = NewLabel();
    Condition();
    char message[50];
    sprintf(message, "BEQ %s", label);
    EmitLn(message);
    Block();
    Match('e');
    PostLabel(label);
}

void DoProgram()
{
    Block();
    if(read != 'e')
    {
        Expected("End");
    }
    EmitLn("END");
}

void free_strings()
{
    int i;
    for(i = 0;i < smpi;i++)
    {
        free(str_malloc_refs[i]);
        str_malloc_refs[i] = NULL;
    }
}

int main(void)
{
    Init();
    DoProgram();
    // free string created during the program.
    free_strings();
    return 0;
}