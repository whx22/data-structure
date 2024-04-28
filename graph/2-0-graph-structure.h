#ifndef GRAPH_STRUCTURE_H
#define GRAPH_STRUCTURE_H

// graph structure

// adjacency matrix
#include <iostream>
#include <queue>
using namespace std;
namespace adjacency_matrix {

typedef char    VertexType;
typedef int     EdgeType;
#define MAXSIZE 100
#define INFINITY 65535
typedef struct {
    VertexType  vertex[MAXSIZE];
    EdgeType    arc[MAXSIZE][MAXSIZE];
    int         numVertex, numEdge;
} MGraph;

// Establish the adjacency matrix representation of the undirected network graph
void createMGraph(MGraph* G) {
    // record the number of vertices and edges
    std::cout << "Please input the number of vertices : " << std::endl; 
    std::cin >> G->numVertex;
    std::cout << "Please input the number of edges : " << std::endl;
    std::cin >> G->numEdge;
    
    // record the values for each vertex 
    for (int i = 0; i < G->numVertex; ++i) {
        std::cout << "Please input No." << i << " vertex value : " << std::endl;
        std::cin >> G->vertex[i];
    }

    // initialize the value of each edge
    for (int i = 0; i < G->numVertex; ++i) {
        for (int j = 0; j < G->numVertex; ++j) {
            G->arc[i][j] = INFINITY;
        }
    }

    // record the values of each edge
    int i = 0, j = 0, w = INFINITY;
    for (int k = 0; k < G->numEdge; ++k) {
        std::cout << "Please input (vi, vj) index and their weight w : " << std::endl;
        std::cin >> i >> j >> w;
        G->arc[i][j] = G->arc[j][i] = w;    // undirected network graph
    }
}   

// adjacency matrix graph Depth First Search algorithm
#define MAX_VERTEX 9
bool visited[MAX_VERTEX];   // record each node access
void DFS(const MGraph& G, const int& i) {
    visited[i] = true;
    std::cout << G.vertex[i] << std::endl;  // visit vertex i
    for (int j = 0; j < G.numVertex; ++j) {
        // note : different graph connection conditions are judges differently
        // directed and undirected graph : G.arc[i][j] == 1
        // directed and undirected network graph : G.arc[i][j] != INFINITY
        if(G.arc[i][j] == 1 && !visited[j]) {
            DFS(G, j);
        }
    }
}
void DFSTraverse(const MGraph& G) {
    // initialize the visited array
    for (int i = 0; i < G.numVertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.numVertex; ++i) {
        if (!visited[i]) {  // note : the connection graph is executed only one
            DFS(G, i);
        }
    }
}

// adjacency matrix graph Breadth First Search
void BFSTraverse(const MGraph& G) {
    // initialize the visited array;
    for (int i = 0; i < G.numVertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    for (int i = 0; i < G.numVertex; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            std::cout << G.vertex[i] << std::endl;  // visit vertex i
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                int k = assist_queue.front();
                assist_queue.pop();
                for (int j = 0; j < G.numVertex; ++j) {
                    // note : different graph connection conditions are judges differently
                    // directed and undirected graph : G.arc[k][j] == 1
                    // directed and undirected network graph : G.arc[k][j] != INFINITY
                    if (G.arc[k][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        std::cout << G.vertex[j] << std::endl;
                        assist_queue.push(j);
                    }
                }
            }
        }
    }
}

}   // namespace adjacency_matrix

#include <iostream>
namespace adjacency_list {
typedef char    VertexType;
typedef int     EdgeType;
#define MAX_VERTEX 9
#define MAX_EDGE 19
// the edge node structure
typedef struct EdgeNode {
    int                 adjacency_vertex;   // record the adjacency vertex index
    EdgeType            info;               // record network graph weight
    struct EdgeNode*    next;               // record next edge node pointer
} EdgeNode;
// the vertex node structure
typedef struct VertexNode {
    VertexType  data;       // record the vertex value
    EdgeNode*   firstEdge;  // record the first edge node pointer 
} VertexNode, AdjList[MAXSIZE];
// the adjacency list graph structure
typedef struct {
    AdjList adjList;            // record the adjacency list
    int     numVertex, numEdge; // record the number of vertices and edges
} ALGraph;

// Establishes the adjacency list graph structure
void CreateALGraph(ALGraph* G) {
    // record the number of vertices and edges
    std::cout << "Please input the number of vertices : " << std::endl; 
    std::cin >> G->numVertex;
    std::cout << "Please input the number of edges : " << std::endl;
    std::cin >> G->numEdge;

    // record the values for each vertex data
    // initialize first edge of each vertex 
    for (int i = 0; i < G->numVertex; ++i) {
        std::cout << "Please input No." << i
        << " vertex value : " << std::endl;
        std::cin >> G->adjList[i].data;
        G->adjList[i].firstEdge = nullptr;
    } 

    // record the values of each edge
    int i = 0, j = 0;
    EdgeNode* e = nullptr;
    for (int k = 0; k < G->numEdge; ++k) {
        std::cout << "Please input (vi, vj) index : " << std::endl;
        std::cin >> i >> j;
        // use the two-time head insertion method
        // record i -> j relation
        e = new EdgeNode;
        e->adjacency_vertex = j;
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
        // record j -> i relation
        e = new EdgeNode;
        e->adjacency_vertex = i;
        e->next = G->adjList[j].firstEdge;
        G->adjList[i].firstEdge = e;
    }
}

// adjacency list graph Depth First Search algorithm
bool visited[MAX_VERTEX];
void DFS(const ALGraph& G, const int& i) {
    EdgeNode* p = nullptr;
    visited[i] = true;
    std::cout << G.adjList[i].data << std::endl;    // visit vertex i
    p = G.adjList[i].firstEdge;
    while (p) {
        if (!visited[p->adjacency_vertex]) {
            DFS(G, p->adjacency_vertex);
            p = p->next;
        }
    }
}   
void DFSTraverse(const ALGraph& G) {
    // initialize the visited array 
    for (int i = 0; i < G.numVertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.numVertex; ++i) {
        if (!visited[i]) {  // note : the connection graph is executed only one
            DFS(G, i);
        }
    }
}

// adjacency list graph Breadth First Search algorithm
void BFSTraverse(const ALGraph& G) {
    // initialize the visited array
    for (int i = 0; i < G.numVertex; ++i) {
        visited[i] = false;
    }
    queue<int> assist_queue;
    EdgeNode* p = nullptr;
    for (int i = 0; i < G.numVertex; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            std::cout << G.adjList[i].data << std::endl;    // visit vertex i
            assist_queue.push(i);
            while (!assist_queue.empty()) {
                int k = assist_queue.front();
                assist_queue.pop();
                // find the current exit queue vertex first adjacency vertex
                p = G.adjList[k].firstEdge;
                // traverse the current exit queue vertex all adjacency vertex
                // visit and enter queue adjacency vertex have not been visited
                while (p) {
                    if (!visited[p->adjacency_vertex]) {
                        visited[p->adjacency_vertex] = true;
                        std::cout << G.adjList[p->adjacency_vertex].data << std::endl;
                        assist_queue.push(p->adjacency_vertex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

}   // namespace adjacency_list 

#endif  // GRAPH_STRUCTURE_H
