// 复制二叉树（递归）

#include "biTreeHead.h"

Status CopyBiTree(const BiTree& T, BiTree& NewT) {
    if (T == NULL) {
        NewT = NULL;
        return 0;   // 递归基线条件
    }
    else {
        NewT = new BiNode;
        NewT->data = T->data;
        // 递归复制左右子树
        CopyBiTree(T->lchild, NewT->lchild);
        CopyBiTree(T->rchild, NewT->rchild);
    }
    return OK;
}