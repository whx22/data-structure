#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXSIZE 100
#define INFINITY 65535

using VertexType = char;
using EdgeType = int;
typedef struct EdgeNode {
    EdgeType    weight;
    int         destination;
    EdgeNode*   next;
} EdgeNode;
typedef struct {
    VertexType  data;
    EdgeNode*   first;
} VertexNode, AdjacencyList[MAXSIZE];
typedef struct {
    AdjacencyList   adjacency_list;
    int             num_vertex;
    int             num_edge;
} ALGraph;

// create directed graph
void createDG(ALGraph& G) {
    cout << "Please input the number of vertices and edges for the graph" << endl;
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cout << "Please input num." << i + 1 << " vertex's data" << endl;
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source, destination;
    EdgeNode* edge = nullptr;
    for (int i = 0; i < G.num_edge; ++i) {
        cout << "Please input the source and destination of the num." << i + 1 << " edge" << endl;
        cin >> source >> destination;
        edge = new EdgeNode;
        edge->destination = destination;
        edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = edge;
    }
}
// create undirected graph
void createUG(ALGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source, destination;
    EdgeNode* edge;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination;
        edge = new EdgeNode;
        edge->destination = destination;
        edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = edge;
        edge = new EdgeNode;
        edge->destination = source;
        edge->next = G.adjacency_list[destination].first;
        G.adjacency_list[destination].first = edge;
    }
}
// create directed net
void createDN(ALGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source, destination, weight;
    EdgeNode* edge;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> weight;
        edge = new EdgeNode;
        edge->weight = weight;
        edge->destination = destination;
        edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = edge;
    }
}
// create undirected net
void createUN(ALGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source, destination, weight;
    EdgeNode* edge;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> weight;
        edge = new EdgeNode;
        edge->weight = weight;
        edge->destination = destination;
        edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = edge;
        edge = new EdgeNode;
        edge->weight = weight;
        edge->destination = source;
        edge->next = G.adjacency_list[destination].first;
        G.adjacency_list[destination].first = edge;
    }
}
// DFS
void visitVertex(const ALGraph& G, const int& v, bool*& visited) {
    cout << G.adjacency_list[v].data << endl;
    visited[v] = true;
}
void DFS(const ALGraph& G, const int& v, bool*& visited) {
    visitVertex(G, v, visited);
    EdgeNode* p = G.adjacency_list[v].first;
    while (p) {
        if (!visited[p->destination]) {
            DFS(G, p->destination, visited);
        }
        p = p->next;
    }
}
void DFSTraverse(const ALGraph& G) {
    bool* visited = new bool[G.num_edge];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        if (!visited[i]) {
            DFS(G, i, visited);
        }
    }
    delete[] visited;
}
void BFSTraverse(const ALGraph& G) {
    bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    int current_vertex_index;
    EdgeNode* p = nullptr;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (!visited[i]) {
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                current_vertex_index = assist_queue.front();
                visitVertex(G, current_vertex_index, visited);
                assist_queue.pop();
                p = G.adjacency_list[current_vertex_index].first;
                while (p) {
                    if (!visited[p->destination]) {
                        assist_queue.push(p->destination);
                    }
                    p = p->next;
                }
            }
        }
    }
    delete[] visited;
}

void test_1() {
    ALGraph G;
    createDG(G);
    BFSTraverse(G);
}

int main() {
    test_1();
    return EXIT_SUCCESS;
}