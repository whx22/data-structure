//
// Created by whx on 22-12-2.
//

#include "string_function.h"

/*
 * FunctionName : strInit()
 */
void strInit(Str& str) {
    str.ch = new char('\0');
    str.length = 0;
}

/*
 * FunctionName : strPrint()
 */
void strPrint(const Str& str) {
    for (int i = 0; i < str.length; ++i) {
        cout << str.ch[i];
    }
    cout << endl;
}

/*
 * FunctionName : strAssign()
 * Description : Assign string
 * Parameter 1 : object (Str&)string
 * Parameter 2 : assign char*
 * return : the assign operate result
 */
int strAssign(Str& str, char* ch) {
    if (str.ch != nullptr) {
        delete[] str.ch;
        str.ch = nullptr;
    }
    int len = 0;
    char *c = ch;
    while (*c != '\0') {
        ++len;
        ++c;
    }
    if (len == 0) {
        str.ch = nullptr;
        str.length = 0;
        return EXIT_SUCCESS;
    }
    else {
        str.ch = new char[len + 1];
        if (str.ch == nullptr) {
            cerr << "error : Storage space allocation failed" << endl;
            return EXIT_FAILURE;
        }
        else {
            c = ch;
            for (int i = 0; i <= len; ++i, ++c) {
                str.ch[i] = *c;
            }
            str.length = len;
            return EXIT_SUCCESS;
        }
    }
}

/*
 * FunctionName : strLength()
 * Description : return the length of string
 * Parameter : object string
 * Return : the length of object string
 */
int strLength(const Str& str) {
    return str.length;
}

/*
 * FunctionName : strCompare()
 * Description : compare two string character ASCII code and length
 * Parameter 1 : the first object string_1
 * Parameter 2 : the last object string_2
 * return : <0(s1 < s2) 0(s1 == s2) >0(s1 > s2)
 */
int strCompare(const Str& str_1, const Str& str_2) {
    for (int i = 0; i < str_1.length && i < str_2.length; ++i) {
        if (str_1.ch[i] != str_2.ch[i]) {
            return str_1.ch[i] - str_2.ch[i];
        }
    }
    return str_1.length - str_2.length;
}

/*
 * FunctionName : strConcat()
 * Description : Concatenation two string to new string
 */
int strConcat(Str& str, const Str& str_1, const Str& str_2) {
    if (str.ch != nullptr) {
        delete[] str.ch;
        str.ch = nullptr;
    }
    str.ch = new char[str_1.length + str_2.length + 1];
    if (str.ch == nullptr) {
        cerr << "error : Storage space allocation failed" << endl;
        return EXIT_FAILURE;
    }
    int i = 0;
    while (i < str_1.length) {
        str.ch[i] = str_1.ch[i];
        ++i;
    }
    int j = 0;
    while (j <= str_2.length) {
        str.ch[i + j] = str_2.ch[j];
        ++j;
    }
    str.length = str_1.length + str_2.length;
    return EXIT_SUCCESS;
}

/*
 * FunctionName : getSubstring()
 * Description : return string's substring
 * Parameter 1 : the substring
 * Parameter 2 : the base string
 * Parameter 3 : the index of begin position
 * Parameter 4 : the length of substring
 * Return : operate result
 */
int getSubstring(Str& substr, const Str& str, int pos, int len) {
    if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos) {
        cerr << "error : the position or length is invalid" << endl;
        return EXIT_FAILURE;
    }
    if (substr.ch != nullptr) {
        delete[] substr.ch;
        substr.ch = nullptr;
    }
    if (len == 0) {
        substr.ch = nullptr;
        substr.length = 0;
        return EXIT_SUCCESS;
    }
    else {
        substr.ch = new char[len + 1];
        if (substr.ch == nullptr) {
            cerr << "error : Storage space allocation failed" << endl;
            return EXIT_FAILURE;
        }
        int i = pos;
        int j = 0;
        while (i < pos + len) {
            substr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return EXIT_SUCCESS;
    }
}

/*
 * FunctionName : clearString()
 * Description : clear object string
 */
int clearString(Str& str) {
    if (str.ch != nullptr) {
        delete[] str.ch;
        str.ch = nullptr;
    }
    str.length = 0;
    return EXIT_SUCCESS;
}