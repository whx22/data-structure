#include <iostream>
using namespace std;

typedef struct {
    char* str;
    unsigned int length;
} String;

// int BF(const String& str, const String& substr, const int& pos = 1) {
//     int i = pos, j = 1;
//     while (i < str.length && j < substr.length) {
//         if (str.str[i] == substr.str[j]) {
//             ++i;
//             ++j;
//         }
//         else {
//             i = i - j + 2;
//             j = 1;
//         }
//     }
//     if (j > substr.length) {
//         return i - substr.length;
//     }
//     else {
//         return 0;
//     }
// }

// void getNext(const String& substr, int next[]) {
//     int j = 1, t = 0;   // 假设 t == next[j] 
//     next[1] = 0;    // 设置第一个元素next值为0
//     while (j < substr.length) { // 每一轮计算next[j + 1]的值
//         if (t == 0 || substr.str[j] == substr.str[t]) { // j位置字符等于t == next[j]位置字符
//             // 则next[j + 1] = t + 1;
//             next[j + 1] = t + 1;
//             ++t;    // 公共前缀长度+1
//             ++j;    // 计算下一位next数组值
//         }
//         else {  // j位置字符不等于t == next[j]位置字符
//             // 则尝试j与next[next[t]]位置的字符
//             // 如果一直不相等 : t = 0
//             t = next[t];    
//         }
//     }
// }

// void getNextval(const String& substr, int nextval[]) {
//     int j = 1, t = 0;
//     nextval[1] = 0;
//     while (j < substr.length) {
//         if (t == 0 || substr.str[j] == substr.str[t]) {
//             if (substr.str[j + 1] != substr.str[t + 1]) {   // 如果j + 1位置字符不等于next[j] + 1位置上的字符, 值得比较
//                 nextval[j + 1] = t + 1;
//             }
//             else {  // 否则, 不值得比较, 将nextval[t + 1]赋值给nextval数组的j + 1位置的值
//                 nextval[j + 1] = nextval[t + 1];
//             }
//             ++j;
//             ++t;
//         }
//         else {
//             t = nextval[t];
//         }
//     }
// }

// int KMP(const String& str, const String& substr, int nextval[], int pos = 1) {
//     int i = pos, j = 1;
//     while (i < str.length && j < substr.length) {
//         if (j == 0 || str.str[i] == substr.str[j]) {    // j == 0 : 当第一个字符比较不相等时, 通过j(此时为1) = nextval[j] = nextval[1] = 0时, 主串和子串同时后移再进行比较
//             ++i;
//             ++j;
//         }
//         else {
//             j = nextval[j];
//         }
//     }
//     if (j > substr.length) {
//         return i - substr.length;
//     }
//     else {
//         return 0;
//     }
// }

int BF(const String& str, const String& subStr, const int& pos = 1) {
    int i = pos, j = 1;
    while (i <= str.length && j <= subStr.length) {
        if (str.str[i] == subStr.str[j]) {
            ++i;
            ++j;
        }
        else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > str.length) {
        return i - str.length;
    }
    else {
        return 0;
    }
}

void getNext(const String& str, int next[]) {
    int j = 1, t = 0;
    next[1] = 0;
    while (j < str.length) {
        if (t == 0 || str.str[j] == str.str[t]) {
            next[j + 1] = t + 1;
            ++t;
            ++j;
        }
        else {
            t = next[t];
        }
    }
}

void getNextval(const String& str, int nextval[]) {
    int j = 1, t = 0;
    nextval[1] = 0;
    while (j < str.length) {
        if (t == 0 || str.str[j] == str.str[t]) {
            if (str.str[j + 1] != str.str[t + 1]) {
                nextval[j + 1] = t + 1;
            }
            else {
                nextval[j + 1] = nextval[t + 1];
            }
        }  
        else {
            t = nextval[t];
        }
    }
}

int KMP(const String& str, const String& substr, int nextval[], const int& pos = 1) {
    int i = pos, j = 1;
    while (i < str.length && j < substr.length) {
        if (j == 0 || str.str[i] == substr.str[j]) {
            ++i;
            ++j;
        }
        else {
            j = nextval[j]; 
        }
    }
    if (j > substr.length) {
        return i - substr.length;
    }
    else {
        return 0;
    }
}