#include "biTreeHead.h"

// 计算二叉树的结点总数（递归）
int NodeCourt(BiTree T) {
    if (T == NULL) { 
        return 0;
    }
    else {
        return NodeCourt(T->lchild) + NodeCourt(T->rchild) + 1;
    }
}

// 计算二叉树的叶子结点数（递归）
int leafCourt(BiTree T) {
    // 两个基线条件
    if (T == NULL) {
        return 0;   // 空树返回0
    }
    if (T->lchild == NULL && T->rchild == NULL) { 
        return 1;   // 叶子节点返回1    
    }
    else {
        return NodeCourt(T->lchild) + NodeCourt(T->rchild);
    }
}