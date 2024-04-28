// 查找单链表求公共后缀
// linkList_public_suffix

#include <iostream>
using namespace std;

typedef struct LinkNode {
    char data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

void printLinkList(const LinkList& head) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
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

// main function
LinkNode* findFirstCommon(LinkList& head_1, LinkList& head_2) {
    // 计算两个单链表的长度, 及单词字母个数
    int length_1 = 0;
    int length_2 = 0;
    LinkNode* p = head_1->next;
    LinkNode* q = head_2->next;
    while (p != nullptr) {
        p = p->next;
        ++length_1;
    }
    while (q != nullptr) {
        q = q->next;
        ++length_2;
    }

    // 较长的单链表的指针先走(length_1 - length_2)步, 及到达相同公共后缀长度处
    for (p = head_1->next; length_1 > length_2; --length_1) {
        p = p->next;
    }
    for (q = head_2->next; length_2 > length_1; --length_2) {
        q = q->next;
    }

    /*
     * p、q同时向后移动
     * p == q 时：找到公共后缀
     * p == nullptr && q == nullptr 时：没有公共后缀
     */ 
    while (p != nullptr && p != q) {
        p = p->next;
        q = q->next;
    }
    
    return p;   // 公共后缀结点
}

void test_1(void) {
    LinkList head_1;
    LinkList head_2;
    createLinkListR(head_1);
    createLinkListR(head_2);

    cout << "the first word is : " << endl;
    printLinkList(head_1);

    cout << "the second word is : " << endl;
    printLinkList(head_2);
}

int main(void) {
    test_1();

    return EXIT_SUCCESS;
}