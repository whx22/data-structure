#include "head.h"

// 0.���ʽ��
void Visit(BiTree T)
{
    printf("%c\t", T->data);
}

// 1.���򹹽�������
Status CreateBiTree(BiTree &T)
{
    TElemType ch;
    ch = getchar();

    if (ch == '#')//�ս��
        T = NULL; 
    else          //�ǿս��
    {
        if (!(T = (BiNode *)malloc(sizeof(BiNode)))) //�ǿս�����ռ�
            exit(OVERFLOW);                          //�ڴ治��

        T->data = ch; //�ǿս�㸳ֵ

        //�ݹ齨����������
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

// 2.1�ݹ��������������
Status PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return OK; //�ն�����
    else
    {
        Visit(T);                    //���ʸ��ڵ�
        PreOrderTraverse(T->lchild); //�ݹ����������
        PreOrderTraverse(T->rchild); //�ݹ����������
    }
    return OK;
}

// 2.2�ݹ��������������
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

// 2.3�ݹ�������������
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

// 3.1�ǵݹ��������������
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

// 3.2�ǵݹ��������������
Status InOrderTraverse2(BiTree T)
{
    BiNode *p = T;  //ʹ��pָ�������T����ʼλ��Ϊ���ڵ�
    SeqStack S;
    InitStack(S);
    while (p || !StackEmpty(S)) //��ǰ�ڵ㲻Ϊ����ջS��Ϊ�գ�����ѭ��
    {
        //p��Ϊ�գ�p��ջ��pָ��p����������ֱ��pΪ�գ�����ǰ���������
        if (p)  
        {
            Push(S, p);
            p = p->lchild;
        }

        //pΪ�գ�ջ��Ԫ�أ���ǰp��˫�ף���ջ�����ʣ�
        //Ȼ��pָ������������������������������ͬ����
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


// 3.3.1�ǵݹ�������������
Status PostOrderTraverse2(BiTree T)
{
    BiNode *p = T, *q = NULL;
    BiNode **S;
    int top = 0;
    S = (BiNode **)malloc(sizeof(BiNode*) * MAXSIZE);

    while (p || top) //��ǰ�ڵ㲻Ϊ����ջS��Ϊ�գ�����ѭ��
    {
        //p��Ϊ�գ�p��ջ��pָ��p����������ֱ��pΪ�գ�����ǰ���������
        while (p) {top++; S[top] = p; p = p->lchild;}

        if (top > 0)
        {
            //��p��Ϊ��ǰ��ջ��Ԫ�أ���Ҫ�жϴ����Ԫ��
            p = S[top];

            //���Һ��ӣ����Һ����Ѿ����ʣ�����ǰ������ʣ�¸��ڵ�δ���ʣ������Է��ʸ��ڵ�
            if ((p->rchild == NULL) || (p->rchild == q))
            {
                Visit(p);   //���ʸ����
                q = p;      
                //��¼�ôη��ʵĽ�㣨��һ�η��ʵ�ǰ����㣩

                top--;      //��ǰ�ڵ��ջ
                
                p = NULL;   
                //��p��ΪNULL
                //��ֱ����ת��p = S[top]��䣬�жϴ������һ��ջ��Ԫ��
                //��ֹp�ٴ�ָ��ǰ��������ˣ����������ظ�����
            }

            //Ȼ��pָ������������������������������ͬ����
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
    printf("������������Ľ�����ݣ��ս����'#'���棩��");
    CreateBiTree(T);
    printf("\n�ݹ�������������\t");
    PreOrderTraverse(T);
    printf("\n�ݹ�������������\t");
    InOrderTraverse(T);
    printf("\n�ݹ������������\t");
    PostOrderTraverse(T);
    printf("\n�ǵݹ�������������\t");
    PreOrderTraverse2(T);
    printf("\n�ǵݹ�������������\t");
    InOrderTraverse2(T);
    printf("\n�ǵݹ������������\t");
    PostOrderTraverse2(T);

    system("pause");
    return 0;
}