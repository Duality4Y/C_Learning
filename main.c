#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "scanner.h"

#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))

const char *keywords[] = 
{
    "if",
    "then",
    "else",
    "elif",
    "endif",
    "while",
    "loop",
    "endloop",
    "print",
    "return",
    "exit",
};

// one character symbols
const char onecharsyms[] = 
{
    '=',
    '(',
    ')',
    '<',
    '>',
    '/',
    '*',
    '+',
    '-',
    '!',
    '&',
    '.',
    ';'
};

// to character symbols.
const char *twocharsyms[] =
{
    "==",
    "<=",
    ">=",
    "<>",
    "!=",
    "++",
    "**",
    "--",
    "+=",
    "-=",
    "||",
    "&&"
};

const char STRING_STARTCHARS[] = {'\'', '"'};
const char WHITESPACE_CHARS[] = {" \t\n"};

const char *STRING = "String";
const char *IDENTIFIER = "Identifier";
const char *NUMBER = "Number";
const char *WHITESPACE = "WhiteSpace";
const char *COMMENT = "Comment";
const char *Eof = "EOF";

typedef struct {
    char srp[50];
    int type;
    unsigned int pos[1][1];
} token_t;

token_t
lexer()
{
    static scanned_t scanned;
    token_t token;
    scanned1 = scanner();
    char read1 = scanned1.data;

    return token;
}

void scannerTest()
{
    // open a file for scanning
    scanner_init("test.lan");
    scanned_t scan = scanner();
    printf("line    column    data \n");
    while(!scan.done)
    {
        printf("%4d, %8d, %4c\n", scan.line, scan.pos, scan.data);
        scan = scanner();
    }
}

int main(void)
{
    // initialize scanner.
    scanner_init("test.lan");
    lexer();
    return 0;
}
