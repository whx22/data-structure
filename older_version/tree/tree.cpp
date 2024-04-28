// 树的结构类型定义
// 1.双亲表示法
// 2.孩子链表
// 3.孩子兄弟表示法

#include <stdio.h>

#define MAXSIZE 100
typedef int TElemType;
// 双亲树的结构定义（顺序存储）

// 节点结构定义
typedef struct PTNode {
    TElemType data;
    int parent;     // 双亲结点下标
} PTNode;

// 树结构定义
typedef struct {
    PTNode node[MAXSIZE];
    int r, n;   // r：根节点下标，   n：节点总数
} PTree;

// 孩子链表（顺序结构 + 链式结构）

// 孩子节点结构
typedef struct CTNode {
    int child;      // 存储的树元素顺序表中该孩子下标
    CTNode *next;   // 指向下一个孩子结点
} *ChildPtr;

// 双亲结点结构
typedef struct
{
    TElemType data;         // 数据域
    ChildPtr first_child;   // 孩子链表的表头指针，若为叶子节点，则指向NULL
}CTBox;

// 树结构
typedef struct CTree {
    CTBox nodes[MAXSIZE];
    int r, n;   // r：根节点下标，   n：节点总数
} CTree;

// 孩子兄弟表示法

// 结点定义
typedef struct CSNode {
    TElemType data;
    CSNode *first_child, *next_sibling;
} CSNode, *CSTree;