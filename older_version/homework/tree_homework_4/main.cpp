#include "head.h"

// 0.访问结点
void Visit(BiTree T)
{
    printf("%c\t", T->data);
}

// 1.先序构建二叉树
Status CreateBiTree(BiTree &T)
{
    TElemType ch;
    ch = getchar();

    if (ch == '#')//空结点
        T = NULL; 
    else          //非空结点
    {
        if (!(T = (BiNode *)malloc(sizeof(BiNode)))) //非空结点分配空间
            exit(OVERFLOW);                          //内存不够

        T->data = ch; //非空结点赋值

        //递归建立左右子树
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

// 2.1递归先序遍历二叉树
Status PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return OK; //空二叉树
    else
    {
        Visit(T);                    //访问根节点
        PreOrderTraverse(T->lchild); //递归遍历左子树
        PreOrderTraverse(T->rchild); //递归遍历右子树
    }
    return OK;
}

// 2.2递归中序遍历二叉树
Status InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return OK;
    else
    {
        InOrderTraverse(T->lchild);
        Visit(T);
        InOrderTraverse(T->rchild);
    }
    return OK;
}

// 2.3递归后序遍历二叉树
Status PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return OK;
    else
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        Visit(T);
    }
    return OK;
}

// 3.1非递归先序遍历二叉树
Status PreOrderTraverse2(BiTree T)
{
    BiNode *p = T;
    SeqStack S;
    InitStack(S);
    Push(S, p);
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Visit(p);
            Push(S, p);
            p = p->lchild;
        }  
        else
        {
            BiNode *q;
            Pop(S, q);
            p = q->rchild;
        }
    }
    return OK;
}

// 3.2非递归中序遍历二叉树
Status InOrderTraverse2(BiTree T)
{
    BiNode *p = T;  //使用p指针遍历树T，初始位置为根节点
    SeqStack S;
    InitStack(S);
    while (p || !StackEmpty(S)) //当前节点不为空且栈S不为空，继续循环
    {
        //p不为空，p进栈，p指向p的左子树，直到p为空，到当前树的最左端
        if (p)  
        {
            Push(S, p);
            p = p->lchild;
        }

        //p为空，栈顶元素（当前p的双亲）出栈并访问，
        //然后p指向其的右子树，对右子树进行外层相同操作
        else    
        {
            BiNode *q;
            Pop(S, q);
            Visit(q);
            p = q->rchild;
        }
    }
    return OK;
}


// 3.3.1非递归后序遍历二叉树
Status PostOrderTraverse2(BiTree T)
{
    BiNode *p = T, *q = NULL;
    BiNode **S;
    int top = 0;
    S = (BiNode **)malloc(sizeof(BiNode*) * MAXSIZE);

    while (p || top) //当前节点不为空且栈S不为空，继续循环
    {
        //p不为空，p进栈，p指向p的左子树，直到p为空，到当前树的最左端
        while (p) {top++; S[top] = p; p = p->lchild;}

        if (top > 0)
        {
            //将p置为当前（栈顶元素）需要判断处理的元素
            p = S[top];

            //无右孩子，或右孩子已经访问，（当前子树仅剩下根节点未访问），可以访问根节点
            if ((p->rchild == NULL) || (p->rchild == q))
            {
                Visit(p);   //访问根结点
                q = p;      
                //记录该次访问的结点（下一次访问的前驱结点）

                top--;      //当前节点出栈
                
                p = NULL;   
                //将p置为NULL
                //以直接跳转至p = S[top]语句，判断处理的下一个栈中元素
                //防止p再次指向当前树的最左端，对左子树重复访问
            }

            //然后p指向其的右子树，对右子树进行外层相同操作
            else 
            {
                p = p->rchild;
            }
        }
    }
    free(S);
    return OK;
}

int main(void)
{
    BiTree T;
    printf("请输入二叉树的结点数据（空结点用'#'代替）：");
    CreateBiTree(T);
    printf("\n递归先序遍历结果：\t");
    PreOrderTraverse(T);
    printf("\n递归中序遍历结果：\t");
    InOrderTraverse(T);
    printf("\n递归后序遍历结果：\t");
    PostOrderTraverse(T);
    printf("\n非递归先序遍历结果：\t");
    PreOrderTraverse2(T);
    printf("\n非递归中序遍历结果：\t");
    InOrderTraverse2(T);
    printf("\n非递归后序遍历结果：\t");
    PostOrderTraverse2(T);

    system("pause");
    return 0;
}