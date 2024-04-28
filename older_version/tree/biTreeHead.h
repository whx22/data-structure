#ifndef _HEAD_H
#define _HEAD_H

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;

//定义最大元素个数
#define MAXSIZE 100

typedef int TElemType;  // 根据情况定义元素类型

typedef struct BiNode {
    TElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void visit(BiTree T) {
    printf("%d\t", T->data);
}

#endif