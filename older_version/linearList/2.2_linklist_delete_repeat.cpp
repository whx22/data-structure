// Delete 递增 LinkList data域重复的节点

#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

void createLinkList(LinkList& head, int Arr[], const int& length) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* r = head;     // 维护LinkList尾节点指针
    LinkNode* p = nullptr;  // 维护创建并需要插入节点指针
    for (int i = 0; i < length; ++i) {
        p = new LinkNode;
        p->data = Arr[i];
        p->next = nullptr;
        r->next = p;
        r = p;
    }
}

void printLinkList(const LinkList& head) {
    LinkNode* p = head->next;   // data域遍历指针
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// main function
void deleteLinkList(LinkList& head) {
    LinkNode* p = head->next;   // compare遍历指针
    LinkNode* q = nullptr;      // 维护被删节点指针
    if (p == nullptr) {
        return;
    }
    while (p->next != nullptr) {
        if (p->data == p->next->data) {
            q = p->next;
            p->next = q->next;
            delete q;
        }
        else {
            p = p->next;
        }
    }
}

int main(void) {
    int Arr[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int length = 10;
    LinkList head;
    createLinkList(head, Arr, length);

    cout << "Before Delete" << endl;
    printLinkList(head);

    deleteLinkList(head);

    cout << "After Delete" << endl;
    printLinkList(head);

    return EXIT_SUCCESS;
}