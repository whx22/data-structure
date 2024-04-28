/*
排序函数所需要的头文件
1.所需要的C库头文件
2.函数返回值、返回状态
3.排序元素的最大值大小、比较关键值类型
4.比较元素存储结构定义
5.顺序表存储结构定义
*/

#ifndef _HEAD_H
#define _HEAD_H

//1.所需要的C库头文件
#include <stdio.h>
#include <stdlib.h>

//2.函数返回值、返回状态
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;

//3.排序元素的最大值大小、比较关键值类型
#define MAXSIZE 20      //比较元素不超过MAXSIZE
typedef int KeyType;    //比较关键值类型

//4.比较元素存储结构定义
typedef struct
{
    KeyType key;    //关键字域
    //InfoType otherInfo    //其他数据域
}RecordType;    //记录元素类型

//5.顺序表存储结构定义
typedef struct
{
    RecordType list[MAXSIZE+1];  //list[0]作哨兵或缓冲区
    int length;     //顺序表的长度
}SeqList;       //顺序表类型


#endif