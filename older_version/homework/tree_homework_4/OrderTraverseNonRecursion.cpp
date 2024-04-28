#include "head.h"

void Visit(BiTree T);
Status CreateBiTree(BiTree &T);
Status PreOrderTraverseNonRecursion_1(BiTree T);
Status PreOrderTraverseNonRecursion_2(BiTree T);
Status InOrderTraverseNonRecursion_1(BiTree T);
Status PostOrderTraverseNonRecursion_1(BiTree T);
Status PostOrderTraverseNonRecursion_2(BiTree T);

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


// 2.1非递归先序遍历1
Status PreOrderTraverseNonRecursion_1(BiTree T)
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


/*
2.2非递归先序遍历2（元素栈法）
根节点出栈，右孩子入栈，左孩子入栈（左孩子比右孩子先访问）
*/
Status PreOrderTraverseNonRecursion_2(BiTree T)
{
    if (T != NULL)
    {
        //初始化一个栈
        BiNode *Stack[MAXSIZE];
        int top = -1;

        BiNode *p = NULL;   //遍历指针p
        Stack[++top] = T;   //root结点Push栈
        
        while (top != -1)
        {
            //栈顶结点Pop栈并访问
            p = Stack[top--];   
            Visit(p);

            //栈顶元素有孩子结点，按照孩子结点的右左顺序push进栈;
            if (p->rchild != NULL)
            {
                Stack[++top] = p->rchild;
            }
            if (p->lchild != NULL)
            {
                Stack[++top] = p->lchild;
            }
        }
    }
    return OK;
}

// 3.1非递归中序遍历二叉树1
Status InOrderTraverseNonRecursion_1(BiTree T)
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

// 4.1非递归后序遍历1
Status PostOrderTraverseNonRecursion_1(BiTree T)
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

            //无右孩子，或右孩子已经访问
            //可以访问当前节点
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


/*
4.2非递归后序遍历2
先用两个栈实现（逆后序序列），（栈2中结点顺序：根节点、右子树、左子树）
依此弹出栈2元素并访问（后续序列）

伪代码如下：
    初始化S1的top元素是树的根结点;
    while(top1 != -1) {
        将栈顶元素push到S2;
        if(栈顶元素有孩子结点)
        {
            按照孩子结点的左右顺序push进S1;
        } 
    }
    循环逐个弹出S2的栈顶元素

*/
Status PostOrderTraverseNonRecursion_2(BiTree T)
{
    //树不为空，进行遍历
    if (T != NULL)
    {
        //初始化两个栈
        BiNode *Stack1[MAXSIZE]; int top1 = -1; //中转栈S1
        BiNode *Stack2[MAXSIZE]; int top2 = -1; //逆后续栈S2
        
        
        BiNode *p = NULL;   //遍历指针p
        Stack1[++top1] = T; //先将root结点压入S1
        while (top1 != -1)
        {
            //将栈顶元素push到S2;
            p = Stack1[top1--];
            Stack2[++top2] = p;

            //栈顶元素有孩子结点，按照孩子结点的左右顺序push进S1;
            if (p->lchild != NULL)
            {
                Stack1[++top1] = p->lchild;
            }
            if (p->rchild != NULL)
            {
                Stack1[++top1] = p->rchild;
            }
        }

        //逐个PopS2的栈顶元素
        while (top2 != -1)
        {
            p = Stack2[top2--];
            Visit(p);
        }
    }
    return OK;
}

int main(void)
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverseNonRecursion_1(T);
    putchar('\n');
    PreOrderTraverseNonRecursion_2(T);
    putchar('\n');
    InOrderTraverseNonRecursion_1(T);
    putchar('\n');
    PostOrderTraverseNonRecursion_1(T);
    putchar('\n');
    PostOrderTraverseNonRecursion_2(T);
    return 0;
}