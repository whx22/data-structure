// 分解 LinkList A 分解为 LinkList A 存放 奇数节点 LinkNode B 存放 偶数节点
// linkList_odd_even

#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;
typedef LinkNode *LinkList;

void createLinkList(LinkList &head, int Arr[], const int& length) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode *r = head;    // 维护尾节点指针
    LinkNode *p = nullptr; // 维护新创建并需插入的节点指针
    for (int i = 0; i < length; ++i) {
        p = new LinkNode;
        p->data = Arr[i];
        p->next = nullptr;
        r->next = p;
        r = p;
    }
}

void printLinkList(const LinkList &head) {
    LinkNode *p = head->next;   // 遍历数据域指针
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

void classifyLinkList(LinkList &head_A, LinkList &head_B) {
    LinkNode *p = head_A;   // 遍历指针
    head_B = new LinkNode;
    head_B->next = nullptr;
    LinkNode *r = head_B;   // 维护偶节点链表尾指针
    LinkNode *q = nullptr;  // 维护需要重新分类的指针
    while (p->next != nullptr) {
        if ((p->next->data) % 2 == 0) {
            q = p->next;
            p->next = q->next;
            q->next = nullptr;
            r->next = q;
            r = q;
        }
        else {
            p = p->next;
        }
    }
}

int main(void) {
    int Arr[10] = {1, 3, 5, 7, 8, 6, 9, 7, 4, 6};
    int length = 10;
    LinkList head_A;
    LinkList head_B;
    createLinkList(head_A, Arr, length);
    cout << "Before classify" << endl;
    cout << "LinkList A : " << endl;
    printLinkList(head_A);
    
    // 以下语句段错误：B为单链表（但还未建立其头节点）
    // cout << "LinkList B : " << endl;
    // printLinkList(head_B);

    classifyLinkList(head_A, head_B);
    cout << "After classify" << endl;
    cout << "LinkList A : " << endl;
    printLinkList(head_A);
    cout << "LinkList B : " << endl;
    printLinkList(head_B);

    return EXIT_SUCCESS;
}