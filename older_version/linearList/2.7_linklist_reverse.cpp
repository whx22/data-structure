// 逆置链表（要求不能建立新节点）

#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

void printLinkList(const LinkList& head) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

void createLinkListR(LinkList& head) {
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

void reverseLinkList(LinkList& head) {
    LinkNode* p = head->next;
    LinkNode* q = nullptr; 
    head->next = nullptr;
    while (p != nullptr) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

void test(void) {
    LinkList head;
    createLinkListR(head);
    cout << "Before reverse" << endl;
    printLinkList(head);
    reverseLinkList(head);
    cout << "After reverse" << endl;
    printLinkList(head);
}

int main(void) {
    test();
    return EXIT_SUCCESS;
}