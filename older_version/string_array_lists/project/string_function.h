//
// Created by whx on 22-12-2.
//

#ifndef CLION_STRING_FUNCTION_H
#define CLION_STRING_FUNCTION_H

#include <iostream>
using namespace std;

#define MAXSIZE 10000
// 定长存储结构
typedef struct {
    char str[MAXSIZE + 1];  // +1 : '\0'
    int length;
} Str_certain;

// 变长存储结构 : 常用
typedef struct {
    char* ch;
    int length;
} Str;

void strInit(Str& str);
void strPrint(const Str& str);
int strAssign(Str& str, char* ch);
int strLength(const Str& str);
int strCompare(const Str& str_1, const Str& str_2);
int strConcat(Str& str, const Str& str_1, const Str& str_2);
int getSubstring(Str& substr, const Str& str, int pos, int len);
int clearString(Str& str);

#endif //CLION_STRING_FUNCTION_H
