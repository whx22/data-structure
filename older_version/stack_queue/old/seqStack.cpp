// 栈是限定仅在表尾进行插入和删除操作的线性表
// LIFO(last in first out)
// top：栈顶（允许进行插入和删除操作）
// bottom：栈底

/*
 ADT 栈（stack）
 Data
    同线性表。元素类型相同，有前驱和后继关系
 Operation
    InitStack(*S)：初始化操作，建立一个空栈S
    DestroyStack(*S)：栈S若存在，则销毁
    ClearStack(*S)：将栈清空
    StackEmpty(S)：栈的判空，空返回TRUE，非空返回FALSE
    GetTop(S, *e)：栈存在且非空，用e存储栈S栈顶元素
    Push(*S, e)：将元素e插入栈S中并成为栈顶元素
    Pop(*S, *e)：删除栈S的栈顶元素，通过e返回
    StackLength(S)：返回栈S中元素的个数
 endADT
*/
#include <stdio.h>
#include <stdlib.h>

#define OK;
#define ERROR;
#define TRUE;
#define FALSE;
typedef int Status;

#define MAXSIZE 100

typedef int SElemType;  // 根据实际问题定义SElemType类型
typedef struct SeqStack {
    SElemType data[MAXSIZE];
    int top;    // 用于栈顶指针，top == -1（空栈）top == MAXSIZE - 1（满栈）
} *SeqStack;

// 1.压栈（将元素e插入栈顶并作为栈顶元素）时间复杂度O(1)
Status Push(SeqStack &S, SElemType e) {
    if (S->top == MAXSIZE - 1) { return ERROR; }    // 栈满
    S->top++;
    S->data[S->top] = e;
    return OK;
}

// 2.弹栈（删除S的栈顶元素，用e返回）时间复杂度O(1)
Status Pop(SeqStack &S, SElemType &e) {
    if (S->top == -1) { return ERROR; } // 空栈
    e = S->data[S->top];
    S->top--;
    return OK;
}

// 两栈共享空间结构
typedef struct SeqDoubleStack {
    SElemType data[MAXSIZE];
    int top1;   // 栈1栈顶指针
    int top2;   // 栈2栈顶指针
} *SeqDoubleStack;

// 1.共享栈的Push
// 额外需要插入元素的栈号参数（栈1或栈2）StackNumber(int型)
Status Push(SeqDoubleStack &S, SElemType e, int StackNumber) {
    if (S->top1 + 1 == S->top2) { return ERROR; }  // 共享栈已满
    
    if (StackNumber == 1) { // 在栈1插入
        S->top1++;
        S->data[S->top1] = e;
        // 另一种写法：S->data[++S->top1] = e;
    }
    else if (StackNumber == 2) {
        S->top2--;
        S->data[S->top2] = e;
        // 另一种写法：S->data[--S->top2] = e;
    }
    return OK;
}

// 2.共享栈的Pop
// 额外需要插入元素的栈号参数（栈1或栈2）StackNumber(int型)
Status Pop(SeqDoubleStack &S, SElemType &e, int StackNumber) {
    if (StackNumber == 1) {
        if (S->top1 == -1) { return ERROR; }
        e = S->data[S->top1];
        S->top1--;
        // e = S->data[S->top1--];
    }
    else if (StackNumber == 2) {
        if (S->top2 == MAXSIZE) { return ERROR; }
        e = S->data[S->top2];
        S->top2++;
        // e = S->data[S->top2++];
    }
    return OK;
}