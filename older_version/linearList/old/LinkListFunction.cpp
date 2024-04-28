#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

// 注意：1.使用头节点（头指针指向该节点，数据域一般无意义（或存储表长），指针域指向首元节点）
// 好处：对在第一个节点操作（前插入和删除）时，可与其他结点统一操作
// 以下单链表及其函数均为带头结点的情况
// 2.注意遍历指针p的初值与循环条件的判断的关系

typedef char ElemType;
typedef struct Node {
    ElemType data;
    Node *next;
} Node, *LinkList;  // Node为节点，L为单链表的头指针（并表示该链表）

// 1.单链表的获取元素，获取第i个元素，通过e返回
// （顺序存储结构，时间复杂度：O(n)）
Status GetElem(LinkList L, int i, ElemType &e);

// 2.单链表的插入，改变表L，将元素e插入到第i位后面；
// 在第一个或最后一个位置插入的操作相同
// 时间复杂度：O(n)
Status ListInsert(LinkList &L, int i, ElemType e);

// 3.单链表的删除，改变表L，将第i位元素从单链表中删除，保存数据域，释放其内存空间
// 在第一个或最后一个位置删除的操作相同
// 时间复杂度：O(n)
Status ListDelete(LinkList &L, int i, ElemType &e);

// 2、3对同一位置同时插入或删除多个元素时单链表只需第一次遍历找到位置i后（O(n)）,
// 再次插入时，直接通过该位置i指针运算进行操作（O(1)）,而顺序表每次插入或删除操作时间复杂度均为O(n)

// 4.单链表的整表创建（头插法）：有头节点
// 随机产生n个元素的值，建立带表头结点的单链表L
void CreatListHead(LinkList &L, int n);

// 5.单链表的整表创建（尾插法）：需要定义一个尾指针
// 随机产生n个元素的值，建立带表头结点的单链表L
void CreatListTail(LinkList &L, int n);

// 6.单链表的整表删除：L重置为空表（仅含头节点）（头删法）
Status ClearList(LinkList &L);

Status GetElem(LinkList L, int i, ElemType &e) {
    Node *p = L->next;  // p为指向首元节点的指针
    
    // 事先不知道循环次数，不方便使用for控制循环
    // 遍历单链表，情况：1.到达i时，j=i退出循环；2.p=表尾的指针域=NULL退出循环
    int j;  //计数器
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) return ERROR;
    else {
    e = p->data;
    return OK;
    }
}

Status ListInsert(LinkList &L, int i, ElemType e) {
    Node *p = L;    
    // p指向头节点，遍历i次时，指向第i-1个节点
    // 插入表尾结点时p->next=NULL，所以仅当p=NULL时插入位置非法
    int j;
    while (p && j < i) {
        p = p->next;    // p条件等于p != NULL
        j++;
    }
    if (!p || j > i) return ERROR;// !p等于p == NULL
    else {
        Node *s = (Node *)malloc(sizeof(Node));
        s->data = e;
        s->next = p ->next;
        p->next = s;
        return OK;
    }
}

Status ListDelete(LinkList &L, int i, ElemType &e) {
    Node *p = L;    
    // p指向头节点，遍历i次时，指向第i-1个节点
    // 删除表尾结点时：用p->next指向表尾结点，所以当p->next=NULL时删除位置非法
    int j = 1;
    while (p->next  && j < i) { // p->next条件等于p->next != NULL
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i) return ERROR;  // !p->next等于p->next == NULL
    else {
        Node *s = p->next;
        p->next = p->next->next;
        e = s->data;
        free(s); 
        return OK;
    }
}

void CreatListHead(LinkList &L, int n) {
    srand(time(NULL));  // 重新播种，生成随机数

    LinkList L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;     // 建立带头结点的单链表L，L为空（其中不含元素）

    for (int i = 0; i < n; i++) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; // 随机生成一个100以内的非负数
        // 插入到表头
        p->next = L->next;
        L->next = p;
    }
}

void CreatListTail(LinkList &L, int n) {
    srand(time(NULL));

    LinkList L = (LinkList)malloc(sizeof(Node));
    Node *r = L;    // r恒指向尾结点（r为尾指针）

    for (int i = 0; i < n; i++) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL; // 创建结束，尾结点的指针域指向NULL
}

Status ClearList(LinkList &L) {
    Node *p, *q;
    p = L->next;    // p=头节点指针域，指向首元节点
    while (p) {     // p != NULL，没有到表尾
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; // L置空，仅含头节点
    return OK;
}