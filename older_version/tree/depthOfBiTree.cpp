// 计算二叉树的深度
#include "biTreeHead.h"

int DepthOfBiTree(BiTree T) {
    if (T == NULL) {    // 空树返回0（基线条件）
        return 0;
    }    
    else {
        int m = DepthOfBiTree(T->lchild);
        int n = DepthOfBiTree(T->rchild);
        return (m > n? (m + 1) : (n + 1));
    }
}