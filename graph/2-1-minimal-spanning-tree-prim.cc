// minimal spanning tree
#include "2-0-graph-structure.h"
using namespace adjacency_matrix;

// Prim : minimal spanning tree algorithm 
void miniSpanTreePrim(const MGraph& G) {
    // record the minimum overhead for each vertex to incorporation spanning tree
    // lowCost[i] == 0 : i index vertex is merged into spanning tree
    int lowCost[MAX_VERTEX] =  { 0 };   
    // record each vertex is merged into spanning tree through that vertex
    // adjVertex[i] == j; i index vertex merged into spanning tree through j index vertex
    int adjVertex[MAX_VERTEX] = { 0 }; 
    // the minimum spanning tree is incorporated into each node
    // need to update the lowCost array and adjVertex array
    lowCost[0] = 0;     // 0 index vertex is merged into spanning tree
    adjVertex[0] = 0;   // 0 index vertex merged into spanning tree through itself 
    for (int i = 0; i < G.numVertex; ++i) {
        lowCost[i] = G.arc[0][i];
        adjVertex[i] = 0;
    }

    // k record the minimal weight adjacency vertex
    // mim record the minimal weight
    int k = 0, min = INFINITY;
    for (int i = 1; i < G.numVertex; ++i) {
        k = 0, min = INFINITY;
        for (int j = 1; j < G.numVertex; ++j) {
            if (lowCost[j] != 0 && lowCost[j] < min) {
                min = lowCost[j];
                k = j;
            }
        }
        std::cout << "(" << adjVertex[k] << ", " << k << ")" << std::endl;
        lowCost[k] = 0;
        for (int j = 1; j < G.numVertex; ++j) {
            if (lowCost[j] != 0 && G.arc[k][j] < lowCost[j]) {
                lowCost[j] = G.arc[k][j];
                adjVertex[j] = k;
            }
        }
    }
}

// Kruskal : minimal spanning tree algorithm
typedef struct {
    int begin, end;
    int weight;
} Edge;
int find(int parent[], int f) {
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}
void miniSpanTreeKruskal(const MGraph& G) {
    Edge edges[MAX_EDGE];
    int parent[MAX_VERTEX];

    // TODO : 将邻接矩阵G转化为边集数组edges并按权重由小到大排列

    // initialize the parent array
    for (int i = 0; i < G.numVertex; ++i) {
        parent[i] = 0;
    }
    int n = 0, m = 0;
    for (int i = 0; i < G.numEdge; ++i) {
        n = find(parent, edges[i].begin);
        m = find(parent, edges[i].end);
        if (n != m) {
            parent[n] = m;
            std::cout << "(" << edges[i].begin << ", " << edges[i].end << ") "
            << "weight = " << edges[i].weight << std::endl;
        }
    }
}