#include <iostream>
using namespace std;

#define MAXSIZE 100

// 静态链表意义 : 早期高级语言不含指针类型, 实现链表的存储结构

// 静态链表结点类型定义
typedef struct {
    int             data;
    unsigned int    next;
} SLNode;

// 静态链表类型定义
SLNode SLinkList[MAXSIZE];

// int p = Ad0;         // 定义一个指针 
// SLinkList[p].data;   // 取p结点的数据域, 类比 p->data;
// SLinkList[p].next;   // 取p结点后继结点指针, 类比 p->next;

// 在p结点后插入q结点
// SLinkList[q].next = SLinkList[p].next;
// SLinkList[p].next = q;
// 类比链表
// q->next = p->next;
// p->next = q;