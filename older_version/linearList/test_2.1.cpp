#include <iostream>
#include <stdexcept>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

// 带头结点单链表 打印
void printLinkList(const LinkList& head) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// 带头结点单链表 头插法
void createLinkListH(LinkList& head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* p = nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = head->next;
        head->next = p;
    }
}

// 带头结点单链表 尾插法
void createLinkListR(LinkList& head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* r = head;
    LinkNode* p = nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = nullptr;
        r->next = p;
        r = p;
    }
}

// 不带头结点单链表 打印
void printNoHeadLinkList(const LinkList& head) {
    LinkNode* p = head;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// 不带头结点单链表 头插法
void createNoHeadLinkListH(LinkList& head) {
    head = nullptr;
    LinkNode* p = nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        p = new LinkNode;
        cin >> p->data;
        if (head == nullptr) {
            p->next = nullptr;
            head = p;
        }
        else {
            p->next = head;
            head = p;
        }
    }
}

// 不带头结点单链表 尾插法
void createNoHeadLinkListR(LinkList& head) {
    head = nullptr;
    LinkNode* r = head;
    LinkNode* p = nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = nullptr;
        if (head == nullptr) {
            head = p;
            r = p;
        }
        else {
            r->next = p;
            r = p;
        }
    }
}

void test_1(void) {
    LinkList head = nullptr;
    // createLinkListH(head);
    createLinkListR(head);
    printLinkList(head);
}

void test_2(void) {
    LinkList head = nullptr;
    // createNoHeadLinkListH(head);
    createNoHeadLinkListR(head);
    printNoHeadLinkList(head);
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}