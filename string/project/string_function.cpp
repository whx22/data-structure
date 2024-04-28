//
// Created by whx on 23-3-3.
//

#include "string_function.h"

void strInit(Str& str) {
    str.str = nullptr;
    str.length = 0;
}

void strPrint(Str& str) {
    for (int i = 0; i < str.length; ++i) {
        cout << str.str[i];
    }
    cout << endl;
}

void strAssign(Str& str, const char* ch) {
    if (str.str != nullptr) {
        delete[] str.str;
        str.str = nullptr;
    }
    int length = 0;
    char* c = const_cast<char*>(ch);
    while (*c != '\0') {
        ++c;
        ++length;
    }
    if (length == 0) {
        str.str = nullptr;
        str.length = 0;
        return;
    }
    else {
        str.str = new char[length + 1];
        if (str.str == nullptr) {
            throw bad_alloc();
        }
        else {
            c = const_cast<char*>(ch);
            for (int i = 0; i <= length; ++i, ++c) {
                str.str[i] = *c;
            }
            str.length = length;
            return;
        }
    }
}

int strLength(const Str& str) {
    return str.length;
}

int strCompare(const Str& str_1, const Str& str_2) {
    for (int i = 0; i < str_1.length && i < str_2.length; ++i) {
        if (str_1.str[i] != str_2.str[i]) {
            return str_1.str[i] - str_2.str[i];
        }
    }
    return str_1.length - str_2.length;
}

void strConcat(Str& result_str, const Str& str_1, const Str& str_2) {
    if (result_str.str != nullptr) {
        delete[] result_str.str;
        result_str.str = nullptr;
    }
    result_str.str = new char[str_1.length + str_2.length + 1];
    if (result_str.str == nullptr) {
        throw bad_alloc();
    }
    int i = 0;
    while (i < str_1.length) {
        result_str.str[i] = str_1.str[i];
        ++i;
    }
    int j = 0;
    while (j <= str_2.length) {
        result_str.str[i + j] = str_2.str[i];
        ++j;
    }
    result_str.length = str_1.length + str_2.length;
}

void getSubstring(Str& substr, const Str& str, const int& pos, const int& len) {
    if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos) {
        throw invalid_argument("error : the argument is invalid");
    }
    if (substr.str != nullptr) {
        delete[] substr.str;
        substr.str = nullptr;
    }
    if (len == 0) {
        substr.str = nullptr;
        substr.length = 0;
        return;
    }
    else {
        substr.str = new char[len + 1];
        if (substr.str == nullptr) {
            throw bad_alloc();
        }
        int i = pos;
        int j = 0;
        while (i < pos + len) {
            substr.str[j] = str.str[i];
            ++i;
            ++j;
        }
        substr.str[j] = '\0';
        substr.length = len;
    }
}

void clearString(Str& str) {
    if (str.str != nullptr) {
        delete[] str.str;
        str.str = nullptr;
    }
    str.length = 0;
}

int BF(const Str& str, const Str& substr, int pos) {
    int i = pos, j = 1;
    while (i <= str.length && j < substr.length) {
        if (str.str[i] == substr.str[j]) {
            ++i;
            ++j;
        }
        else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > substr.length) {
        return i - substr.length;
    }
    else {
        return 0;
    }
}

void getNext(const Str& substr, int next[]) {
    int j = 1, t = 0;
    next[1] = 0;
    while (j < substr.length) {
        if (t == 0 || substr.str[j] == substr.str[t]) {
            substr.str[j + 1] = t + 1;
            ++t;
            ++j;
        }
        else {
            t = next[t];
        }
    }
}

void getNextval(const Str& substr, int nextval[]) {
    int j = 1, t = 0;
    nextval[1] = 0;
    while (j < substr.length) {
        if (t == 0 || substr.str[j] == substr.str[t]) {
            if (substr.str[j + 1] != substr.str[t + 1]) {
                nextval[j + 1] = t + 1;
            }
            else {
                nextval[j + 1] = nextval[t + 1];
            }
            ++t;
            ++j;
        }
        else {
            t = nextval[t];
        }
    }
}

int KMP(const Str& str, const Str& substr, int nextval[], int pos) {
    int i = pos, j = 1;
    while (i <= str.length && j <= str.length) {
        if (j == 0 || str.str[i] == substr.str[j]) {
            ++i;
            ++j;
        }
        else {
            j = nextval[j];
        }
    }
    if (j >substr.length) {
        return i - substr.length;
    }
    else {
        return 0;
    }
}