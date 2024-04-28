#include <iostream>
using namespace std;

// 存储密度 : 结点数据本身所占的存储量 / 整个结点结构所占的存储量

// 顺序表存储结构
#define MAXSIZE 100
typedef struct SeqList {
    int data[MAXSIZE];
    int length;
} SeqList;

// 链式存储结构(单链表)
typedef struct LNode {
    int             data;
    struct LNode*   next;
} LNode;
typedef LNode* LinkList;

// 链式存储结构(双链表)
typedef struct DLNode {
    int             data;
    struct DLNode*  prior;
    struct DLNode*  next;
} DLNode;
typedef DLNode* DLinkList;

// 链式存储结构(循环链表)判空条件
// 含头结点单循环链表 : head->next == head;
// 含头结点双循环链表 : head->prior == head && head->next == head;
// 不含头结点单双循环链表 : head == nullptr;