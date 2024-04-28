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
} SeqList; // ����˳���

typedef struct LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList; // ���嵥�����㣬������

// ˳���ĳ�ʼ��
Status InitSeqList(SeqList &L) {
    L.length = 0;
    return OK;
}

// ˳���Ĳ���
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
    int top; // ����ջ��ָ�룬top == -1����ջ��top == MAXSIZE - 1����ջ��
} SeqStack;

typedef struct SeqQueue {
    char str[MAXSIZE];
    int front; // ָ���ͷ�±�
    int rear;  // ָ���β�±����һλ
} SeqQueue;

// ��ʼ��ջ
Status InitStack(SeqStack &S) {
    S.top = -1;
    return OK;
}

// ��ջ�ĳ���
int StackLength(SeqStack S) {
    return S.top + 1;
}

// ѹջ����Ԫ��e����ջ������Ϊջ��Ԫ�أ�
Status Push(SeqStack &S, char e) {
    if (S.top == MAXSIZE - 1)
        return ERROR; //ջ��
    S.top++;
    S.str[S.top] = e;
    return OK;
}

// ��ջ��ɾ��S��ջ��Ԫ�أ���e���أ�
Status Pop(SeqStack &S, char &e) {
    if (S.top == -1)
        return ERROR; //��ջ
    e = S.str[S.top];
    S.top--;
    return OK;
}

// ��ʼ��һ������
Status InitQueue(SeqQueue &Q) {
    Q.rear = Q.front = 0;
    return OK;
}

// ����еĳ���
int QueueLength(SeqQueue Q) {
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

// ���
Status EnQueue(SeqQueue &Q, char e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return ERROR;
    Q.str[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}

// ����
Status DeQueue(SeqQueue &Q, char &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.str[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}


#endif