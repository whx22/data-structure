#ifndef _HEAD_H
#define _HEAD_H

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;

//定义最大元素个数
#define MAXSIZE 100

typedef char TElemType;

typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

typedef BiTree SElemType;

typedef struct SeqStack
{
    SElemType *top;
    SElemType *base;
    int stacksize;
}SeqStack;

//1.顺序栈的初始化
Status InitStack(SeqStack &S)
{
    //顺序栈的数组的首地址用*base存储（即*base指向整个栈）
    S.base = (SElemType *)malloc(sizeof(SElemType) * MAXSIZE);
    if (!(S.base)) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//2.判断顺序栈是否为空
Status StackEmpty(SeqStack S)
{
    if (S.top == S.base) return TRUE;
    else return FALSE;
}

//3.求顺序栈的长度
int StackLength(SeqStack S)
{
    return (S.top - S.base);
}

//4.清空顺序栈
Status ClearStack(SeqStack &S)
{
    if (S.base) S.top = S.base;
    return OK;
}

//5.销毁顺序栈
Status DestroyStack(SeqStack &S)
{
    if (S.base)
    {
        delete S.base;
        //free(S.base);
        S.stacksize = 0;
        S.top = S.base = NULL;
    }
    return OK;
}

//6.顺序栈的压栈
Status Push(SeqStack &S, SElemType e)
{
    if (S.top - S.base == S.stacksize) return ERROR;//上溢
    
    *S.top++ = e;
    //等效于    *S.top = e;
    //          S.top++;
    return OK;
}

//7.顺序栈的弹栈
Status Pop(SeqStack &S, SElemType &e)
{
    if (StackEmpty(S)) return ERROR;//下溢 
    //StackEmpty(S)等价于S.top == S.base
    
    e = *--S.top;
    //等效于    S.top--;
    //          e = *S.top;

    return OK;
}

//8.获取栈顶元素
Status GetTop(SeqStack S, SElemType &e)
{
    if (StackEmpty(S)) return ERROR;
    e = *--S.top;
    return OK;
}

#endif