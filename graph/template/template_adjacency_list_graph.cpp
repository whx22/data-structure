/**
 * @file template_adjacency_list_graph.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief adjacency list graph create & depth first search & breadth first search
 * @version 0.1
 * @date 2023-05-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXSIZE     100
#define INFINITY    65535

using VertexType    = char;
using EdgeType      = int;

typedef struct EdgeNode {
    EdgeType    info;
    int         adjacency_vertex_index;
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
} AdjacencyGraph;

// create directed adjacency graph
void createDG(AdjacencyGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source = 0, destination = 0;
    EdgeNode* current_edge = nullptr; 
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination;
        current_edge = new EdgeNode;
        current_edge->adjacency_vertex_index = destination;
        current_edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = current_edge;
    }
}

// create undirected adjacency graph
void createUG(AdjacencyGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source = 0, destination = 0;
    EdgeNode* current_edge = nullptr;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination;
        current_edge = new EdgeNode;
        current_edge->adjacency_vertex_index = destination;
        current_edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = current_edge->next;
        current_edge = new EdgeNode;
        current_edge->adjacency_vertex_index = source;
        current_edge->next = G.adjacency_list[destination].first;
        G.adjacency_list[destination].first = current_edge;
    }
}

// create directed adjacency net
void createDN(AdjacencyGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source = 0, destination = 0, value = 0;
    EdgeNode* current_edge = nullptr;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> value;
        current_edge = new EdgeNode;
        current_edge->info = value;
        current_edge->adjacency_vertex_index = source;
        current_edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = current_edge;
    }
}

// create undirected adjacency net
void createUN(AdjacencyGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.adjacency_list[i].data;
        G.adjacency_list[i].first = nullptr;
    }
    int source = 0, destination = 0, value = 0;
    EdgeNode* current_edge;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> value;
        current_edge = new EdgeNode;
        current_edge->info = value;
        current_edge->adjacency_vertex_index = destination;
        current_edge->next = G.adjacency_list[source].first;
        G.adjacency_list[source].first = current_edge;
        current_edge = new EdgeNode;
        current_edge->info = value;
        current_edge->adjacency_vertex_index = source;
        current_edge->next = G.adjacency_list[destination].first;
        G.adjacency_list[destination].first = current_edge;
    }
}

// visit a vertex
void visitVertex(const AdjacencyGraph& G, const int& v, bool*& visited) {
    cout << G.adjacency_list[v].data << endl;
    visited[v] = true;
}

// Depth First Search a graph connectivity component
void DFS(const AdjacencyGraph& G, const int& v, bool*& visited) {
    visitVertex(G, v, visited);
    EdgeNode* traverse_ptr = G.adjacency_list[v].first;
    while (traverse_ptr) {
        if (!visited[traverse_ptr->adjacency_vertex_index]) {
            DFS(G, traverse_ptr->adjacency_vertex_index, visited);
        }
        traverse_ptr = traverse_ptr->next;
    }
}

// Depth First Search all graph & net connectivity component
void DFSTraverse(const AdjacencyGraph& G) {
bool* visited = new bool[G.num_vertex];
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

// Breadth First Search all graph & net connectivity component
void BFSTraverse(const AdjacencyGraph& G) {
bool* visited = new bool[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    EdgeNode* current_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (!visited[i]) {
            visitVertex(G, i, visited);
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                current_edge = G.adjacency_list[assist_queue.front()].first;
                assist_queue.pop();
                while (current_edge) {
                    if (!visited[current_edge->adjacency_vertex_index]) {
                        visitVertex(G, current_edge->adjacency_vertex_index, visited);
                        assist_queue.push(current_edge->adjacency_vertex_index);
                    }
                    current_edge = current_edge->next;
                }
            }
        }
    }
delete[] visited;
}