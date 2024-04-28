#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXSIZE 100
#define INFINITY 65535

using VertexType = char;
using EdgeType = int;

typedef struct {
    VertexType  vertex[MAXSIZE];
    EdgeType    edge[MAXSIZE][MAXSIZE];
    int         num_vertex;
    int         num_edge;
} MatrixGraph;

// create directed graph
void CreateDG(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = 0;
        }
    }
    int source, destination;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination;
        G.edge[source][destination] = 1;
    }
}
// create undirected graph
void CreateUG(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = 0;
        }
    }
    int source, destination;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination;
        G.edge[source][destination] = G.edge[destination][source] = 1;
    }
}
// create directed net
void CreateDN(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = false;
        }
    }
    int source, destination;
    EdgeType value;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> value;
        G.edge[source][destination] = value;
    }
}
// create undirected net
void CreateUN(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = INFINITY;
        }
    }
    int source, destination;
    EdgeType value;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> source >> destination >> value;
        G.edge[source][destination] = G.edge[destination][source] = value; 
    }
}

inline void visitVertex(const MatrixGraph& G, const int& v) {
    cout << G.vertex[v] << endl;
}
// graph DFS
void DFS_G(const MatrixGraph& G, const int& v, bool*& visited) {
    visitVertex(G, v);
    visited[v] = true;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (G.edge[v][i] != 0 && visited[i] == false) {
            DFS_G(G, i, visited);
        }
    }
}
void DFSTraverse_G(const MatrixGraph& G) {
    bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        if (visited[i] == false) {
            DFS_G(G, i, visited);
        }
    }
    delete[] visited;
}
// net DFS
void DFS_N(const MatrixGraph& G, const int& v, bool*& visited) {
    visitVertex(G, v);
    visited[v] = true;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (G.edge[v][i] != INFINITY && visited[i] == false) {
            DFS_N(G, v, visited);
        }
    }
} 
void DFSTraverse_N(const MatrixGraph& G) {
    bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        if (visited[i] == false) {
            DFS_N(G, i, visited);
        }
    }
    delete[] visited;
}
// graph BFS
void BFS_G(const MatrixGraph& G) {
    bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    int current_vertex_index;
    for (int i= 0; i < G.num_vertex; ++i) {
        if (visited[i] == false) {
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                current_vertex_index = assist_queue.front();
                visitVertex(G, current_vertex_index);
                visited[current_vertex_index] = true;
                assist_queue.pop();
                for (int j = 0; j < G.num_vertex; ++j) {
                    if (G.edge[current_vertex_index][j] != 0 && visited[j] == false) {
                        assist_queue.push(j);
                    }
                }
            }
        }
    }
    delete[] visited;
}
// net BFS
void BFS_N(const MatrixGraph& G) {
    bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    int current_vertex_index;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (visited[i] == false) {
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                current_vertex_index = assist_queue.front();
                visitVertex(G, current_vertex_index);
                visited[current_vertex_index] = false;
                assist_queue.pop();
                for (int j = 0; j < G.num_vertex; ++j) {
                    if (G.edge[current_vertex_index][j] != INFINITY && visited[j] == false) {
                        assist_queue.push(j);
                    }
                }
            }
        }
    }
    delete[] visited;
}