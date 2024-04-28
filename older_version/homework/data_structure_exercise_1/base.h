#ifndef _BASE_H
#define _BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList; // 定义顺序表

typedef struct LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList; // 定义单链表结点，单链表

// 顺序表的初始化
Status InitSeqList(SeqList &L) {
    L.length = 0;
    return OK;
}

// 顺序表的插入
Status ListInsert(SeqList &L, int i, ElemType e) {
    if (L.length == MAXSIZE || i < 1 || i > L.length + 1)
        return ERROR;

    if (i <= L.length) {
        for (int j = L.length - 1; j >= i - 1; j--) {
            L.data[j + 1] = L.data[j];
        }
    }
    L.data[i - 1] = e;
    L.length++;
    return OK;
}

typedef struct {
    char str[MAXSIZE];
    int top; // 用于栈顶指针，top == -1（空栈）top == MAXSIZE - 1（满栈）
} SeqStack;

typedef struct SeqQueue {
    char str[MAXSIZE];
    int front; // 指向队头下标
    int rear;  // 指向队尾下标的下一位
} SeqQueue;

// 初始化栈
Status InitStack(SeqStack &S) {
    S.top = -1;
    return OK;
}

// 求栈的长度
int StackLength(SeqStack S) {
    return S.top + 1;
}

// 压栈（将元素e插入栈顶并作为栈顶元素）
Status Push(SeqStack &S, char e) {
    if (S.top == MAXSIZE - 1)
        return ERROR; //栈满
    S.top++;
    S.str[S.top] = e;
    return OK;
}

// 弹栈（删除S的栈顶元素，用e返回）
Status Pop(SeqStack &S, char &e) {
    if (S.top == -1)
        return ERROR; //空栈
    e = S.str[S.top];
    S.top--;
    return OK;
}

// 初始化一个队列
Status InitQueue(SeqQueue &Q) {
    Q.rear = Q.front = 0;
    return OK;
}

// 求队列的长度
int QueueLength(SeqQueue Q) {
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

// 入队
Status EnQueue(SeqQueue &Q, char e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return ERROR;
    Q.str[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}

// 出队
Status DeQueue(SeqQueue &Q, char &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.str[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}


#endif