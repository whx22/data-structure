// Create Link List Algorithm

#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

// 带头节点单链表 打印
void printLinkList(LinkList head) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// 带头节点单链表 头插法
void createLinkListH(LinkList& head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* p = nullptr;
    int length;
    cin >> length;
    for (int i = 0; i < length; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = head->next;
        head->next = p;
    }
}

// 带头节点单链表 尾插法
void createLinkListR(LinkList& head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* r = head;     // 维护尾节点
    LinkNode* p = nullptr;  // 接受创建新节点
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

// 不带头节点单链表 打印
void printNoHeadLinkList(const LinkList& head) {
    LinkNode* p = head;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// 不带头节点单链表 头插法
void createNoHeadLinkListH(LinkList& head) {
    head = nullptr;
    LinkNode* p = nullptr;
    int length;
    cin >> length;
    for (int i = 0; i < length; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = nullptr;
        if (head == nullptr) {
            head = p;
        }
        else {
            p->next = head;
            head = p;
        }
    }
}

// 不带头节点单链表 尾插法
void createNoHeadLinkListR(LinkList& head) {
    head = nullptr;
    LinkNode* p = nullptr;
    LinkNode* r = nullptr;
    int length;
    cin >> length;
    for (int i = 0; i < length; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = nullptr;
        if (head == nullptr) {
            head = p;
            r = head;
        }
        else {
            r->next = p;
            r = p;
        }
    }
}

void test(void) {
    LinkList head = nullptr;
    createNoHeadLinkListR(head);
    cout << "finish create" << endl;
    printNoHeadLinkList(head);
}

int main(void) {
    test();
    return EXIT_SUCCESS;
}