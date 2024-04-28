// 栈、队列：操作受限的线性表
// 串、数组、广义表：内容受限的线性表，线性结构的推广

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 255
// 串的顺序结构定义
typedef struct {
    char ch[MAXSIZE + 1];   // ch[0]不存储字符，方便操作
    int length;             // 串的长度
} SString;  // 定义类型

// 串的链式存储结构
// 优点：操作方便
// 缺点：存储密度较低：20%（解决方法：一个节点（块）存储多个字符）
// 串的链式存储结构——块链
#define CHUNKSIZE 80   // 块的大小
typedef struct CHUNK {
    char ch[CHUNKSIZE];
    CHUNK *next;
} CHUNK;

typedef struct {
    CHUNK *head, *tail;     // 串的头指针，尾指针
    int curlen;             // 串当前的长度
} LString;  // 字符串的块链结构

// 串的模式比配算法
// 确定主串中所含子串（模式串）第一次出现的位置（定位）
// 算法种类
// BF算法（Brute-Force）时间复杂度O(m*n)
// KMP算法（特点：速度快）时间复杂度O(m+n) 

// BF算法
// 匹配失败：
// 主串i-j+1（i回到比较的首位制）+1（移动到下一位）：i = i - j + 2;（回溯）
// 模式串：j = 1;（回到模式串的头部）
// 到字符串结束没有匹配成功返回0
// 匹配成功：
// 返回位置：i - T.length;
// 时间复杂度分析
// 最好情况：比较m次（第一位匹配）
// 最坏情况：比较(n-m+1)*m次（不匹配或在n-m位匹配）
// 若m<<n,时间复杂度O(n*m)

// 在主串S中匹配模式串T
int index_BF(SString S, SString T) {
    int i = 1, j = 1;
    // i > S.length 时匹配失败
    // j > T.length 时匹配成功
    while (i <= S.length && j <= T.length) {
        // 字符相等，比较下一位
        if (S.ch[i] == T.ch[j]) {i++; j++;} 
        // 字符不等，匹配失败，i回溯，j回到T头部
        else {i = i - j + 2; j = 1;}    
    }
    // 匹配成功，返回匹配的第一个字符下标
    if (j >= T.length) return i - T.length;
    // 否则返回0 
    else return 0;
}

// 指定从主串的pos位置开始匹配模式串T
int Index_BF(SString S, SString T, int pos) {
    int i = pos, j = 1;
    while (i <= S.length && j <= S.length) {
        if (S.ch[i] == T.ch[j]) {i++; j++;}
        else {i = i - j + 2; j = 1;}
    }
    if (j >= T.length) return i - T.length;
    else return 0; 
}

// KMP（Knuth Morris Pratt）算法
// 时间复杂度O(n+m)
// 利用已经匹配的结果加快模式串的滑动
// 主串的指针i不必回溯   
int Index_KMP(SString S, SString T) {
    // TODO
}