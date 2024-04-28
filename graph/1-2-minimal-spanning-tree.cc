// minimal spanning tree
// Prim algorithm : 以结点为单位构造最小生成树
// Kruskal algorithm : 以边为单位构造最小生成树

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
namespace Prim {
// Prim algorithm graph structure
#define INFINITE 32767
char Vertex[5] = { 'a', 'b', 'c', 'd', 'e' };
double Edge[5][5];

// initialize adjacency matrix
void initAdjacencyMatrixGraph(void) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            Edge[i][j] = INFINITE;
        }
    }
}
/*
 * FunctionName : Prim()
 * Description : calculate the sum of the weights of the minimal spanning tree
 * Parameter 1 : the number of vertexes of the graph 
 * Parameter 2 : the object graph : Two-dimensional array
 * Parameter 3 : the first vertex of the minimal spanning tree
 * Parameter 4 : the weights of the minimal spanning tree 
 */
/**
 * @brief Prim algorithm
 *  assist array and variable : 
 *  1. lowCost array : record the minimum weight of the edge from the current spanning tree to other vertex
 *  2. vertexSet array : record the vertex whether has been visited
 *  3. v : record the vertex which has been visited last time
 *  4. sum : record the sum of the weights of the minimal spanning tree
 * 
 *  main process : 
 *  1. initialize lowCost array & vertexSet array & v & sum
 *  2. select the edge which has the minimum weight and the vertex of the edge has not been visited
 *  3. update the lowCost array
 *  4. repeat step 2 & 3 until all the vertexes have been visited
 *  5. return the sum of the weights of the minimal spanning tree
*/
void Prim(const int& n, const double**& MatrixGraph, const int& v0, double& sum) {
    int lowCost[n];     // 记录当前生成树到其余各顶点边的最小权值
    // lowCost[n] : 当前生成树到顶点n边权值最小的权值
    
    bool vertexSet[n];  // 记录n顶点是否已经并入生成树
    // vertexSet[n] = true : 顶点n已经并入生成树
    // vertexSet[n] = false : 顶点n未并入生成树
    
    int v, k, min;  // v记录刚并入的顶点
    
    // 初始化lowCost array & vertexSet array & v & sum
    for (int i = 0; i < n; ++i) {
        lowCost[i] = MatrixGraph[v0][i];
        // vertexSet[i] = { 0 };
        memset(vertexSet, 0, sizeof(vertexSet));
    }
    v = v0;             
    vertexSet[v] = true;
    sum = 0;

    // 构建生成树的主要过程
    for (int i = 0; i < n - 1; ++i) {
        // 选出没有并入生成树且权值最小的边, 并将改变并入生成树
        min = INFINITE;
        for (int j = 0; j < n; ++j) {
            if (vertexSet[j] == false && lowCost[j] < min) {
                min = lowCost[j];
                k = j;
            }
        }
        vertexSet[k] = true;    // 标记k顶点已经访问
        v = k;                  // 记录刚并入的结点k
        sum += min;             // 更新最小生成树代价

        // 通过刚并入的顶点v到其他顶点的权值, 更新lowCost array 
        for (int j = 0; j < n; ++j) {
            if (vertexSet[j] == false && MatrixGraph[v][j] < lowCost[j]) {
                lowCost[j] = MatrixGraph[v][j];
            }
        }
    }
}

}   // namespace Prim


#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
namespace Kruskal {
// Kruskal algorithm graph structure : 以边为单位构造最小生成树
#define MAXSIZE 100
typedef struct {
    int a, b;   // 边的两个顶点
    int weight; // 边的权重
} Edge;
Edge edge[MAXSIZE];     // edge set array
int dsu[MAXSIZE];       // disjoint set union array
// initialize disjoint set union array
void initDisjointSetUnion() {
    memset(dsu, -1, sizeof(dsu));
}
/**
 * @brief find the root of the vertex
 * 
 * @param v 
 * @return int 
 */
int Find(int v) {
    if (dsu[v] < 0) {
        return v;
    } else {
        return dsu[v] = Find(v);
    }
}

void Union(int v1, int v2) {
    v1 = Find(v1);
    v2 = Find(v2);
    if (v1 == v2) {
        return;
    } else {
        if (dsu[v1] < dsu[v2]) {    // v1集合的元素个数大于v2集合的元素个数
            dsu[v1] += dsu[v2];
            dsu[v2] = v1;
        } else {                    // v2集合的元素个数大于v1集合的元素个数
            dsu[v2] += dsu[v1];
            dsu[v1] = v2;
        }
    }
}

/**
 * @brief Kruskal algorithm
 * 
 * @param vertex_num : the number of vertexes of the graph
 * @param edge_num : the number of edges of the graph
 * @param sum : the sum of the weights of the minimal spanning tree
 */
void Kruskal(const int& vertex_num, const int& edge_num, int& sum) {
    // 1. initialize disjoint set union array
    initDisjointSetUnion();
    // 2. sort the edge set array
    // TODO : implement : sort(Edge, edge_num);
    
    // select the edge which has the minimum weight and the vertex of the edge has not been visited and merge the two vertexes of the edge
    int a = 0, b = 0;
    for (int i = 0; i < edge_num; ++i) {
        a = Find(edge[i].a);
        b = Find(edge[i].b);
        if (a != b) {
            Union(a, b);
            sum += edge[i].weight;
        }
    }
}

}   // namespace Kruskal 