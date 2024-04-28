// tree traversal
#include <iostream>
using namespace std;
#include "my_queue.hpp"

// 定义分支指向结点
typedef struct Branch {
    int child_index;
    struct Branch* next;
} Branch;

// 定义树结点
typedef struct {
    int data;
    Branch* first;
} TNode;

// 定义树表
#define SIZE
TNode tree[SIZE];

void visit(TNode* t) {
    cout << t->data << endl;
}

// tree depth-first traversal use recursion
void preOrder(TNode* root, TNode tree[]) {
    if (root != nullptr) {
        visit(root);
        Branch* p = root->first;
        while (p != nullptr) {
            preOrder(&tree[p->child_index], tree);
            p = p->next;
        }
    }
}

void postOrder(TNode* root, TNode tree[]) {
    if (root != nullptr) {
        Branch* p = root->first;
        while (p != nullptr) {
            postOrder(&tree[p->child_index], tree);
            p = p->next;
        }
        visit(root);
    }
}

// tree level traversal no recursion
void levelTraversal(TNode* root, TNode tree[]) {
    if (root != nullptr) {
        Queue<TNode*> assist_queue;
        TNode* p = nullptr;
        assist_queue.enter(root);
        while (!assist_queue.is_empty()) {
            p = assist_queue.exit();
            visit(p);
            Branch* q = p->first;
            while (q != nullptr) {
                assist_queue.enter(&tree[q->child_index]);
                q = q->next;
            }
        }
    }
}