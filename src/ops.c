#include "ops.h"

op_t ops[] = 
{
    {'_', 10, ASSOC_RIGHT, 1, eval_uminus},
    {'^', 9, ASSOC_RIGHT, 0, eval_exp},
    {'*', 8, ASSOC_LEFT, 0, eval_mul},
    {'/', 8, ASSOC_LEFT, 0, eval_div},
    {'%', 8, ASSOC_LEFT, 0, eval_mod},
    {'+', 5, ASSOC_LEFT, 0, eval_add},
    {'-', 5, ASSOC_LEFT, 0, eval_sub},
    {'(', 0, ASSOC_NONE, 0, NULL},
    {')', 0, ASSOC_NONE, 0, NULL}
};

op_t *getop(char ch)
{
    int i;
    for(i = 0; i < sizeof(ops)/sizeof(ops[0]);++i)
    {
        if(ops[i].op == ch) return ops+i;
    }
    return NULL;
}

int eval_uminus(int a1, int a2)
{
    return -a1;
}

int eval_exp(int a1, int a2)
{
    return a2<0 ? 0 : (a2==0?1:a1*eval_exp(a1, a2-1));
}

int eval_mul(int a, int b)
{
    return a*b;
}

int eval_div(int a, int b)
{
    if(!b)
    {
        printf("Div by Zero error!\n");
        exit(1);
    }
    return a/b;
}

int eval_mod(int a, int b)
{
    if(!b)
    {
        printf("Div by Zero error!\n");
        exit(1);
    }
    return a%b;
}

int eval_add(int a, int b)
{
    return a+b;
}

int eval_sub(int a, int b)
{
    return a-b;
}
