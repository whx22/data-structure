// Reverse LinkList Algorithm

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

// FunctionName : reverseLinkList
// Description : 带头节点单链表逆置  
void reverseLinkList(LinkList& head) {
    LinkNode* p = head;     // 维护单链表开始逆置节点
    LinkNode* q = head;     // 维护head单链表的尾节点
    LinkNode* t = nullptr;  // 维护当前需要交换的节点
    while (q->next != nullptr) {
        q = q->next;
    }
    while (p->next != q) {
        t = p->next;
        p->next = t->next;
        t->next = q->next;
        q->next = t;
    }
}

void test_1(void) {
    LinkList head;
    CreateLinkListR(head);
    cout << "Before reverse" << endl;
    printLinkList(head);
    
    reverseLinkList(head);

    cout << "After reverse" << endl;
    printLinkList(head);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}