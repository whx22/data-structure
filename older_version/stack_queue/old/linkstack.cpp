// 链式栈
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;

// 定义最大元素个数
#define MAXSIZE 100

// 栈的data域元素类型（根据具体问题定义）
typedef char SElemType;

// 链式栈定义
typedef struct StackNode {
    SElemType data;
    StackNode *next;
} StackNode, *LinkStack;
// 注意：
// 1.栈的操作只能在栈顶，对链表中的最后一个元素进行操作，
// 因此链式栈的指针方向为元素n的指针指向n-1，第1个元素的指针指向NULL
// 2.*LinkStack指向最后的元素n（方便压栈和弹栈的操作）
// 3.不需要头节点
// 4.头指针就是栈顶
// 5.第一个元素就是栈底
// 6.压栈（头插法）、弹栈（头删法）
// 7.基本不存在满栈的情况，空栈时*LinkStack指向NULL

// 1.链栈的初始化
Status InitStack(LinkStack &S) {
    S = NULL;
    return OK;
}

// 2.判断链栈是否为空
Status StackEmpty(LinkStack S) {
    if (S == NULL) { return TRUE; }
    else { return FALSE; }
}

// 3.链栈的压栈
Status Push(LinkStack &S, SElemType e) {   
    StackNode *p = new StackNode;
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
}

// 4.链栈的弹栈
Status Pop(LinkStack &S, SElemType &e) {
    if (StackEmpty(S)) { return ERROR; }
    e = S->data;
    StackNode *p = S;
    S = S->next;
    delete p;
    // free(p);
    return OK;
}

// 5.去链栈的栈顶元素
SElemType GetTop(LinkStack S) {
    if (S != NULL) { return S->data; }
}