#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;

// 定义队的data域元素类型（根据具体问题）
typedef char QElemType;

// 定义最大队列长度
#define MAXSIZE 100

// 链队列的定义
typedef struct QNode {
    QElemType data; // 数据域
    QNode *next;    // 指针域
} QNode, *QueuePrt;

typedef struct LinkQueue {   
    QueuePrt front; // 指向链队列的头指针（指向头节点）
    QueuePrt rear;  // 指向链队列的尾指针（指向尾元素节点）
} LinkQueue;


// 1.链队列的初始化
Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QueuePrt)malloc(sizeof(QNode)); 
    if (Q.front == NULL) { return OVERFLOW; }
    Q.front->next = NULL;
    return OK;
}

// 2.链队列的销毁
Status DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        QueuePrt p = Q.front->next;
        free(Q.front);
        Q.front = p;
        // 或不添加新的指针变量，直接用Q.rear指针
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

// 3.将元素e入队
Status EnQueue(LinkQueue &Q, QElemType e) {
    QueuePrt p = (QueuePrt)malloc(sizeof(QNode));
    if (p == NULL) { return ERROR; }
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

// 4.链队列的出队
Status DeQueue(LinkQueue &Q, QElemType &e) {
    if (Q.front == Q.rear)  { return ERROR; }
    QueuePrt p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    
    // 如果要删除的是尾元结点，
    // 则需要将尾指针指向头指针（防止尾结点丢失）
    // 队列置空{
    if (p == Q.rear) { Q.rear = Q.front; }

    free(p);
    return OK;
}

// 4.链队列求队头元素
// QElemType GetHead(LinkQueue Q) {
//     return Q.front->next->data;
// }
Status GetHead(LinkQueue Q, QElemType &e) {
    if (Q.front == Q.rear)  { return ERROR; }
    e = Q.front->next->data;
    return OK;
}