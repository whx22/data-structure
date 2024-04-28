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

typedef int QElemType;  // 根据具体问题具体分析
typedef struct SeqQueue {
    QElemType data[MAXSIZE];
    int front;  // 指向队头下标
    int rear;   // 指向队尾下标的下一位
} SeqQueue;

// 1.初始化一个队列
Status InitQueue(SeqQueue &Q) {
    Q.rear = Q.front = 0;
    return OK;
}

// 2.求队列的长度
int QueueLength(SeqQueue Q) {
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

// 3.入队
Status EnQueue(SeqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) { return ERROR; }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}   

// 4.出队
Status DeQueue(SeqQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) { return ERROR; }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}