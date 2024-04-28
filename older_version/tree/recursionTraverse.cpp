// 递归遍历算法，路径一样，访问时机不一样
// 时间复杂度O(n)    
// 空间复杂度O(n)   内存中栈用到的最大辅助空间
#include "biTreeHead.h"

// 二叉树先序遍历算法
Status PreOrderTraverse(BiTree T) {
    if (T == NULL) { return OK; }   // 空二叉树
    else {
        visit(T);   // 访问根节点
        PreOrderTraverse(T->lchild);    // 递归遍历左子树
        PreOrderTraverse(T->rchild);    // 递归遍历右子树
    }
}

// 二叉树中序遍历算法
Status InOrderTraverse(BiTree T) {
    if (T == NULL) { return OK; }
    else {
        InOrderTraverse(T->lchild);
        visit(T);
        InOrderTraverse(T->rchild);
    }
}

// 二叉树后序遍历算法
Status PostOrderTraverse(BiTree T) {
    if (T == NULL) { return OK; }
    else {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T);
    }
}