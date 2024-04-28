// 图的存储结构
// 1.借助二维数组表示元素间的关系：邻接矩阵

#ifndef _GRAPH_STRUCT_DEFINE_1
#define _GRAPH_STRUCT_DEFINE_1

// c库头文件
#include <stdio.h>
#include <stdlib.h>

// 函数返回类型定义
#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0
typedef int Status;

// 1.借助二维数组表示元素间的关系：邻接矩阵
#define MAX_INT        32767   // 网的最大权值定义，及无穷大
#define MAX_VERTEX_NUM 100     // 最大节点数定义

typedef char VertexType;    // 顶点的数据类型
typedef int  ArcType;       // 边的权值类型

typedef struct {
    VertexType  vertex[MAX_VERTEX_NUM];                 // 顶点表
    ArcType     arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   // 邻接矩阵
    int vertex_num; // 图当前的顶点数
    int arc_num;    // 图当前的边数
} AdjacencyMatrixGraph;  // 邻接矩阵图


// 1.1.采用邻接矩阵表示法建立无向网

// 1.1.0补充依赖算法：
// 在图中查找顶点v对应的索引下标，找到返回下标值，否则返回-1
int LocateVertex(AdjacencyMatrixGraph G, VertexType v) {
    for (int i = 0; i < G.vertex_num; ++i) {
        if (v == G.vertex[i]) { 
            return i;
        }
    }
    return -1;
}

// 1.1.采用邻接矩阵表示法建立无向网
Status CreateUndirectedNet(AdjacencyMatrixGraph &G) {
    scanf("%d%d", &G.vertex_num, &G.arc_num);  // 输入总顶点数，总边数

    // 依次输入顶点信息
    for (int i = 0; i < G.vertex_num; i++) {
        scanf("%c", &G.vertex[i]);
    }

    // 初始化邻接矩阵
    for (int i = 0; i < G.vertex_num; i++) {
        for (int j = 0; j < G.vertex_num; j++) {
            G.arcs[i][j] = MAX_INT; // 边的权值均为无穷大
        }
    }

    // 构造邻接矩阵
    for (int k = 0; k < G.arc_num; k++) {
        // 输入一条边所以依附的两个顶点，和边的权值
        char vertex1, vertex2;
        int  weight;
        scanf("%c%c%d", &vertex1, &vertex2, &weight);

        // 找出vertex1，vertex2在图中的下标（序号）
        int i = LocateVertex(G, vertex1);
        int j = LocateVertex(G, vertex2);

        // 给边<vertex1, vertex2>的权值置为weight
        // 无向网：邻接矩阵对称
        G.arcs[i][j] = weight;
        G.arcs[j][i] = weight;
    }
    return OK;
}


#endif