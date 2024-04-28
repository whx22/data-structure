// 比较 表示两个集合和递增单链表 是否相等

#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

void createLinkList(LinkList& head, int arr[], int length) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* r = head;
    LinkNode* p = nullptr;
    for (int i = 0; i < length; ++i) {
        p = new LinkNode;
        p->data = arr[i];
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

bool is_compare(const LinkList& head_1, const LinkList& head_2) {
    LinkNode* p = head_1->next;
    LinkNode* q = head_2->next;

    while (p != nullptr && q != nullptr) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        }
        else {
            return false;
        }
    }
    if (p != nullptr || q != nullptr) {
        return false;
    }
    else {
        return true;
    }
}

void test_1(void) {
    int arr_1[] = {1, 2, 5, 7, 9};
    int length_1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int arr_2[] = {1, 2, 5, 7, 9, 10};
    int length_2 = sizeof(arr_2) / sizeof(arr_2[0]);
    LinkList head_1;
    LinkList head_2;
    createLinkList(head_1, arr_1, length_1);
    createLinkList(head_2, arr_2, length_2);
    cout << "link list 1 : " << endl;
    printLinkList(head_1);
    cout << "link list 1 : " << endl;
    printLinkList(head_2);

    if (is_compare(head_1, head_2)) {
        cout << "link list 1 == link list 2" << endl;
    }
    else {
        cout << "link list 1 != link list 2" << endl;
    }
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}