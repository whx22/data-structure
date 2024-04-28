#include <iostream>
using namespace std;

// 顺序表求最值
int maxOfArray(int array[], int length) {
    int max = array[0];
    int maxIndex = 0;
    for (int i = 0; i < length; ++i) {
        if (max < array[i]) {
            max = array[i];
            maxIndex = i;
        }
    }
    return max;
}

int minOfArray(int array[], int length) {
    int min = array[0];
    int minIndex = 0;
    for (int i = 0; i < length; ++i) {
        if (min > array[i]) {
            min = array[i];
            min = i;
        }
    }
    return min;
}

// 带头结点的单链表求最值
typedef struct LNode {
    int             data;
    struct LNode*   next;
} LNode;
typedef LNode* LinkList;

void maxOfLinkList(LinkList head) {
    int max = head->next->data;
    LNode* p = head->next;
    LNode* q = head->next;
    while (p != nullptr) {
        if (max < p->data) {
            max = p->data;
            q = p;
        }
        p = p->next;
    }
}

void minOfLinkList(LinkList head) {
    int min = head->next->data;
    LNode* p = head->next;
    LNode* q = head->next;
    while (p != nullptr) {
        if (min > p->data) {
            min = p->data;
            q = p;
        }
        p = p->next;
    }
}

void moveMax(LinkList head) {
    int max = head->next->data;
    LNode* p = head;
    LNode* q = head->next;
    while (p->next != nullptr) {
        if (max < p->next->data) {
            max = p->next->data;
            q = p->next;
        }
        p = p->next;
    }
    LNode* t = q->next;
    q->next = t->next;
    t->next = head->next;
    head->next = t;
}

// 1.找到带头结点的双链表中data域最大的结点(最大值结点只有一个), 并将该结点移动到链表最前端.
typedef struct DLNode {
    int             data;
    struct DLNode*  prior;
    struct DLNode*  next;
} DLNode;
typedef DLNode* DLinkList;

void moveMax(DLinkList head) {
    int max = head->next->data;
    DLNode* p = head->next;
    DLNode* q = head->next;
    while (p != nullptr) {
        if (max < p->data) {
            max = p->data;
            q = p;
        }
        p = p->next;
    }
    // 错误 : 没有考虑q为尾结点的情况
    // q->prior->next = q->next;
    // q->next->prior = q->prior;
    // 正确 : 如下
    DLNode* l = q->prior;
    DLNode* r = q->next;
    l->next = r;
    if (r != nullptr) {
        r->prior = l;
    }

    q->next = head->next;
    head->next->prior = q;
    head->next = q;
    q->prior = head;
}

// 查找单词的公共后缀结点
LNode* findFirstCommon(LNode* str_1, LNode* str_2) {
    int len_1 = 0, len_2 = 0;
    LNode* p = str_1->next;
    LNode* q = str_2->next;
    while (p != nullptr) {
        ++len_1;
        p = p->next;
    }
    while (q != nullptr) {
        ++len_2;
        q = q->next;
    }
    for (p = str_1->next; len_1 > len_2; --len_1) {
        p = p->next;
    }
    for (q = str_2->next; len_1 < len_2; --len_2) {
        q = q->next;
    }
    while (p != nullptr && p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}

int main(void) {

    return EXIT_SUCCESS;
}