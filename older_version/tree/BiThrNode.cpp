// 线索二叉树结构定义
#include <stdio.h>
#include <stdlib.h>

typedef struct BiThrNode {
    int data;
    int ltag, rtag; // tag == 0：指向孩子， tag == 1：指向前驱或后继
    BiThrNode *lchild, *rchild; 
} BiThrNode, *BiThrTree;