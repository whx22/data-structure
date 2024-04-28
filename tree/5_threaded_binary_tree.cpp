// threaded binary tree
#include <iostream>
using namespace std;

typedef struct TBTNode {
    int data;
    int lTag;   // Tag == 0 : 表示存储左右子树结点
    int rTag;   // Tag == 1 : 表示存储前驱后继线索结点
    struct TBTNode* lChild;
    struct TBTNode* rChild;
} TBTNode;
typedef TBTNode* ThreadedBinaryTree;

// 中序线索二叉树索引化
void inTreaded(ThreadedBinaryTree& tbt, TBTNode* pre = nullptr) {
    if (tbt != nullptr) {
        inTreaded(tbt->lChild, pre);
        if (tbt->lChild == nullptr) {
            tbt->lChild = pre;
            tbt->lTag = 1;
        }
        if (pre != nullptr && pre->rChild == nullptr) {
            pre->rChild = tbt;
            pre->rTag = 1;
        }
        pre = tbt;
        inTreaded(tbt->rChild, pre);
    }
}

// 前序线索二叉树索引化
void preTreaded(ThreadedBinaryTree& tbt, TBTNode* pre = nullptr) {
    if (tbt != nullptr) {
        if (tbt->lChild == nullptr) {
            tbt->lChild = pre;
            tbt->lTag = 1;
        }
        if (pre != nullptr && pre->rChild == nullptr) {
            pre->rChild = tbt;
            pre->rTag = 1;
        }
        pre = tbt;
        if (tbt->lTag == 0) {
            preTreaded(tbt->lChild, pre);
        }
        if (tbt->rTag == 0) {
            preTreaded(tbt->rChild, pre);
        }
    }
}

// 前序遍历(通过前序线索二叉树)
void visit(const ThreadedBinaryTree& tbt) {
    cout << tbt->data << endl;
}

void preOrder(ThreadedBinaryTree& tbt) {
    if (tbt != nullptr) {
        TBTNode* p = tbt;
        while (p != nullptr) {
            while (p->lTag == 0) {
                visit(p);
                p = p->lChild;
            }
            visit(p);
            p = p->rChild;
        }
    }
}

// 后序线索二叉树索引化
void postThreaded(ThreadedBinaryTree& tbt, TBTNode* pre) {
    if (tbt != nullptr) {
        postThreaded(tbt->lChild, pre);
        postThreaded(tbt->rChild, pre);
        if (tbt->lChild == nullptr) {
            tbt->lChild = pre;
            tbt->lTag = 1;
        }
        if (pre != nullptr && pre->rChild == nullptr) {
            pre->rChild = tbt;
            pre->rTag = 1;
        }
        pre = tbt;
    }
}