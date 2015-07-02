#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int peek()
{
    int data = fgetc(stdin);
    ungetc(data, stdin);
    return data;
}

#define TAB "\t"
int read = 0;

void Expression();

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
        sprintf(message, "''%c''", mc);
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

bool IsAddop(char c)
{
    return(c == '+' || c == '-');
}

char GetName()
{
    if(!IsAlpha(read))
    {
        Expected("Name");
    }
    // store previous value before getting a new one.
    char data  = read;
    GetChar();
    return toupper(data);
}

char GetNum()
{
    if(!IsDigit(read))
    {
        Expected("Integer");
    }
    // store previous value before getting a new one.
    // and get the actual value.
    char data = read-'0';
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

void Ident()
{
    char name;
    name = GetName();
    if(read == '(')
    {
        Match('(');
        Match(')');
        char message[50];
        sprintf(message, "BSR %c", name);
        EmitLn(message);
    }
    else
    {
        char message[50];
        sprintf(message, "MOVE %c(PC), D0", GetName());
        EmitLn(message);
    }
}

void Factor()
{
    if(read == '(')
    {
        Match('(');
        Expression();
        Match(')');
    }
    else if(IsAlpha(read))
    {
        Ident();
    }
    else
    {
        char message[50];
        sprintf(message, "MOVE #%d, D0", GetNum());
        EmitLn(message);
    }
}

void Multiply()
{
    Match('*');
    Factor();
    EmitLn("MULS (SP)+, D0");
}

void Divide()
{
    Match('/');
    Factor();
    EmitLn("MOVE (SP)+, D1");
    EmitLn("DIVS D1, D0");
}

void Term()
{
    Factor();
    while(read == '*' || read == '/')
    {
        EmitLn("MOVE D0, -(SP)");
        switch(read)
        {
            case '*':
                Multiply();
                break;
            case '/':
                Divide();
                break;
            default:
                Expected("* or / operator.");
                break;
        }
    }
}

void Add()
{
    Match('+');
    Term();
    EmitLn("ADD +(SP), D0");
}

void Subtract()
{
    Match('-');
    Term();
    EmitLn("SUB +(SP), D0");
    EmitLn("NEG D0");
}

void Expression()
{
    if(IsAddop(read))
    {
        EmitLn("CLR D0");
    }
    else
    {
        Term();
    }
    while(read == '+' || read == '-')
    {
        EmitLn("MOVE D0, -(SP)");
        switch(read)
        {
            case '+':
                Add();
                break;
            case '-':
                Subtract();
                break;
            default:
                Expected("Operator");
                break;
        }
    }
}

void Assignment()
{
    char name;
    name = GetName();
    Match('=');
    Expression();
    char message[50];
    sprintf(message, "LEA %c (PC), A0", name);
    EmitLn(message);
    EmitLn("MOVE D0, (A0)");
}

int main(void)
{
    Init();
    Assignment();
    if(read != '\n')
    {
        Expected("Newline");
    }
    // while(peek() != EOF)
    // {
    // }
    return 0;
}