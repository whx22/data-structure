// 逆序打印（无头节点）单链表L

#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

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

void sequentialPrintLinkList(const LinkList& head) {
    LinkNode* p = head;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// recursion
// 时间复杂度：O(n)
// 空间复杂度：O(n)
void reversePrintLinkList(const LinkList& head) {
    if (head != nullptr) {
        reversePrintLinkList(head->next);
        cout << head->data << endl;
    }
}

void test_1(void) {
    LinkList head;
    createLinkListR(head);
    cout << "Sequential print link list" << endl;
    sequentialPrintLinkList(head->next);
    cout << "Reverse print link list" << endl;
    reversePrintLinkList(head->next);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}