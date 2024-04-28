#ifndef _QUEUE_H
#define _QUEUE_H

#include "biTreeHead.h"
// 定义队的data域元素类型（根据具体问题）
typedef int QElemType;

// 顺序队的定义
typedef struct SeqQueue {
    QElemType *base;                    // 初始化动态分配的存储空间
    // QElemType data[SeqQueueSize];    // 初始化静态分配的存储空间
    
    // front指向第一位元素的下标，rear指向最后一位元素的下一位下标
    // 该中定义方式统一了出队和入队时对front与rear的操作，其他方式同样可以
    int front;  // 头元素下标（头指针）指向第一位元素的下标
    int rear;   // 尾元素下标（尾指针）指向最后一位元素的下一位下标
} SeqQueue;

// 使用模运算构建循环链表克服假溢出的情况
// 入队
//  SeqQueue.data[rear] = e;
//  SeqQueue.rear = (SeqQueue.rear + 1) % SeqQueueSize;
// 出队
//  e = SeqQueue.data[front];
//  SeqQueue.front = (SeqQueue.front + 1) % SeqQueueSize;
// 循环队列解决队空与队满条件相同的问题（front == rear）
//  1.另外设置一个标志区别队空、队满
//  2.另设一个变量court，记录元素个数
//  3.少用一个元素空间
// 队空：rear == front;
// 队满：(rear + 1) % SeqQueueSize == front;

// 1.队列的初始化
Status InitQueue(SeqQueue &Q) {
    Q.base = new QElemType[MAXSIZE];
    // Q.base = (QElemType *)malloc(sizeof(QElemType) * MAXSIZE);
    if (Q.base == NULL) {
        return OVERFLOW;
    }
    Q.front = Q.rear = 0;
    return OK;
}

// 2.求循环队列的长度
// QueueLength == (rear - front + MAXSIZE) % MAXSIZE（类似补码运算）
int QueueLength(SeqQueue Q) {
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

// 3.循环队列的入队
Status EnQueue(SeqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) { return ERROR; }    // 队满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}

// 4.循环指针的出队
Status DelQueue(SeqQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) { return ERROR; }    // 队空
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}

// 5.取队头元素
// QElemType GetHead(SeqQueue Q) {
//     if (Q.front != Q.rear) {
//     return Q.base[Q.front];
//     }
// }
Status GetHead(SeqQueue Q, QElemType &e) {
    if (Q.front == Q.rear) { return ERROR; }    // 队空
    e = Q.base[Q.front];
    return OK;
}

// 6.队列的判空
Status QueueEmpty(SeqQueue Q) {
    if (Q.front == Q.rear) { return TRUE; }
    else { return FALSE; }
}


#endif