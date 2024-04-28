#include "head.h"


//查找元素类型定义
typedef struct  
{
    KeyType key;    //关键字域
    //......    //其他域
}ElemType;

//定义查找二叉排序树结构
typedef struct BinarySearchTreeNode
{
    ElemType data;  //数据域
    BinarySearchTreeNode *lchild, *rchild;  //左孩子域、右孩子域
}BinarySearchTreeNode, *BinarySearchTree;

//定义二叉排序树BST
BinarySearchTree BST;

//1.二叉排序树的递归查找
BinarySearchTree SearchBST(BinarySearchTree BST, KeyType key)
{
    //基线条件：结点为NULL或结点的值等于key，返回当前结点
    if ((BST == NULL) || (key == BST->data.key)) return BST;
    
    //递归条件
    else
    {
        //key小于当前节点的值，在左子树中继续查找
        if (key < BST->data.key)
        {
            return SearchBST(BST->lchild, key);
        }
        //key大于当前节点的值，在右子树中继续查找
        else
        {
            return SearchBST(BST->rchild, key);
        }
    }
}

//2.二叉排序树的插入操作

//3.二叉排序树的生成操作

//4.二叉排序树的删除操作