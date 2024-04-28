#ifndef _SString_H
#define _SString_H


#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 255
typedef struct {
    char ch[MAXSIZE + 1];
    int length;
} SString;


#endif