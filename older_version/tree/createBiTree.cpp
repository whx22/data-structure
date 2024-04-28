// 先序建立二叉树（使用递归）
// 问题：根据先序序列无法确定唯一形式的树
// 解决：补充空结点，确定唯一形式二叉树（空结点使用特殊符号表示，例如'#'或' '）
// 注意：scanf不读入' '

#include "biTreeHead.h"

Status CreateBiTree(BiTree& T) {
    char ch;    // T二叉树的数据域为char型时
    cin >> ch;
    if (ch == '#') {    // 空结点
        T = NULL; 
    }    
    else {  // 非空结点
        if (!(T = (BiNode *)malloc(sizeof(BiNode)))) {  // 非空结点分配空间
            exit(OVERFLOW); // 内存不够
        }
        // 疑问：T->data为int型（二叉树的定义），赋值为char型
        T->data = ch;   // 非空结点赋值
        // 递归建立左右子树
        CreateBiTree(T->lchild);    
        CreateBiTree(T->rchild);
    }
    return OK;
}