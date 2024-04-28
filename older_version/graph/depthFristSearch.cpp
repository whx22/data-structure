// 深度优先遍历————DFS
#include "graph_struct_define_matrix.h"
#include "graph_struct_define_list.h"


// 1.邻接矩阵表示的无向图深度优先遍历（递归）：类似于树的先根遍历（系统栈）
#include <stdbool.h>
#define graph_vertex_num 9          // 需要遍历的图的结点总数
bool visited[graph_vertex_num] = { FALSE };
// 辅助数组：记录以访问结点，初始化为FALSE，以访问标记TRUE

void DFS(AdjacencyMatrixGraph G, int v) {   // 参数图，起始顶点 
    printf("%d", v);    // 访问该结点（访问方式：根据需求）
    visited[v] = TRUE;  // 以访问标记TRUE

    for (int w = 0; w < G.vertex_num; w++) {        // 依次检查邻接矩阵所在的行
        if ((G.arcs[v][w] != 0) && (!visited[w]))   // w是v的邻接点且没有访问
        {
            DFS(G, w);  // 递归调用DFS
        }
    }
}