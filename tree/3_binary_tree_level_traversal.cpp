// binary tree level traversal
#include <iostream>
using namespace std;
#include "my_queue.hpp"

typedef struct BTNode {
    int data;
    struct BTNode* lChild;
    struct BTNode* rChild;
} BTNode;
typedef BTNode* BinaryTree;

void visit(const BinaryTree& bt) {
    cout << bt->data << endl;
}

void levelTraversal(const BinaryTree& bt) {
    if (bt != nullptr) {
        Queue<BinaryTree> assist_queue;
        BTNode* p = nullptr;
        assist_queue.enter(bt);
        while (!assist_queue.is_empty()) {
            p = assist_queue.exit();
            visit(p);
            if (p->lChild != nullptr) {
                assist_queue.enter(p->lChild);
            }
            if (p->rChild != nullptr) {
                assist_queue.enter(p->rChild);
            }
        }
    }
}