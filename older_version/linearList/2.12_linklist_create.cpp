// LinkList create
#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;

void CreateLinkListR(LinkNode*& head) {
    head = new LinkNode;
    head->next = nullptr;

    LinkNode* r = head;     // 维护尾节点
    LinkNode* p = nullptr;  // 维护创建节点
    int n;                  // 记录建表节点个数
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p = new LinkNode;
        cin >> p->data;
        p->next = r->next;
        r->next = p;
        r = p;
    }
}

void CreateLinkListH(LinkNode*& head) {
    head = new LinkNode;
    head->next = nullptr;

    LinkNode* p = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p = new LinkNode;
        p->next = nullptr;
        cin >> p->data;
        p->next = head->next;
        head->next = p; 
    }
}

void printLinkList(LinkNode* head) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main(void) {
    LinkNode* head = nullptr;
    CreateLinkListH(head);
    cout << "after build" << endl;
    printLinkList(head);

    return EXIT_SUCCESS;
}