// 队列是只允许在一端进行插入操作，而另一端进行删除操作的线性表
// FIFO(first in first out)
// 队尾：允许插入
// 队头：允许删除

/*
 ADT 队列（Queue）
 Data
    同线性表。元素类型相同，有前驱和后继关系
 Operation
    InitQueue(*Q)：初始化操作，建立一个空队列Q
    DestroyQueue(*Q)：队列Q若存在，则销毁
    ClearQueue(*Q)：将队列Q清空
    QueueEmpty(Q)：队列Q的判空，空返回TRUE，非空返回FALSE
    GetHead(Q, *e)：队列Q存在且非空，用e存储队列Q队头元素
    EnQueue(*Q, e)：队列Q存在，插入新元素e到队列Q中并成为队尾元素
    DeQueue(*Q, *e)：删除队列Q的队头元素，用e返回
    QueueLength(Q)：返回队列Q中元素的个数
 endADT
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 100
typedef int QElemType;  // 定义数据域类型,根据具体问题具体分析
typedef struct QNode {
    QElemType data;
    QNode *next;
} QNode, *QueuePtr; // 定义链队列结点，及其指针类型

typedef struct LinkQueue {
    QueuePtr front, rear;   // front头指针，rear队尾元素指针
} LinkQueue;    // 定义链队列

// 1.链队列的初始化
Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear =(QueuePtr)malloc(sizeof(QNode));
    if (Q.front == NULL) { return ERROR; }
    Q.front->next = NULL;
    return OK;
}

// 2.链队列的销毁
Status DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        QueuePtr p = Q.front->next;
        free(Q.front);
        Q.front = p;
    }
    return OK;
}

// 3.获取队头元素
// QElemType GetHead(LinkQueue Q) {
//     if (Q.front == Q.rear) return ERROR;
//     return Q.front->next->data;
// }
Status GetHead(LinkQueue Q, QElemType &e) {
    if (Q.front == Q.rear) { return ERROR; }
    e = Q.front->next->data;
    return OK;
}

// 4.入队
Status EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (p == NULL) { return ERROR; }
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

// 5.出队
Status DeQueue(LinkQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) { return ERROR; }
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    
    // 如果要删除的是尾元结点，
    // 则需要将尾指针指向头指针（防止尾结点丢失）
    // 队列置空
    if (p == Q.rear) { Q.rear = Q.front; }

    free(p);
    return OK;
}