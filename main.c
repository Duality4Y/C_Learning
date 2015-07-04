#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB "\t"
int read = 0;

void Expression();
void SkipWhite();

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
        Other();
    }
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

int main(void)
{
    Init();
    DoProgram();
    return 0;
}