//  二叉链表存储结构
//  一个数据域，两个指针域（分别存储两个后继节点的地址）
//  n个结点的二叉链表中，有2n个指针域（2 * n）
//  有（n - 1）个结点存放的指针不为空（根节点的没有前驱）
//  则有（n + 1）个空指针域（2 * n - (n - 1) == n + 1）


#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;  // 根据情况定义元素类型

typedef struct BiNode {
    TElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

// 三叉链表
// 一个数据域，三个指针域（分别存储一个前驱和两个后继节点的地址）
typedef struct TriTNode {
    TElemType data;
    struct TriTNode *parents, *lchild, *rchild;
}TriTNode, *TriTree;