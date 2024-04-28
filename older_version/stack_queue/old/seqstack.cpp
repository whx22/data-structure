// 顺序栈

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;

// 定义
#define MAXSIZE 100

// 栈的data域元素类型（根据具体问题定义）
typedef char SElemType;

// 为方便操作，top的下标为栈顶元素的下一位
// （逻辑位置i+1，存储位置为数组下标i）
// base：（栈底，逻辑位置1，存储位置为数组下标0）
// stacksize：（逻辑最大容量，最大存储位置为数组下标(stacksize-1)）
// 空栈：top == base
// 满栈：top - base == stacksize
// 栈中元素个数 == top - base
// 上溢(overflow)：满栈状态，任然压栈（错误）
// 下溢(underflow)：空栈状态，任然弹栈（结束条件）

// 两种定义方法均可以
typedef struct SeqStack {
    int top;
    int base;
    int stacksize;
} SeqStack;

// 对同一数组*top、*base运算时，作用同数组下标进行运算
// （运算单位为整个元素的存储大小，而非一个字节）
typedef struct SeqStack {
    SElemType *top;
    SElemType *base;
    int stacksize;
} SeqStack;

// 1.顺序栈的初始化
Status InitStack(SeqStack &S) {
    // 顺序栈的数组的首地址用*base存储（即*base指向整个栈）
    S.base = new SElemType[MAXSIZE];
    // S.base = (SElemType *)malloc(sizeof(SElemType) * MAXSIZE);
    if (!(S.base)) { exit(OVERFLOW); }
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

// 2.判断顺序栈是否为空
Status StackEmpty(SeqStack S) {
    if (S.top == S.base) { return TRUE; }
    else { return FALSE; }
}

// 3.求顺序栈的长度
int StackLength(SeqStack S) {
    return (S.top - S.base);
}

// 4.清空顺序栈
Status ClearStack(SeqStack &S) {
    if (S.base) { S.top = S.base; }
    return OK;
}

// 5.销毁顺序栈
Status DestroyStack(SeqStack &S) {
    if (S.base) {
        delete S.base;
        // free(S.base);
        S.stacksize = 0;
        S.top = S.base = NULL;
    }
    return OK;
}

// 6.顺序栈的压栈
Status Push(SeqStack &S, SElemType e) {
    if (S.top - S.base == S.stacksize) { return ERROR; }    // 上溢
    
    *S.top++ = e;
    // 等效于    *S.top = e;
    //           S.top++;
    return OK;
}

// 7.顺序栈的弹栈
Status Pop(SeqStack &S, SElemType &e) {
    if (StackEmpty(S)) { return ERROR; }    // 下溢 
    // StackEmpty(S)等价于S.top == S.base
    
    e = *--S.top;
    // 等效于    S.top--;
    //          e = *S.top;
    
    return OK;
}