//二叉树的层次遍历算法（应用队列）

#include "biTreeHead.h"
#include "queue.h"

Status LevelOrder(BiNode *b) {
    BiNode *p;
    SeqQueue Q;
    InitQueue(Q);
    EnQueue(Q, b->data);    // 根节点入队
    while (!QueueEmpty(Q)) {    // 队不为空，则进行循环
        DelQueue(Q, p->data);       // 出队结点p
        printf("%d\t", p->data);    // 访问p结点
        if (p->lchild != NULL) { EnQueue(Q, p->lchild->data); } // 存在右孩子时将其进队
        if (p->rchild != NULL) { EnQueue(Q, p->rchild->data); } // 存在左孩子时将其进队
    }
}