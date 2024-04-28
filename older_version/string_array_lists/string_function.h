// String Function Algorithm
// String Assign 
// String Length
// String Compare
// String Concatenation
// String Substring
// String Clear

#ifndef _STRING_FUNCTION_H_
#define _STRING_FUNCTION_H_

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
int strAssign(Str& str, const char* ch);
int strLength(const Str& str);
int strCompare(const Str& str_1, const Str& str_2);
int strConcat(Str& str, const Str& str_1, const Str& str_2);
int getSubstring(Str& substr, const Str& str, const int& pos, const int& len);
int clearString(Str& str);
/*
 * TODO : 
 * 1. the index_BF()    // 简单模式串匹配算法
 * 2. the index_KMP()   // KMP算法
 */
int index_BF(const Str& str_1, const Str& str_2, int pos);

#endif // _STRING_FUNCTION_H_