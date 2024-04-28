/**
 * @file template_matrix_graph.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief matrix graph create & depth first search & breadth first search
 * @version 0.1
 * @date 2023-05-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXSIZE     100
#define INFINITY    65536

using VertexType = char;
using EdgeType = int;

typedef struct {
    VertexType  vertex[MAXSIZE];
    EdgeType    edge[MAXSIZE][MAXSIZE];
    int         num_vertex;
    int         num_edge;
} MatrixGraph;

// create matrix directed graph 
void createDG(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = 0;
        }
    }
    int source = 0, destination = 0;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination;
        G.edge[source][destination] = 1;
    }
}

// create matrix undirected graph
void createUG(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++i) {
            G.edge[i][j] = 0;
        }
    }
    int source = 0, destination = 0;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination;
        G.edge[source][destination] = G.edge[destination][source] = 1;
    }
}

// create matrix directed net
void createDN(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = INFINITY;
        }
    }
    int source = 0, destination = 0, value = 0;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> value;
        G.edge[source][destination] = value;
    }
}

// create matrix undirected net
void createUN(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = INFINITY;
        }
    }
    int source = 0, destination = 0, value = 0;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> value;
        G.edge[source][destination] = G.edge[destination][source] = value;
    }
}

// visit a vertex
void visitVertex(const MatrixGraph& G, const int& v, bool*& visited) {
    cout << G.vertex[v] << endl;
    visited[v] = true;
}

// graph Depth First Search a connectivity component
void DFS_G(const MatrixGraph& G, const int& v, bool*& visited) {
    visitVertex(G, v, visited);
    for (int i = 0; i < G.num_vertex; ++i) {
        if (G.edge[v][i] && !visited[i]) {
            DFS_G(G, i, visited);
        }
    }
}

// graph Depth First Search all connectivity component
void DFSTraverse_G(const MatrixGraph& G) {
bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        if (!visited[i]) {
            DFS_G(G, i, visited);
        }
    }
delete[] visited;
}

// net Depth First Search a connectivity component
void DFS_N(const MatrixGraph& G, const int& v, bool*& visited) {
    visitVertex(G, v, visited);
    for (int i = 0; i < G.num_vertex; ++i) {
        if (G.edge[v][i] != INFINITY && !visited[i]) {
            DFS_N(G, i, visited);
        }
    }
}

// net Depth First Search all connectivity component
void DFSTraverse_N(const MatrixGraph& G) {
bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        if (!visited[i]) {
            DFS_N(G, i, visited);
        }
    }
delete[] visited;
}

// graph Breadth First Search all connectivity component
void BFSTraverse_G(const MatrixGraph& G) {
bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    int current_vertex_index;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (!visited[i]) {
            visitVertex(G, i, visited);
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                current_vertex_index = assist_queue.front();
                assist_queue.pop();
                for (int j = 0; j < G.num_vertex; ++j) {
                    if (G.edge[current_vertex_index][j] && !visited[j]) {
                        visitVertex(G, j, visited);
                        assist_queue.push(j);
                    }
                }
            }
        }
    }
delete[] visited;
}

// net Breadth First Search all connectivity component
void BFSTraverse_N(const MatrixGraph& G) {
bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    int current_vertex_index;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (!visited[i]) {
            visitVertex(G, i, visited);
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                current_vertex_index = assist_queue.front();
                assist_queue.pop();
                for (int j = 0; j < G.num_vertex; ++j) {
                    if (G.edge[current_vertex_index][j] != INFINITY && !visited[j]) {
                        visitVertex(G, j, visited);
                        assist_queue.push(j);
                    }
                }
            }
        }
    }
delete[] visited;
}