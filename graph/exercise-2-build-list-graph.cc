// #include <iostream>
// using namespace std;

// #define MAXSIZE 100
// #define INFINITY 65535

// using VertexType = char;
// using EdgeType = int;

// typedef struct EdgeNode {
//     EdgeType    info;
//     int         adjacency_vertex;
//     EdgeNode*   next;
// } EdgeNode;

// typedef struct {
//     VertexType  data;
//     EdgeNode*   first;
// } VertexType, AdjList[MAXSIZE];

// typedef struct {
//     AdjList adjacency_list;
//     int     num_vertex, num_edge;
// } ALGraph;

// // 有向图
// void CreateALGraph(ALGraph& ALG) {
//     // record the number of vertices and edges
//     cin >> ALG.num_vertex >> ALG.num_edge;

//     // record the values for each vertex data
//     for (int i = 0; i < ALG.num_vertex; ++i) {
//         cin >> ALG.adjacency_list[i].data;
//         ALG.adjacency_list[i].first = nullptr;
//     }

//     // record the values of each edge
//     int source, destination;
//     EdgeNode* edge;
//     for (int i = 0; i < ALG.num_edge; ++i) {
//         cin >> source >> destination;
//         edge = new EdgeNode;
//         edge->adjacency_vertex = destination;
//         edge->next = ALG.adjacency_list[source].first;
//         ALG.adjacency_list[source].first = edge;
//     }
// }

// // 无向图
// void CreateALGraph(ALGraph& ALG) {
//     cin >> ALG.num_vertex >> ALG.num_edge;
//     for (int i = 0; i < ALG.num_vertex; ++i) {
//         cin >> ALG.adjacency_list[i].data;
//         ALG.adjacency_list[i].first = nullptr;
//     }
//     int source, destination;
//     EdgeNode* edge;
//     for (int i = 0; i < ALG.num_edge; ++i) {
//         cin >> source >> destination;
        
//         edge = new EdgeNode;
//         edge->adjacency_vertex = destination;
//         edge->next = ALG.adjacency_list[source].first;
//         ALG.adjacency_list[i].first = edge;
        
//         edge = new EdgeNode;
//         edge->adjacency_vertex = source;
//         edge->next = ALG.adjacency_list[destination].first;
//         ALG.adjacency_list[destination].first = edge;
//     } 
// }

// // 有向网
// void CreateALGraph(ALGraph& ALG) {
//     cin >> ALG.num_vertex >> ALG.num_edge;
//     for (int i = 0; i < ALG.num_vertex; ++i) {
//         cin >> ALG.adjacency_list[i].data;
//         ALG.adjacency_list[i].first = nullptr;
//     }
//     int source, destination, value;
//     EdgeNode* edge;
//     for (int i = 0; i < ALG.num_edge; ++i) {
//         cin >> source >> destination >> value;

//         edge = new EdgeNode;
//         edge->info = value;
//         edge->adjacency_vertex = destination;
//         edge->next = ALG.adjacency_list[source].first;
//         ALG.adjacency_list[source].first = edge;
//     }
// }

// // 无向网
// void CreateALGraph(ALGraph& ALG) {
//     cin >> ALG.num_vertex >> ALG.num_edge;
//     for (int i = 0; i < ALG.num_vertex; ++i) {
//         cin >> ALG.adjacency_list[i].data;
//         ALG.adjacency_list[i].first = nullptr;
//     }
//     int source, destination, value;
//     EdgeNode* edge;
//     for (int i = 0; i < ALG.num_edge; ++i) {
//         cin >> source >> destination >> value;

//         edge = new EdgeNode;
//         edge->info = value;
//         edge->adjacency_vertex = destination;
//         edge->next = ALG.adjacency_list[source].first;
//         ALG.adjacency_list[source].first = edge;

//         edge = new EdgeNode;
//         edge->info = value;
//         edge->adjacency_vertex = source;
//         edge->next = ALG.adjacency_list[destination].first;
//         ALG.adjacency_list[destination].first = edge;
//     }
// }

// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;

// #define MAXSIZE 100
// #define INFINITY 65535

// using VertexType = char;
// using EdgeType = int;

// typedef struct EdgeNode {
//     EdgeType    info;
//     int         adjacency_vertex_index;
//     EdgeNode*   next;
// } EdgeNode;

// typedef struct {
//     VertexType  data;
//     EdgeNode*   first_edge;
// } Vertex, AdjList[MAXSIZE];

// typedef struct {
//     AdjList adjacency_list;
//     int     num_vertex;
//     int     num_edge;
// } ALGraph;

// // directed graph
// void CreateDG(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first_edge = nullptr;
//     }
//     int source, destination;
//     EdgeNode* edge;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;

//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = destination;
//         edge->next = G.adjacency_list[source].first_edge;
//         G.adjacency_list[source].first_edge = edge;
//     }
// }
// // undirected graph
// void CreateUG(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first_edge = nullptr;
//     }
//     int source, destination;
//     EdgeNode* edge;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;

//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = destination;
//         edge->next = G.adjacency_list[source].first_edge;
//         G.adjacency_list[source].first_edge = edge;

//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = source;
//         edge->next = G.adjacency_list[destination].first_edge;
//         G.adjacency_list[destination].first_edge = edge;
//     }
// }
// // directed net
// void CreateDN(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first_edge = nullptr;
//     }
//     int source, destination, value;
//     EdgeNode* edge;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;

//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = destination;
//         edge->info = value;
//         edge->next = G.adjacency_list[source].first_edge;
//         G.adjacency_list[source].first_edge = edge;
//     }
// }
// // undirected net
// void CreateUN(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first_edge = nullptr;
//     }
//     int source, destination, value;
//     EdgeNode* edge;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;

//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = destination;
//         edge->info = value;
//         edge->next = G.adjacency_list[source].first_edge;
//         G.adjacency_list[source].first_edge = edge;

//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = source;
//         edge->info = value;
//         edge->next = G.adjacency_list[destination].first_edge;
//         G.adjacency_list[destination].first_edge = edge;
//     }
// }

// void visitVertex(const ALGraph& G, const int& v) {
//     cout << G.adjacency_list[v].data << endl;
// }
// // DFS 
// void DFS(const ALGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v);
//     visited[v] = true;
//     EdgeNode* p = G.adjacency_list[v].first_edge;
//     while (p) {
//         if (visited[p->adjacency_vertex_index] == false) {
//             DFS(G, p->adjacency_vertex_index, visited);
//         }
//         p = p->next;
//     }
// }
// void DFSTraverse(const ALGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (visited[i] == false) {
//             DFS(G, i, visited);
//         }
//     }
//     delete[] visited;
// }
// // BFS
// void BFS(const ALGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex_index;
//     EdgeNode* p = nullptr;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (visited[i] == false) {
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 visitVertex(G, current_vertex_index);
//                 visited[current_vertex_index] = true;
//                 p = G.adjacency_list[current_vertex_index].first_edge;
//                 assist_queue.pop();
//                 while (p) {
//                     if (visited[p->adjacency_vertex_index] == false) {
//                         assist_queue.push(p->adjacency_vertex_index);
//                     }
//                     p = p->next;
//                 }
//             }
//         }
//     }
//     delete[] visited;
// }
// void BFS(const ALGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex_index;
//     EdgeNode* p = nullptr;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (visited[i] == false) {
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 visitVertex(G, current_vertex_index);
//                 visited[current_vertex_index] = true;
//                 p = G.adjacency_list[current_vertex_index].first_edge;
//                 assist_queue.pop();
//                 while (p) {
//                     if (visited[p->adjacency_vertex_index] == false) {
//                         assist_queue.push(p->adjacency_vertex_index);
//                     }
//                     p = p->next;
//                 }
//             }
//         }
//     }
//     delete[] visited;
// }
// void BFS(const ALGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex_index;
//     EdgeNode* p = nullptr;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (visited[i] == false) {
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 visitVertex(G, current_vertex_index);
//                 visited[current_vertex_index] = true;
//                 p = G.adjacency_list[current_vertex_index].first_edge;
//                 assist_queue.pop();
//                 while (p) {
//                     if (visited[p->adjacency_vertex_index] == false) {
//                         assist_queue.push(p->adjacency_vertex_index);
//                     }
//                     p = p->next;
//                 }
//             }
//         }
//     }
//     delete[] visited;
// }


// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;

// #define MAXSIZE 100
// #define INFINITY 65535

// using VertexType = char;
// using EdgeType = int;
// typedef struct EdgeNode {
//     EdgeType    info;
//     int         adjacency_vertex_index;
//     EdgeNode*   next;
// } EdgeNode;
// typedef struct {
//     VertexType  data;
//     EdgeNode*   first;
// } VertexNode, AdjacentList[MAXSIZE];
// typedef struct {
//     AdjacentList    adjacent_list;
//     int             num_vertex;
//     int             num_edge;
// } ALGraph; 
// // create directed graph
// void createDG(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacent_list[i].data;
//         G.adjacent_list[i].first = nullptr;    
//     }
//     int source, destination;
//     EdgeNode* edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = destination;
//         edge->next = G.adjacent_list[source].first;
//         G.adjacent_list[source].first = edge;
//     }
// }
// // create undirected graph
// void createUG(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacent_list[i].data;
//         G.adjacent_list[i].first = nullptr;
//     }
//     int source, destination;
//     EdgeNode* edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = destination;
//         edge->next = G.adjacent_list[source].first;
//         G.adjacent_list[source].first = edge;
//         edge = new EdgeNode;
//         edge->adjacency_vertex_index = source;
//         edge->next = G.adjacent_list[destination].first;
//         G.adjacent_list[destination].first = edge;
//     }
// }
// // create directed net 
// void createDN(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacent_list[i].data;
//         G.adjacent_list[i].first = nullptr;
//     }
//     int source, destination, value;
//     EdgeNode* edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         edge = new EdgeNode;
//         edge->info = value;
//         edge->adjacency_vertex_index = destination;
//         edge->next = G.adjacent_list[source].first;
//         G.adjacent_list[source].first = edge;
//     }
// }
// // create undirected net
// void createUN(ALGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacent_list[i].data;
//         G.adjacent_list[i].first = nullptr;
//     }
//     int source, destination, value;
//     EdgeNode* edge;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         edge = new EdgeNode;
//         edge->info = value;
//         edge->adjacency_vertex_index = destination;
//         edge->next = G.adjacent_list[source].first;
//         G.adjacent_list[source].first = edge;
//         edge = new EdgeNode;
//         edge->info = value;
//         edge->adjacency_vertex_index = source;
//         edge->next = G.adjacent_list[destination].first;
//         G.adjacent_list[destination].first = edge;
//     }
// }
// // // DFS
// // void visitVertex(const ALGraph& G, const int& v, bool*& visited) {
// //     cout << G.adjacent_list[v].data << endl;
// //     visited[v] = true;
// // }
// // void DFS(const ALGraph& G, const int& v, bool*& visited) {
// //     visitVertex(G, v, visited);
// //     EdgeNode* p = G.adjacent_list[v].first;
// //     while (p) {
// //         if (!visited[p->adjacency_vertex_index]) {
// //             DFS(G, p->adjacency_vertex_index, visited);
// //         }
// //         p = p->next;
// //     }
// // }
// // void DFSTraverse(const ALGraph& G) {
// //     bool* visited = new bool[G.num_vertex];
// //     for (int i = 0; i < G.num_vertex; ++i) {
// //         visited[G.num_vertex] = false;
// //     }
// //     for (int i = 0; i < G.num_vertex; ++i) {
// //         if (!visited[i]) {
// //             DFS(G, i, visited);
// //         }
// //     }
// //     delete[] visited;
// // }
// // DFS
// void visitVertex(const ALGraph& G, const int& v, bool*& visited) {
//     cout << G.adjacent_list[v].data << endl;
//     visited[v] = true;
// }
// void DFS(const ALGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     EdgeNode* p = G.adjacent_list[v].first;
//     while (p) {
//         if (!visited[p->adjacency_vertex_index]) {
//             DFS(G, p->adjacency_vertex_index, visited);
//         }
//         p = p->next;
//     }
// }
// void DFSTraverse(const ALGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS(G, i, visited);
//         }
//     }
// }
// // // BFS
// // void BFSTraverse(const ALGraph& G) {
// //     bool* visited = new bool[G.num_vertex];
// //     for (int i = 0; i < G.num_vertex; ++i) {
// //         visited[i] = false;
// //     }
// //     queue<int> assist_queue;
// //     int current_vertex_index;
// //     EdgeNode* p = nullptr;
// //     for (int i = 0; i < G.num_vertex; ++i) {
// //         if (!visited[i]) {
// //             assist_queue.push(i);
// //             while (!assist_queue.empty()) {
// //                 current_vertex_index = assist_queue.front();
// //                 visitVertex(G, current_vertex_index, visited);
// //                 assist_queue.pop();
// //                 p = G.adjacent_list[current_vertex_index].first;
// //                 while (p) {
// //                     if (!visited[p->adjacency_vertex_index]) {
// //                         assist_queue.push(p->adjacency_vertex_index);
// //                     }
// //                     p = p->next;
// //                 }
// //             }
// //         }
// //     }
// //     delete[] visited;
// // }
// // BFS
// void BFSTraverse(const ALGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex_index;   
//     EdgeNode* p = nullptr;      // traverse edge_node
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 visitVertex(G, current_vertex_index, visited);
//                 assist_queue.pop();
//                 p = G.adjacent_list[current_vertex_index].first;
//                 while (p) {
//                     if (!visited[p->adjacency_vertex_index]) {
//                         assist_queue.push(p->adjacency_vertex_index);
//                     }
//                     p = p->next;
//                 }
//             }
//         }
//     }
//     delete[] visited;
// }

// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;

// #define MAXSIZE     100
// #define INFINITY    65535

// using VertexType = char;
// using EdgeType = int;
// typedef struct EdgeNode {
//     EdgeType    info;
//     int         adjacency_vertex_index;
//     EdgeNode*   next;
// } EdgeNode;
// typedef struct {
//     VertexType  data;
//     EdgeNode*   first;
// } VertexNode, AdjList[MAXSIZE];
// typedef struct {
//     AdjList     adjList;
//     int         num_vertex;
//     int         num_edge;
// } AdjGraph;
// // create directed graph
// void createDG(AdjGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjList[i].data;
//         G.adjList[i].first = nullptr;
//     }
//     int source, destination;
//     EdgeNode* current_edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         current_edge = new EdgeNode;
//         current_edge->adjacency_vertex_index = destination;
//         current_edge->next = G.adjList[source].first;
//         G.adjList[source].first = current_edge;
//     }
// }
// // create undirected graph 
// void createUG(AdjGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjList[i].data;
//         G.adjList[i].first = nullptr;
//     }
//     int source, destination;
//     EdgeNode* current_edge;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         current_edge = new EdgeNode;
//         current_edge->adjacency_vertex_index = destination;
//         current_edge->next = G.adjList[source].first;
//         G.adjList[source].first = current_edge;
//         current_edge = new EdgeNode;
//         current_edge->adjacency_vertex_index = source;
//         current_edge->next = G.adjList[destination].first;
//         G.adjList[destination].first = current_edge;
//     }
// }
// // create directed net
// void createDN(AdjGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjList[i].data;
//         G.adjList[i].first = nullptr;
//     }
//     int source, destination;
//     EdgeType value;
//     EdgeNode* current_edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         current_edge = new EdgeNode;
//         current_edge->info = value;
//         current_edge->adjacency_vertex_index = destination;
//         current_edge->next = G.adjList[source].first;
//         G.adjList[source].first = current_edge;
//     }
// }
// // create undirected net
// void createUN(AdjGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjList[i].data;
//         G.adjList[i].first = nullptr;
//     }
//     int source, destination;
//     EdgeType value;
//     EdgeNode* current_edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         current_edge = new EdgeNode;
//         current_edge->info = value;
//         current_edge->adjacency_vertex_index = destination;
//         current_edge->next = G.adjList[source].first;
//         G.adjList[source].first = current_edge;
//         current_edge = new EdgeNode;
//         current_edge->info = value;
//         current_edge->adjacency_vertex_index = source;
//         current_edge->next = G.adjList[destination].first;
//         G.adjList[destination].first = current_edge;
//     }
// }
// // visit vertex 
// void visitVertex(const AdjGraph& G, const int& v, bool*& visited) {
//     cout << G.adjList[v].data << endl;
//     visited[v] = true;
// }
// // Depth First Search graph
// void DFS_G(const AdjGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     EdgeNode* traverse_ptr = G.adjList[v].first;
//     while (traverse_ptr) {
//         if (!visited[traverse_ptr->adjacency_vertex_index]) {
//             DFS_G(G, traverse_ptr->adjacency_vertex_index, visited);
//         }
//         traverse_ptr = traverse_ptr->next;
//     }
// }
// void DFS_G(const AdjGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS_G(G, i, visited);
//         }
//     }
//     delete[] visited;
// }
// // Depth First Search net 
// void DFS_N(const AdjGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     EdgeNode* traverse_ptr = G.adjList[v].first;
//     while (traverse_ptr) {
//         if (!visited[traverse_ptr->adjacency_vertex_index]) {
//             DFS_N(G, traverse_ptr->adjacency_vertex_index, visited);
//         }
//         traverse_ptr = traverse_ptr->next;
//     }
// }
// void DFS_N(const AdjGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS_G(G, i, visited);
//         }
//     }
//     delete[] visited;
// }
// // Breadth First Search graph
// void BFS_G(const AdjGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     EdgeNode* traverse_ptr;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 traverse_ptr = G.adjList[assist_queue.front()].first;
//                 assist_queue.pop();
//                 while (traverse_ptr) {
//                     if (!visited[traverse_ptr->adjacency_vertex_index]) {
//                         visitVertex(G, traverse_ptr->adjacency_vertex_index, visited);
//                         assist_queue.push(traverse_ptr->adjacency_vertex_index);
//                     }
//                     traverse_ptr = traverse_ptr->next;
//                 }
//             }
//         }
//     }
//     delete[] visited;
// }
// // Breath First Search net
// void BFS_N(const AdjGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     EdgeNode* traverse_ptr;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 traverse_ptr = G.adjList[assist_queue.front()].first;
//                 assist_queue.pop();
//                 while (traverse_ptr) {
//                     if (!visited[traverse_ptr->adjacency_vertex_index]) {
//                         visitVertex(G, traverse_ptr->adjacency_vertex_index, visited);
//                         assist_queue.push(traverse_ptr->adjacency_vertex_index);
//                     }
//                     traverse_ptr = traverse_ptr->next;
//                 }
//             }
//         }
//     }
//     delete[] visited;
// }

// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;
// #define MAXSIZE     100
// #define INFINITY    65535
// using VertexType    = char;
// using EdgeType      = int;
// typedef struct EdgeNode {
//     EdgeType    info;
//     int         adjacency_vertex_index;
//     EdgeNode*   next;
// } EdgeNode;
// typedef struct {
//     VertexType  data;
//     EdgeNode*   first;
// } VertexNode, AdjacencyList[MAXSIZE];
// typedef struct {
//     AdjacencyList   adjacency_list;
//     int             num_vertex;
//     int             num_edge;
// } AdjacencyGraph;
// // create directed adjacency graph
// void createDG(AdjacencyGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first = nullptr;
//     }
//     int source = 0, destination = 0;
//     EdgeNode* current_edge = nullptr; 
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         current_edge = new EdgeNode;
//         current_edge->adjacency_vertex_index = destination;
//         current_edge->next = G.adjacency_list[source].first;
//         G.adjacency_list[source].first = current_edge;
//     }
// }
// // create undirected adjacency graph
// void createUG(AdjacencyGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first = nullptr;
//     }
//     int source = 0, destination = 0;
//     EdgeNode* current_edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         current_edge = new EdgeNode;
//         current_edge->adjacency_vertex_index = destination;
//         current_edge->next = G.adjacency_list[source].first;
//         G.adjacency_list[source].first = current_edge->next;
//         current_edge = new EdgeNode;
//         current_edge->adjacency_vertex_index = source;
//         current_edge->next = G.adjacency_list[destination].first;
//         G.adjacency_list[destination].first = current_edge;
//     }
// }
// // create directed adjacency net
// void createDN(AdjacencyGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first = nullptr;
//     }
//     int source = 0, destination = 0, value = 0;
//     EdgeNode* current_edge = nullptr;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         current_edge = new EdgeNode;
//         current_edge->info = value;
//         current_edge->adjacency_vertex_index = source;
//         current_edge->next = G.adjacency_list[source].first;
//         G.adjacency_list[source].first = current_edge;
//     }
// }
// // create undirected adjacency net
// void createUN(AdjacencyGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.adjacency_list[i].data;
//         G.adjacency_list[i].first = nullptr;
//     }
//     int source = 0, destination = 0, value = 0;
//     EdgeNode* current_edge;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         current_edge = new EdgeNode;
//         current_edge->info = value;
//         current_edge->adjacency_vertex_index = destination;
//         current_edge->next = G.adjacency_list[source].first;
//         G.adjacency_list[source].first = current_edge;
//         current_edge = new EdgeNode;
//         current_edge->info = value;
//         current_edge->adjacency_vertex_index = source;
//         current_edge->next = G.adjacency_list[destination].first;
//         G.adjacency_list[destination].first = current_edge;
//     }
// }
// // visit a vertex
// void visitVertex(const AdjacencyGraph& G, const int& v, bool*& visited) {
//     cout << G.adjacency_list[v].data << endl;
//     visited[v] = true;
// }
// // Depth First Search a graph connectivity component
// void DFS(const AdjacencyGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     EdgeNode* traverse_ptr = G.adjacency_list[v].first;
//     while (traverse_ptr) {
//         if (!visited[traverse_ptr->adjacency_vertex_index]) {
//             DFS(G, traverse_ptr->adjacency_vertex_index, visited);
//         }
//         traverse_ptr = traverse_ptr->next;
//     }
// }
// // Depth First Search all graph & net connectivity component
// void DFSTraverse(const AdjacencyGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS(G, i, visited);
//         }
//     }
// delete[] visited;
// }
// // Breadth First Search all graph & net connectivity component
// void BFSTraverse(const AdjacencyGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     EdgeNode* current_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_edge = G.adjacency_list[assist_queue.front()].first;
//                 assist_queue.pop();
//                 while (current_edge) {
//                     if (!visited[current_edge->adjacency_vertex_index]) {
//                         visitVertex(G, current_edge->adjacency_vertex_index, visited);
//                         assist_queue.push(current_edge->adjacency_vertex_index);
//                     }
//                     current_edge = current_edge->next;
//                 }
//             }
//         }
//     }
// delete[] visited;
// }

// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;
// #define MAXSIZE     100
// #define INFINITY    65535
// using VertexType    = char;
// using EdgeType      = int;
// typedef struct {
//     VertexType  vertex[MAXSIZE];
//     EdgeType    edge[MAXSIZE][MAXSIZE];
//     int         num_vertex;
//     int         num_edge;
// } MatrixGraph;
// // generate matrix directed graph
// void createDG(MatrixGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = 0;
//         }
//     }
//     int source = 0, destination = 0;
//     for (int i = 0; i <G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = 1;
//     }
// }
// // generate matrix undirected graph
// void createUG(MatrixGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = 0;
//         }
//     }
//     int source = 0, destination = 0;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = G.edge[destination][source] = 1;
//     }
// }
// // generate matrix directed net
// void createDN(MatrixGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = INFINITY;
//         }
//     }
//     int source = 0, destination = 0, value = 0;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = value;
//     }
// }
// // generate matrix undirected net
// void createUN(MatrixGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = INFINITY;
//         }
//     }
//     int source = 0, destination = 0, value = 0;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = G.edge[destination][source] = value;
//     } 
// }
// // visit a Vertex
// void visitVertex(const MatrixGraph& G, const int& v, bool*& visited) {
//     cout << G.vertex[v] << endl;
//     visited[v] = true;
// }
// // graph Depth First Search a connectivity component
// void DFS_G(const MatrixGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (G.edge[v][i] && !visited[i]) {
//             DFS_G(G, i, visited);
//         }
//     }
// }
// // graph Depth First Search all connectivity component
// void DFSTraverse_G(const MatrixGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS_G(G, i, visited);
//         }
//     }
// delete[] visited;
// }
// // net Depth First Search a connectivity component
// void DFS_N(const MatrixGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (G.edge[v][i] != INFINITY && !visited[i]) {
//             DFS_N(G, i, visited);
//         }
//     }
// }
// // net Depth First Search all connectivity component
// void DFSTraverse_N(const MatrixGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS_N(G, i, visited);
//         }
//     }
// delete[] visited;
// }
// // graph Breadth First Search all connectivity component
// void BFSTraverse_G(const MatrixGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int>  assist_queue;
//     int         current_vertex;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (G.edge[current_vertex][j] && !visited[j]) {
//                         visitVertex(G, j, visited);
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
// delete[] visited;
// }
// // net Breadth First Search all connectivity component
// void BFSTraverse_N(const MatrixGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int>  assist_queue;
//     int         current_vertex;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (G.edge[current_vertex][j] != INFINITY && !visited[j]) {
//                         visitVertex(G, j, visited);
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
// delete[] visited;
// }

// #include <iostream>
// using namespace std;

// #define MAXSIZE     100
// #define INFINITY    65536

// using VertexType    = char;
// using EdgeType      = int;

// typedef struct EdgeNode {
//     EdgeType    length;
//     int         adjacency_vertex;
//     EdgeNode    *next_edge;
// } EdgeNode;

// typedef struct {
//     VertexType  info;
//     EdgeNode*   first_edge;
// } VertexNode;

// typedef struct {
//     VertexNode  *vertex_list;
//     EdgeNode    *edge_list;
//     int         num_vertex;
//     int         num_edge;
// } AdjacencyGraph;

// // delete adjacency list graph or net
// void DeleteDG(AdjacencyGraph &G) {
//     delete[] G.vertex_list;
//     delete[] G.edge_list;
// }

// // create adjacency list directed graph
// void CreateDG(AdjacencyGraph &G) {
//     std::cin >> G.num_vertex >> G.num_edge;
//     G.vertex_list = new VertexNode[G.num_vertex];
//     G.edge_list = new EdgeNode[G.num_edge];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         G.vertex_list[i].first_edge = nullptr;
//     }
//     int source = 0, destination = 0;
//     for (int i = 0; i < G.num_edge; ++i) {
//         std::cin >> source >> destination;
//         G.edge_list[i].adjacency_vertex = destination;
//         G.edge_list[i].next_edge = G.vertex_list[source].first_edge;
//         G.vertex_list[source].first_edge = &(G.edge_list[i]);
//     }
// }

// // create adjacency list undirected graph
// void CreateUG(AdjacencyGraph &G) {
//     std::cin >> G.num_vertex >> G.num_edge;
//     G.vertex_list = new VertexNode[G.num_vertex];
//     G.edge_list = new EdgeNode[G.num_edge * 2];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         G.vertex_list[i].first_edge = nullptr;
//     }
//     int source = 0, destination = 0;
//     for (int i = 0; i < G.num_edge * 2; i = i + 2) {
//         std::cin >> source >> destination;
//         G.edge_list[i].adjacency_vertex = destination;
//         G.edge_list[i].next_edge = G.vertex_list[source].first_edge;
//         G.vertex_list[source].first_edge = &(G.edge_list[i]);
//         G.edge_list[i + 1].adjacency_vertex = source;
//         G.edge_list[i + 1].next_edge = G.vertex_list[destination].first_edge;
//         G.vertex_list[destination].first_edge = &(G.edge_list[i + 1]);
//     }
// }

// // create adjacency list directed net
// void CreateDN(AdjacencyGraph &N) {
//     std::cin >> N.num_vertex >> N.num_edge;
//     N.vertex_list = new VertexNode[N.num_vertex];
//     N.edge_list = new EdgeNode[N.num_edge * 2];
//     for (int i = 0; i < N.num_vertex; ++i) {
//         N.vertex_list[i].first_edge = nullptr;
//     }
//     int source = 0, destination = 0, value = 0;
//     for (int i = 0; i < N.num_edge; ++i) {
//         std::cin >> source >> destination >> value;
//         N.edge_list[i].length = value;
//         N.edge_list[i].adjacency_vertex = destination;
//         N.edge_list[i].next_edge = N.vertex_list[source].first_edge;
//         N.vertex_list[source].first_edge = &(N.edge_list[i]);
//     }
// }   

// // create adjacency list undirected net
// void CreateUN(AdjacencyGraph &N) {
//     std::cin >> N.num_vertex >> N.num_edge;
//     N.vertex_list = new VertexNode[N.num_vertex];
//     N.edge_list = new EdgeNode[N.num_edge * 2];
//     for (int i = 0; i < N.num_vertex; ++i) {
//         N.vertex_list[i].first_edge = nullptr;
//     }
//     int source = 0, destination = 0, value = 0;
//     for (int i = 0; i < N.num_edge * 2; i = i + 2) {
//         std::cin >> source >> destination >> value;
//         N.edge_list[i].length = N.edge_list[i + 1].length = value;
//         N.edge_list[i].adjacency_vertex = destination;
//         N.edge_list[i].next_edge = N.vertex_list[source].first_edge;
//         N.vertex_list[source].first_edge = &(N.edge_list[i]);
//         N.edge_list[i + 1].adjacency_vertex = source;
//         N.edge_list[i + 1].next_edge = N.vertex_list[destination].first_edge;
//         N.vertex_list[destination].first_edge = &(N.edge_list[i + 1]);
//     }
// }

// chatGPT
#include <iostream>
#include <vector>

const int MAXSIZE = 100;
const int INFINITY = 65536;

struct Edge {
    int adjacency_vertex;
    int length;
};

struct Vertex {
    char info;
    std::vector<Edge> edges;
};

enum GraphType {
    DIRECTED,
    UNDIRECTED
};

enum WeightType {
    UNWEIGHTED,
    WEIGHTED
};

class AdjacencyGraph {
public:
    AdjacencyGraph(int num_vertex, int num_edge) {
        vertex_list.resize(num_vertex);
        edge_list.resize(num_edge);
        this->num_vertex = num_vertex;
        this->num_edge = num_edge;
    }

    void add_edge(int source, int destination, int length = 0) {
        Edge edge;
        edge.adjacency_vertex = destination;
        edge.length = length;
        vertex_list[source].edges.push_back(edge);
        if (type == UNDIRECTED) {
            Edge reverse_edge;
            reverse_edge.adjacency_vertex = source;
            reverse_edge.length = length;
            vertex_list[destination].edges.push_back(reverse_edge);
        }
    }

    void set_type(GraphType type) {
        this->type = type;
    }

    void set_weight_type(WeightType weight_type) {
        this->weight_type = weight_type;
    }

    void print() {
        std::cout << "Number of vertices: " << num_vertex << std::endl;
        std::cout << "Number of edges: " << num_edge << std::endl;
        for (int i = 0; i < num_vertex; i++) {
            std::cout << "Vertex " << i << ": " << vertex_list[i].info << std::endl;
            std::cout << "Edges: ";
            for (auto edge : vertex_list[i].edges) {
                std::cout << edge.adjacency_vertex;
                if (weight_type == WEIGHTED) {
                    std::cout << " (" << edge.length << ")";
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<Vertex> vertex_list;
    std::vector<Edge> edge_list;
    int num_vertex;
    int num_edge;
    GraphType type;
    WeightType weight_type;
};