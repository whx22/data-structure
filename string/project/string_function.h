//
// Created by whx on 23-3-3.
//

#ifndef PROJECT_STRING_FUNCTION_H
#define PROJECT_STRING_FUNCTION_H


#include <iostream>
#include <exception>
using namespace std;

// 定长存储结构
#define MAXSIZE 10000
typedef struct {
    char str[MAXSIZE + 1];
    int length;
} Str_certain;

// 变长存储结构
typedef struct {
    char* str;
    int length;
} Str;

/*
 * FunctionName : strInit()
 */
void strInit(Str& str);

/*
 * FunctionName : strPrint()
 */
void strPrint(Str& str);

/*
 * FunctionName : strAssign()
 * Description : Assign string
 * Parameter 1 : object (Str&)string
 * Parameter 2 : assign char*
 */
void strAssign(Str& str, const char* ch);

/*
 * FunctionName : strLength()
 * Description : return the length of string
 * Parameter : object string
 * Return : the length of object string
 */
int strLength(const Str& str);

/*
 * FunctionName : strCompare()
 * Description : compare two string character ASCII code and length
 * Parameter 1 : the first object string_1
 * Parameter 2 : the last object string_2
 * return : <0(s1 < s2) 0(s1 == s2) >0(s1 > s2)
 */
int strCompare(const Str& str_1, const Str& str_2);

/*
 * FunctionName : strConcat()
 * Description : Concatenation two string to new string
 * Parameter 1 : the result of concat string
 * Parameter 2 : the first string
 * Parameter 3 : the last string
 */
void strConcat(Str& str, const Str& str_1, const Str& str_2);

/*
 * FunctionName : getSubstring()
 * Description : return string's substring
 * Parameter 1 : the substring
 * Parameter 2 : the base string
 * Parameter 3 : the index of begin position
 * Parameter 4 : the length of substring
 */
void getSubstring(Str& substr, const Str& str, const int& pos, const int& len);

/*
 * FunctionName : clearString()
 * Description : clear object string
 */
void clearString(Str& str);

/*
 * FunctionName : index_BF()
 * Description : calculate the substring first appear in main string
 * Parameter 1 : the main string
 * Parameter 2 : the substring
 * Parameter 3 : the starting position of lookup (default parameter : 0)
 * Return : the position where the substring first appear
 * Algorithm time complexity : m * n (length of main string * length of substring)
 */
// 注意 : str & substr 均从[1]开始存储字符, [0]不存储字符
int BF(const Str& str, const Str& substr, int pos = 1);

/*
 * FunctionName : getNext()
 * Description : calculate the next array of substring
 * Called By : KMP()
 * Parameter 1 : the target substring
 * Parameter 2 : an array that holds the results
 */
// 注意 : next数组 从[1]开始存储, [0]不存储
void getNext(const Str& substr, int next[]);

/*
 * FunctionName : getNextval()
 * Description : calculate the nextval array(highly efficient than next array) of substring
 * Called By : KMP()
 * Parameter 1 : the target substring
 * Parameter 2 : an array that holds the results
 */
// 注意 : nextval数组 从[1]开始存储, [0]不存储
void getNextval(const Str& substr, int nextval[]);

/*
 * FunctionName : KMP()
 * Description : calculate the substring first appear in main string
 * Parameter 1 : the main string
 * Parameter 2 : the substring
 * Parameter 3 : the next array of substring
 * Return : the position where the substring first appear
 * Algorithm time complexity : m + n (length of main string + length of substring)
 */
// 注意 : str & substr 均从[1]开始存储字符, [0]不存储字符
int KMP(const Str& str, const Str& substr, int nextval[], int pos = 1);


#endif //PROJECT_STRING_FUNCTION_H
