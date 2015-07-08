#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <stdbool.h>

/*
    structure holds scanned data.
    - what it read.
    - on which line it read the data.
    - position on the line where
    data was read.
    - status flag to show if end of file reached.
*/
typedef struct
{
    char data;
    int line;
    int pos;
    bool done;
} scanned_t;

void scanner_init(char *);
scanned_t scanner();

#endif