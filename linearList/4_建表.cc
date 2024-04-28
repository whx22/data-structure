#include <iostream>
#include <exception>
using namespace std;

#define MAXSIZE 100
// 顺序表建表
typedef struct {
    int             data[MAXSIZE];
    unsigned int    length;
} SeqList;

SeqList seqList;

void createSeqList(SeqList& seqList) {
    cin >> seqList.length;
    if (seqList.length < 0 || seqList.length > MAXSIZE) {
        throw invalid_argument("error : invalid argument");
    }
    for (int i = 0; i < seqList.length; ++i) {
        cin >> seqList.data[i];
    }
}

// 链表的建表
typedef struct LNode {
    int             data;
    struct LNode*   next;
} LNode;
typedef LNode* LinkList;

// 尾插法建立带头结点的单链表
void createLinkListR(LinkList& head) {
    head = new LNode;
    head->next = nullptr;
    LNode* r = head;
    LNode* p = nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        p = new LNode;
        p->next = nullptr;
        cin >> p->data;
        // p->next = r->next;
        r->next = p;
        r = p;
    }
}

// 头插法建立带头结点的单链表
void createLinkListH(LinkList& head) {
    head = new LNode;
    head->next = nullptr;
    LNode* p = nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        p = new LNode;
        p->next = nullptr;
        cin >> p->data;
        p->next = head->next;
        head->next = p;
    }
}

// 建立不含重复元素的单链表
bool find(LinkList head, char ch) {
    LNode* p = head->next;
    while (p != nullptr) {
        if (p->data == ch) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void createLinkListNoSameElem(LinkList& head) {
    head = new LNode;
    head->next = nullptr;
    LNode* p = nullptr;
    int num;
    cin >> num;
    char ch;
    for (int i = 0; i < num; ++i) {
        cin >> ch;
        if (find(head, ch)) {
            continue;
        } else {
            p = new LNode;
            p->data = ch;
            p->next = head->next;
            head->next = p;
        }
    }
}

int main(void) {
    return EXIT_SUCCESS;
}