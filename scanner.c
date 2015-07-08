#include "scanner.h"

static FILE *src;

void scanner_init(char *source)
{
    src = fopen(source, "r");
}

scanned_t 
scanner()
{
    // line number pos on line, read data.
    static int ln;
    static int pos;
    static int read;
    scanned_t scanned;
    // reading logic.
    read = fgetc(src);
    if(read == EOF)
    {
        fclose(src);
        ln = 0;
        pos = 0;
        read = 0;
        scanned.done = 1;
        return scanned;
    }
    
    if(read == '\n')
    {
        pos = 0;
        ln++;
    }
    
    scanned.data = read;
    scanned.line = ln;
    scanned.pos = pos;
    scanned.done = 0;
    
    pos++;

    return scanned;
}