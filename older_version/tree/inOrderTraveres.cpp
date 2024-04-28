// 遍历二叉树的非递归算法
// 中序遍历非递归算法
// 用栈实现递归

#include "biTreeHead.h"
#include "stack.h"

Status InOrderTraverse(BiTree T) {
    BiNode *p = T;  // 使用p指针遍历树T，初始位置为根节点
    SeqStack S;
    InitStack(S);
    while (p || !StackEmpty(S)) {   // 当前节点不为空且栈S不为空，继续循环
        // p不为空，p进栈，p指向p的左子树，直到p为空
        if (p) {
            Push(S, p->data);
            p = p->lchild;
        }
        // p为空，栈顶元素（当前p的双亲）出栈并访问，
        // 然后p指向栈顶元素（当前p的双亲）的右子树
        else {
            BiNode *q;
            Pop(S, q->data);
            printf("%d\t", q->data);
            p = q->rchild;
        }
    }
    return OK;
}