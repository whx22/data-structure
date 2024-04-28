// 图的存储结构
// 2.链式存储结构：邻接表

#ifndef _GRAPH_STRUCT_DEFINE_2
#define _GRAPH_STRUCT_DEFINE_2

// c库头文件
#include <stdio.h>
#include <stdlib.h>

// 函数返回类型定义
#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0
typedef int Status;

#define MAX_VERTEX_NUM 100  // 最大节点数定义

typedef char VertexType;    // 顶点的数据类型
typedef int  ArcType;       // 边的权值类型
typedef int  OtherInfo;     // 边的其他信息（例如：权值）

// 顶点的顺序结构表定义
typedef struct VertexNode {
    VertexType data;        // 顶点信息
    ArcNode*   first_arc;   // 指向第一条依附该结点的指针
} VertexNode, AdjacencyList[MAX_VERTEX_NUM];
// VertexNode为邻接表顶点节点类型
// AdjacencyList[MAX_VERTEX_NUM]为邻接表顶点数组类型

// 边结点的定义
typedef struct ArcNode {
    int       AdjacencyVertexIndex; // 边结点所指向元素在邻接表中的索引
    ArcNode*  next_arc;             // 指向下一条边结点
    OtherInfo info;                 // 边的其他信息（例如：权值）
} ArcNode;
// ArcNode为邻接表边节点类型

// 图的邻接表存储
typedef struct {
    AdjacencyList vertices; // 邻接表 
    int vertex_num;         // 图当前顶点数
    int arc_num;            // 图当前弧数
} AdjacencyListGraph;


// 2.1.采用邻接表建立无向网

// 2.1.0补充依赖算法：
// 在图中查找顶点v对应的下标，找到返回下标值，否则返回-1
int LocateVertex(AdjacencyListGraph G, VertexType v) {
    for (int i = 0; i < G.vertex_num; ++i) {
        if (v == G.vertices[i].data) {
            return i;
        }
    }
    return -1;
}

// 2.1.采用邻接表建立无向网
Status CreateUndirectedNet(AdjacencyListGraph &G) {
    scanf("%d%d", &G.vertex_num, &G.arc_num);   // 输入总顶点数，总边数

    // 依次输入顶点信息，构造表头结点数组
    for (int i = 0; i < G.vertex_num; i++) {
        scanf("%c", &G.vertices[i].data);   // 输入顶点值
        G.vertices[i].first_arc = NULL;     // 初始化表头结点的指针域
    }

    // 输入各边信息，构造邻接表
    for (int k = 0; k < G.arc_num; k++) {
        // 输入一条边所以依附的两个顶点，可添加边的其他信息（例如：权值）
        char vertex1, vertex2;
        scanf("%c%c", &vertex1, &vertex2);

        // 找出vertex1，vertex2在图中的下标（序号）
        int i = LocateVertex(G, vertex1);
        int j = LocateVertex(G, vertex2);

        // 生成一个边结点
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->AdjacencyVertexIndex = j;   // 索引为i的邻接点的索引为j
        // 头插法插入索引为i表头结点
        p1->next_arc = G.vertices[i].first_arc;
        G.vertices[i].first_arc = p1;

        // 生成对应的边结点（原因：无向图对称邻接）
        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->AdjacencyVertexIndex = i;   // 索引为j的邻接点的索引为j
        p2->next_arc = G.vertices[j].first_arc;
        G.vertices[j].first_arc = p2;
    }
    return OK;
}

#endif