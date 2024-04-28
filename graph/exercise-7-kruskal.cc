#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define MAXSIZE     100
#define INFINITY    65535

using VertexType    = char;
using EdgeType      = int;

typedef struct {
    VertexType  vertex[MAXSIZE];
    EdgeType    edge[MAXSIZE][MAXSIZE];
    int         num_vertex;
    int         num_edge;
} MatrixGraph;

typedef struct Edge {
    bool operator > (const Edge& e) {
        return this->length > e.length;
    }
    bool operator < (const Edge& e) {
        return this->length < e.length;
    }
    int         source;
    int         destination;
    EdgeType    length;
} Edge;

int Find(int*& dsu, int x) {
    if (dsu[x] < 0) {
        return x;
    } else {
        return dsu[x] = Find(dsu, dsu[x]);
    }
}

void Union(int*& dsu, int x, int y) {
    x = Find(dsu, x);
    y = Find(dsu, y);
    if (x == y) {
        return;
    } else {
        if (dsu[x] < dsu[y]) {
            dsu[x] += dsu[y];
            dsu[y] = x;
        } else {
            dsu[y] += dsu[x];
            dsu[x] = y;
        }
    }
}

int Count(int*& dsu, int x) {
    return -dsu[Find(dsu, x)];
}

/**
 * @brief 
 *  print edge information
 * @param e 
 */
void printEdge(const Edge& e) {
    cout << "(" << e.source << ", " << e.destination << ")"\
    << "length = " << endl; 
}

// void Kruskal(const MatrixGraph& G, int& sum) {
//     // create & initialize & sort edges array
//     Edge edges[G.num_edge];
//     int current_edge = 0;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (G.edge[i][j] != INFINITY) {
//                 edges[current_edge].source = i;
//                 edges[current_edge].destination = j;
//                 edges[current_edge].length = G.edge[i][j];
//                 ++current_edge;
//             }
//         }
//     }
//     assert(current_edge + 1 == G.num_edge);
//     sort(edges[0], edges[G.num_edge]);
//     // create and initialize dsu array
// int* dsu = new int[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         dsu[i] = -1;
//     }
//     // generate minimum spanning tree
//     int m = 0, n = 0;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         m = Find(dsu, edges[i].source);
//         n = Find(dsu, edges[i].destination);
//         if (m != n) {
//             Union(dsu, m, n);
//             sum += edges[i].length;
//             printEdge(edges[i]);
//         }
//     }
// delete[] dsu;
// }

/**
 * @brief Kruskal algorithm to generate minimum spanning tree in increment per edge
 *  assist array and variable :
 *  1. edge array   : store all edges in graph order by length 
 *  2. dsu array    : record the disjoint set of vertex
 *  
 *  main process :
 *  1. create & initialize & sort edges array
 *  2. create & initialize dsu array
 *  3. generate minimum spanning tree
 */
/**
 * @brief 
 *  Kruskal algorithm to generate minimum spanning tree in increment per edge
 * @param G 
 * @param sum
 *  
 */
void Kruskal(const MatrixGraph& G, int& sum) {
    // create & initialize & sort edges array
    Edge edges[G.num_edge];
    int current_edge = 0;
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            if (G.edge[i][j] != INFINITY) {
                edges[current_edge].source = i;
                edges[current_edge].destination = j;
                edges[current_edge].length = G.edge[i][j];
                ++current_edge;
            }
        }
    }
    assert(current_edge + 1 == G.num_edge);
    sort(edges[0], edges[G.num_edge]);
    // create & initialize dsu array
int* dsu = new int[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        dsu[i] = -1;
    }
    // generate minimum spanning tree
    int m = 0, n = 0;
    for (int i = 0; i < G.num_edge; ++i) {
        m = Find(dsu, edges[i].source);
        n = Find(dsu, edges[i].destination);
        if (m != n) {
            printEdge(edges[i]);
            Union(dsu, m, n);
            sum += edges[i].length;
        }
    }
}
