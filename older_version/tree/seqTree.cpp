//  二叉树的顺序存储
//  实现：按满二叉树的结点层次编号，依次存放二叉树的元素
//  双亲结点和孩子节点的序号可根据二叉树的性质五求出
//  结点的前驱与后继的关系直接蕴含在存储位置中
//  适合于满二叉树和完全二叉树，对于存储右单支树浪费空间

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100     // 定义顺序树最大容量
typedef int TElemType;  // 根据情况定义元素类型

//  二叉树顺序存储表示
typedef TElemType SeqBiTree[MAXSIZE];   // 定义顺序树的结构类型
SeqBiTree bt;   // 声明bt顺序树