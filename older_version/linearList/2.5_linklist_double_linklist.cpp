// 查找双链表中的最大值并将最大值节点插入到双链表的表头

#include <iostream>
using namespace std;

typedef struct DLNode {
    int data;
    struct DLNode* llink;
    struct DLNode* rlink;
} DLNode;
typedef DLNode* DLList;

void maxFirst(DLList& head) {
    DLNode* p = nullptr;    // 查找最大值遍历指针
    DLNode* q = nullptr;    // 记录最大值节点指针
    p = q = head->rlink;
    int max = p->data;
    // find maximum
    while (p != nullptr) {
        if (max < p->data) {
            max = p->data;
            q = p;
        }
        p = p->rlink;
    }
    // 重新链接maximum节点的前驱后继（注意没有后继的情况）
    DLNode* l = q->llink;
    DLNode* r = q->rlink;
    l->rlink = q->rlink;
    if (r != nullptr) { // 若maximum节点存在后继节点
        r->llink = q->llink;
    }
    // 将maximum节点插入头部
    q->rlink = head->rlink;
    head->rlink->llink = q;
    head->rlink = q;
    q->llink = head;
}

int main(void) {
    return EXIT_SUCCESS;
}