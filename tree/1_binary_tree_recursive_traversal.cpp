// binary tree recursive traversal
#include <iostream>
using namespace std;

typedef struct BTNode {
    int data;
    struct BTNode* lChild;
    struct BTNode* rChild;
} BTNode;
typedef BTNode* BinaryTree;

void visit(const BinaryTree& bt) {
    cout << bt->data << endl;
}

void recursive_traverse(const BinaryTree& bt) {
    if (bt != nullptr) {
        // visit(bt);    // 先序遍历访问时机
        recursive_traverse(bt->lChild);
        // visit(bt);    // 中序遍历访问时机
        recursive_traverse(bt->rChild);
        // visit(bt);    // 后序遍历访问时机
    }
}  