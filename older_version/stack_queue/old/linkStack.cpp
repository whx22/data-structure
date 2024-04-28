#include <stdio.h>
#include <stdlib.h>

#define OK;
#define ERROR;
#define TRUE;
#define FALSE;
typedef int Status;

#define MAXSIZE;

typedef int SELemType;

// 头结点的使用可以统一对链表中个元素的操作
// 对于栈的各种操作（仅对栈顶元素进行操作），头节点无意义
// 使用头指针（同时是栈顶指针）即可
// top == NULL 空栈

// 链栈结点的定义
typedef struct StackNode {
    SELemType data;
    StackNode *next;
} StackNode, *LinkStackPtr;

// 链栈的定义
typedef struct LinkStack {
    LinkStackPtr top;   // 栈顶指针（头指针）
    int court;          // 栈中元素
} *LinkStack;

// 1.压栈（时间复杂度O(1)）
Status Push(LinkStack &S, SELemType e) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->court++;
    return OK;
}

// 2.弹栈（时间复杂度O(1)）
Status Pop(LinkStack &S, SELemType &e) {
    if (S->top == NULL) { return ERROR; }
    LinkStackPtr p = S->top;
    e = p->data;
    S->top = S->top->next;
    free(p);
    S->court--;
    return OK;
}