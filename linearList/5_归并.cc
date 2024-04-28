#include <iostream>
using namespace std;

// 有序顺序表的归并
void mergeArray(int a[], int m, int b[], int n, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < m) {
        c[k++] = a[i++];
    }
    while (j < n) {
        c[k++] = b[j++];
    }
}

typedef struct LNode {
    int             data;
    struct LNode*   next;
} LNode;
typedef LNode* LinkList;

// 带头结点有序链表归并为正序链表
void mergeLinkList(LinkList A, LinkList B, LinkList& C) {
    LNode* p = A->next;
    LNode* q = B->next;
    LNode* r = nullptr;
    C = A;
    C->next = nullptr;
    r = C;
    delete B;
    while (p != nullptr && q != nullptr) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
            r = r->next;
        } else {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    if (p != nullptr) {
        r->next = p;
    }
    if (q != nullptr) {
        r->next = q;
    }
}

// 带头结点有序链表归并为逆序链表
void mergeLinkListReverse(LinkList A, LinkList B, LinkList& C) {
    LNode* p = A->next;
    LNode* q = B->next;
    C = A;
    C->next = nullptr;
    delete B;
    LNode* t = C;
    while (p != nullptr && q != nullptr) {
        if (p->data <= q->data) {
            t = p;
            p = p->next;
            t->next = C->next;
            C->next = t;
        } else {
            t = q;
            q = q->next;
            t->next = C->next;
            C->next = t;
        }
    }
    while (p != nullptr) {
        t = p;
        p = p->next;
        t->next = C->next;
        C->next = t;
    }
    while (q != nullptr) {
        t = q;
        q = q->next;
        t->next = C->next;
        C->next = t;
    }
}

int main(void) {

    return EXIT_SUCCESS;
} 