// Merge LinkList Algorithm

#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;

typedef LinkNode* LinkList;

void CreateLinkListR(LinkList& head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* r = head;
    LinkNode* p = nullptr;
    int length;
    cin >> length;
    for (int i = 0; i < length; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = nullptr;
        p->next = r->next;
        r->next = p;
        r = p;
    }
}

void printLinkList(const LinkList& head) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// Sequential Merge
void mergeLinkListS(LinkList A, LinkList B, LinkList& C) {
    LinkNode* p = A->next;
    LinkNode* q = B->next;
    C = A;
    C->next = nullptr;
    delete B;
    LinkNode* r = C;    // 始终指向C链表的尾节点（便于进行尾插法）
    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else {
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

// Reverse Merge
void mergeLinkListR(LinkList A, LinkList B, LinkList& C) {
    LinkNode* p = A->next;
    LinkNode* q = B->next;
    C = A;
    C->next = nullptr;
    delete B;
    LinkNode* h = nullptr;  // 记录当前需要插入头部的节点
    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            h = p;
            p = p->next;
            h->next = C->next;
            C->next = h;
        }
        else {
            h = q;
            q = q->next;
            h->next = C->next;
            C->next = h;
        }
    }
    while (p != nullptr) {
        h = p;
        p = p->next;
        h->next = C->next;
        C->next = h;
    }
    while (q != nullptr) {
        h = q;
        q = q->next;
        h->next = C->next;
        C->next = h;
    }
}

void test_1(void) {
    LinkList head_1;
    LinkList head_2;
    CreateLinkListR(head_1);
    CreateLinkListR(head_2);
    cout << "LinkList 1 : " << endl;
    printLinkList(head_1);
    cout << "LinkList 2 :" << endl;
    printLinkList(head_2);

    LinkList head_3;
    mergeLinkListS(head_1, head_2, head_3);
    cout << "After merge LinkList 3 :" << endl; 
    printLinkList(head_3);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}