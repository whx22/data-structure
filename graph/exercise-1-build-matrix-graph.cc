// #include <iostream>
// using namespace std;

// #define INFINITY 65535
// #define MAXSIZE 100

// using vertexType = char;
// using edgeType = int;
// typedef struct {
//     vertexType  vertex[MAXSIZE];
//     edgeType    edge[MAXSIZE][MAXSIZE];
//     int         vertex_num;
//     int         edge_num;
// } MatrixGraph;

// // 无向图
// void createMatrixGraph(MatrixGraph& MG) {
//     cin >> MG.vertex_num >> MG.edge_num;
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         cin >> MG.vertex[i];
//     }
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         for (int j = 0; j < MG.vertex_num; ++j) {
//             MG.edge[i][j] = 0;
//         }
//     }
//     int s, e;
//     for (int i = 0; i < MG.edge_num; ++i) {
//         cin >> s >> e;
//         MG.edge[s][e] = MG.edge[e][s] = 1;
//     }
// }

// // 有向图
// void createMatrixGraph(MatrixGraph& MG) {
//     cin >> MG.vertex_num >> MG.edge_num;
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         cin >> MG.vertex[i];
//     }
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         for (int j = 0; j < MG.vertex_num; ++j) {
//             MG.edge[i][j] = 0;
//         }
//     }
//     int s, e;
//     for (int i = 0; i < MG.edge_num; ++i) {
//         cin >> s >> e;
//         MG.edge[s][e] = 1;
//     }
// }

// // 无向网
// void createMatrixGraph(MatrixGraph& MG) {
//     cin >> MG.vertex_num >> MG.edge_num;
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         cin  >> MG.vertex[i];
//     }
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         for (int j = 0; j < MG.vertex_num; ++j) {
//             MG.edge[i][j] = INFINITY;
//         }
//     }
//     int s, e, value;
//     for (int i = 0; i < MG.edge_num; ++i) {
//         cin >> s >> e >> value;
//         MG.edge[s][e] = MG.edge[e][s] = value;
//     }
// }

// // 有向网
// void createMatrixGraph(MatrixGraph& MG) {
//     // 1. record the number of vertices and edges
//     cin >> MG.vertex_num >> MG.edge_num;

//     // 2. record the values for each vertex
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         cin >> MG.vertex[i];
//     }

//     // 3. initialize the value of each edge
//     for (int i = 0; i < MG.vertex_num; ++i) {
//         for (int j = 0; j < MG.vertex_num; ++j) {
//             MG.edge[i][j] = INFINITY;
//         }
//     }

//     // 4. record the values of each edge
//     int s, e, value;
//     for (int i = 0; i < MG.edge_num; ++i) {
//         cin >> s >> e >> value;
//         MG.edge[s][e] = value;
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
// typedef struct {
//     VertexType  vertex[MAXSIZE];
//     EdgeType    edge[MAXSIZE][MAXSIZE];
//     int         num_vertex;
//     int         num_edge;
// } MatrixGraph;

// // undirected graph
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
//     int source, destination;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = 1;
//         G.edge[destination][source] = 1;
//     }
// }
// // directed graph
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
//     int source, destination;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = 1;
//     }
// }
// // undirected net
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
//     int source, destination, value;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = value;
//         G.edge[destination][source] = value;
//     }
// }
// // directed net
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
//     int source, destination, value;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = value;
//     }
// }
// void visitVertex(const MatrixGraph& G, const int& v, bool*& visited) {
//     cout << G.vertex[v] << endl;
//     visited[v] = true;
// }
// // graph DFS
// void DFS_G(const MatrixGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (G.edge[v][i] != 0 && !visited[i]) {
//             DFS_G(G, i, visited);
//         }
//     }
// }
// void DFSTraverse_G(const MatrixGraph& G) {
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
// // net DFS
// void DFS_N(const MatrixGraph& G, const int& v, bool*& visited) {
//     visitVertex(G, v, visited);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (G.edge[v][i] != INFINITY && !visited[i]) {
//             DFS_G(G, i, visited);
//         }
//     }
// }
// void DFSTraverse_N(const MatrixGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i= 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS_N(G, i, visited);
//         }
//     }
//     delete[] visited;
// }
// // graph BFS
// void BFSTraverse_G(const MatrixGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex_index;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 visitVertex(G, current_vertex_index, visited);
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (G.edge[current_vertex_index][j] != 0 && !visited[i]) {
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
//     delete[] visited;
// }
// // net BFS
// void BFSTraverse_N(const MatrixGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex_index;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 visitVertex(G, current_vertex_index, visited);
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (G.edge[current_vertex_index][j] != INFINITY && !visited[i]) {
//                         assist_queue.push(j);
//                     }
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
// typedef struct {
//     VertexType  vertex[MAXSIZE];
//     EdgeType    edge[MAXSIZE][MAXSIZE];
//     int         num_vertex;
//     int         num_edge;
// } MatrixGraph;

// // create directed graph
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
//     int source, destination;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = 1;
//     }
// }

// // create undirected graph
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
//     int source, destination;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = 1;
//         G.edge[destination][source] = 1;
//     }
// }

// // create directed net
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
//     int source, destination, value;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = value;
//     }
// }

// // create undirected net
// void createUN(MatrixGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++i) {
//             G.edge[i][j] = INFINITY;
//         }
//     }
//     int source, destination, value;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = value;
//         G.edge[destination][source] = value;
//     }
// }

// // visit a vertex
// void visit(const MatrixGraph& G, const int& v, bool*& visited) {
//     cout << G.vertex[v] << endl;
//     visited[v] = true;
// }
// // graph DFS a connectivity component
// void DFS_G(const MatrixGraph& G, const int& v, bool*& visited) {
//     visit(G, v, visited);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (G.edge[v][i] && !visited[i]) {
//             DFS_G(G, i, visited);
//         }
//     }
// }
// // graph DFS all connectivity component
// void DFSTraverse_G(const MatrixGraph& G) {
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
// // net DFS a connectivity component
// void DFS_N(const MatrixGraph& G, const int& v, bool*& visited) {
//     visit(G, v, visited);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (G.edge[v][i] != INFINITY && !visited[i]) {
//             DFS_N(G, i, visited);
//         }
//     }
// }
// // net DFS all connectivity component
// void DFSTraverse_N(const MatrixGraph& G) {
//     bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFS_N(G, i, visited);
//         }
//     }
//     delete[] visited;
// }
// // graph BFS
// void BFSTraverse_G(const MatrixGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
// queue<int> assist_queue;
// int current_vertex_index;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visit(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++i) {
//                     if (G.edge[current_vertex_index][j] != 0 && !visited[j]) {
//                         visit(G, j, visited);
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
// delete[] visited;
// }
// // net BFS
// void BFSTraverse_N(const MatrixGraph& G) {
// bool* visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
// queue<int> assist_queue;
// int current_vertex_index;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visit(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (G.edge[current_vertex_index][j] != INFINITY && !visited[j]) {
//                         visit(G, j, visited);
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
// delete[] visited;
// }

// #include <iostream>
// #include <queue>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define MAXSIZE     100
// #define INFINITY    65536
// using VertexType = char;
// using EdgeType = int;
// typedef struct {
//     VertexType  vertex[MAXSIZE];
//     EdgeType    edge[MAXSIZE][MAXSIZE];
//     int         num_vertex;
//     int         num_edge;
// } MatrixGraph;
// // create matrix directed graph 
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
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = 1;
//     }
// }
// // create matrix undirected graph
// void createUG(MatrixGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++i) {
//             G.edge[i][j] = 0;
//         }
//     }
//     int source = 0, destination = 0;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = G.edge[destination][source] = 1;
//     }
// }
// // create matrix directed net
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
// // create matrix undirected net
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
//     queue<int> assist_queue;
//     int current_vertex_index;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (G.edge[current_vertex_index][j] && !visited[j]) {
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
//     queue<int> assist_queue;
//     int current_vertex_index;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             visitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex_index = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (G.edge[current_vertex_index][j] != INFINITY && !visited[j]) {
//                         visitVertex(G, j, visited);
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
// delete[] visited;
// }
// /**
//  * @brief 
//  *  print the edge from source to destination in MatrixGraph G
//  * @param G 
//  * @param source 
//  * @param destination 
//  */
// void printEdge(const MatrixGraph& G, const int& source, const int& destination) {
//     cout << "( " << G.vertex[source] << ", " << G.vertex[destination] << " )" << endl;
// }
// /**
//  * @brief Prim algorithm : minimum spanning tree by directed or undirected net 
//  *  assist array and variable : 
//  *  1. lowCost array : record the minimum cost of vertex to spanning tree
//  *  2. vertexSet array : record whether the vertex is in spanning tree
//  *  3. current_vertex : record the vertex which has been visited current time
//  *  4. sum : record the sum of the weights of the minimal spanning tree
//  * 
//  *  main process : 
//  *  generate a minimum spanning tree in increment per vertex
//  *  1. initialize lowCost array & vertexSet array & v & sum
//  *  2. select the edge which has the minimum weight and the vertex of the edge has not been visited
//  *  3. update the lowCost array
//  *  4. repeat step 2 & 3 until all the vertexes have been set
//  *  5. return the sum of the weights of the minimal spanning tree
// */
// void prim(const MatrixGraph& G, const int& v, int& sum) {
//     bool        set[G.num_vertex];
//     EdgeType    low_cost[G.num_vertex];
//     int         adjacency_vertex[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         low_cost[i] = INFINITY;
//         if (G.edge[v][i] != INFINITY) {
//             adjacency_vertex[i] = v;
//         } else {
//             adjacency_vertex[i] = -1;
//         }
//     }
//     set[v] = true;
//     low_cost[v] = 0;
//     adjacency_vertex[v] = -1;
//     sum += low_cost[v];
    
//     int current_vertex = 0;
//     int minimum = INFINITY;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (low_cost[j] < minimum) {
//                 current_vertex = j;
//                 minimum = low_cost[current_vertex];
//             }
//         }
//         printEdge(G, adjacency_vertex[current_vertex], current_vertex);
//         set[current_vertex] = true;
//         sum += low_cost[current_vertex];
//         for (int j = 0; j < G.num_vertex; ++i) {
//             if (G.edge[current_vertex][j] < low_cost[j]) {
//                 adjacency_vertex[j] = current_vertex;
//                 low_cost[j] = G.edge[current_vertex][j];
//             }
//         }
//     }
// }
// // Kruskal algorithm : minimum spanning tree
// typedef struct Edge {
//     bool operator < (const Edge& e) {
//         return this->length < e.length;
//     }
//     bool operator > (const Edge& e) {
//         return this->length > e.length;
//     }
//     EdgeType    length;
//     int         source;
//     int         destination;
// } Edge;
// // disjoint set union algorithm
// // find v set' root and pass compression
// int Find(int* dsu, int v) {
//     if (dsu[v] < 0) {
//         return v;
//     } else {
//         return dsu[v] = Find(dsu, dsu[v]);   // pass compression
//     }
// }
// void Union(int* dsu, int x, int y) {
//     x = Find(dsu, x);
//     y = Find(dsu, y);
//     if (x == y) {
//         return;
//     } else {
//         if (dsu[x] < dsu[y]) {
//             dsu[x] += dsu[y];
//             dsu[y] = x;
//         } else {
//             dsu[y] += dsu[x];
//             dsu[x] = y;
//         }
//     }
// }
// int Count(int* dsu, int v) {
//     return -dsu[Find(dsu ,v)];
// }
// #include <algorithm>
// void Kruskal(const MatrixGraph& G, int& sum) {
//     Edge edges[G.num_edge];
//     int  dsu[G.num_vertex];
//     sort(edges[0], edges[G.num_edge]);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         dsu[i] = -1;    // initialize disjoint set union, every vertex is a set
//     }
//     int m, n;
//     for (int i = 0; i < G.num_edge; ++i) {
//         m = Find(dsu, edges[i].source);
//         n = Find(dsu, edges[i].destination);
//         if (m != n) {
//             Union(dsu, m, n);
//             sum += edges[i].length;
//             cout << "( " <<  edges[i].source << ", " << edges[i].destination << " ) " \
//                 << "length = " << edges[i].length << endl;
//         }
//     }
// }
// // // dijkstra algorithm calculate source vertex to each vertex shortest path and distance
// // void Dijkstra(const MatrixGraph& G, const int& source, int*& distance, int*& path) {
// //     bool set[G.num_vertex];
// //     for (int i = 0; i < G.num_vertex; ++i) {
// //         set[i] = false;
// //         distance[i] = G.edge[source][i];
// //         if (distance[i] != INFINITY) {
// //             path[i] = source;
// //         } else {
// //             path[i] = -1;
// //         }
// //     }
// //     set[source] = true;
// //     distance[source] = 0;
// //     path[source] = -1;

// //     int current_vertex = source;
// //     int minimum = INFINITY;
// //     for (int i = 0; i < G.num_vertex - 1; ++i) {
// //         minimum = INFINITY;
// //         for (int j = 0; j < G.num_vertex; ++j) {
// //             if (!set[j] && distance[j] < minimum) {
// //                 current_vertex = j;
// //                 minimum = distance[current_vertex];
// //             }
// //         }
// //         set[current_vertex] = true;
// //         for (int j = 0; j < G.num_vertex; ++j) {
// //             if (!set[j] && distance[current_vertex] + G.edge[current_vertex][j] < distance[j]) {
// //                 path[j] = current_vertex;
// //                 distance[j] = distance[current_vertex] + G.edge[current_vertex][j];
// //             }
// //         }
// //     }
// // }
// // // print the shortest distance and path by Dijkstra algorithm
// // void printShortPath(const MatrixGraph& G, const int& source, int* distance, int* path) {
// //     int traverse_node;
// //     for (int i = 0; i < G.num_vertex; ++i) {
// //         cout << distance[i] << endl;
// //         cout << G.vertex[i];
// //         traverse_node = i;
// //         while (traverse_node != -1) {
// //             cout << "<-" << G.vertex[path[traverse_node]];
// //             traverse_node = path[traverse_node];
// //         }
// //         cout << endl;
// //     }
// // }
// void Dijkstra(const MatrixGraph& G, const int& source, int*& distance, int*& path) {
//     bool set[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         distance[i] = G.edge[source][i];
//         if (distance[i] != INFINITY) {
//             path[i] = source;
//         } else {
//             path[i] = -1;
//         }
//     }
//     set[source] = true;
//     distance[source] = 0;
//     path[source] = -1;

//     int current_vertex = source;
//     int minimum = INFINITY;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && distance[j] < minimum) {
//                 current_vertex = j;
//                 minimum = distance[current_vertex];
//             }
//         }
//         set[current_vertex] = true;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && distance[current_vertex] + G.edge[current_vertex][j] < distance[j]) {
//                 path[j] = current_vertex;
//                 distance[j] = distance[current_vertex] + G.edge[current_vertex][j];
//             }
//         }
//     }
// }
// void printShortPath(const MatrixGraph& G, const int& source, int* distance, int* path) {
//     int traverse_node;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cout << distance[i] << endl;
//         cout << G.vertex[i];
//         traverse_node = i;
//         while (traverse_node != -1) {
//             cout << "<-" << G.vertex[path[traverse_node]];
//             traverse_node = path[traverse_node];
//         }
//     }
// }


// 2023/06/20
// #include <iostream>
// #include <algorithm>
// #include <queue>
// using namespace std;

// #define MAXSIZE     100
// #define INFINITY    65536

// using VertexType    = char;
// using EdgeType      = int;

// typedef struct {
//     VertexType  *vertex;
//     EdgeType    **edge;
//     int         num_vertex;
//     int         num_edge;
// } MatrixGraph;

// // delete matrix graph or net
// void Delete(MatrixGraph &G) {
//     delete[] G.vertex;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         delete[] G.edge[i];
//     }
//     delete[] G.edge;
// }

// // create matrix directed graph
// void CreateDG(MatrixGraph &G) {
//     cin >> G.num_vertex >> G.num_edge;
//     G.vertex = new VertexType[G.num_vertex];
//     G.edge = new EdgeType*[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         G.edge[i] = new EdgeType[G.num_vertex];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = 0;
//         }
//     }
//     int source = 0, destination = 0;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = 1;
//     }
// }

// // create matrix undirected graph
// void CreateUG(MatrixGraph &G) {
//     cin >> G.num_vertex >> G.num_edge;
//     G.vertex = new VertexType[G.num_vertex];
//     G.edge = new EdgeType*[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         G.edge[i] = new EdgeType[G.num_vertex];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = 0;
//         }
//     }
//     int source = 0, destination = 0;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> source >> destination;
//         G.edge[source][destination] = G.edge[destination][source] = 1;
//     }
// }

// // create matrix directed net
// void CreateDN(MatrixGraph &G) {
//     cin >> G.num_vertex >> G.num_edge;
//     G.vertex = new VertexType[G.num_vertex];
//     G.edge = new EdgeType*[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         G.edge[i] = new EdgeType[G.num_vertex];
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

// // create matrix undirected net
// void CreateUN(MatrixGraph &G) {
//     cin >> G.num_vertex >> G.num_edge;
//     G.vertex = new VertexType[G.num_vertex];
//     G.edge = new EdgeType*[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         G.edge[i] = new EdgeType[G.num_vertex];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = INFINITY;
//         }
//     }
//     int source = 0, destination = 0, value = 0;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = G.edge[destination][source] = 1;
//     }
// }

// // visit vertex
// void VisitVertex(const MatrixGraph &G, const int &v, bool *&visited) {
//     cout << G.vertex[v] << endl;
//     visited[v] = true;
// }

// // graph Depth First Search a connectivity component
// void DFSTraverse_G(const MatrixGraph &G, const int &v, bool *&visited) {
//     VisitVertex(G, v, visited);
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (G.edge[v][i] && !visited[i]) {
//             DFSTraverse_G(G, i, visited);
//         }
//     }
// }

// // graph Depth First Search all connectivity component
// void DFS_G(const MatrixGraph &G) {
// bool *visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFSTraverse_G(G, i, visited);
//         }
//     }
// delete[] visited;
// }

// // net Depth First Search a connective component
// void DFSTraverse_N(const MatrixGraph &N, const int &v, bool *&visited) {
//     VisitVertex(N, v, visited);
//     for (int i = 0; i < N.num_vertex; ++i) {
//         if (N.edge[v][i] != INFINITY && !visited[i]) {
//             DFSTraverse_N(N, i, visited);
//         }
//     }
// }

// // net Depth First Search all connective component
// void DFS_N(const MatrixGraph &N, const int &v, bool *&visited) {
// bool *visited = new bool[N.num_vertex];
//     for (int i = 0; i < N.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     for (int i = 0; i < N.num_vertex; ++i) {
//         if (!visited[i]) {
//             DFSTraverse_N(N, i, visited);
//         }
//     }
// delete[] visited;
// }

// // graph Breadth First Search all connective component
// void BFS_G(const MatrixGraph &G) {
// bool *visited = new bool[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex = 0;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         if (!visited[i]) {
//             VisitVertex(G, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < G.num_vertex; ++j) {
//                     if (!visited[j] && G.edge[current_vertex][j]) {
//                         VisitVertex(G, j, visited);
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
// delete[] visited;
// }

// // net Breadth First Search all connective component
// void BFS_N(const MatrixGraph &N) {
// bool* visited = new bool[N.num_vertex];
//     for (int i = 0; i < N.num_vertex; ++i) {
//         visited[i] = false;
//     }
//     queue<int> assist_queue;
//     int current_vertex;
//     for (int i = 0; i < N.num_vertex; ++i) {
//         if (!visited[i]) {
//             VisitVertex(N, i, visited);
//             assist_queue.push(i);
//             while (!assist_queue.empty()) {
//                 current_vertex = assist_queue.front();
//                 assist_queue.pop();
//                 for (int j = 0; j < N.num_vertex; ++j) {
//                     if (!visited[j] && N.edge[current_vertex][j] != INFINITY) {
//                         VisitVertex(N, j, visited);
//                         assist_queue.push(j);
//                     }
//                 }
//             }
//         }
//     }
// delete[] visited;
// }

// 2023/06/20 GPT
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stdexcept>
#include <limits>
#include <algorithm>
template <typename T>
class Graph {
public:
    Graph(bool directed = false, bool weighted = false)
        : directed_(directed), weighted_(weighted), num_vertices_(0) {}

    void AddVertex(const T& value) {
        vertices_.push_back(value);
        ++num_vertices_;
        adj_matrix_.resize(num_vertices_);
        for (auto& row : adj_matrix_) {
            row.resize(num_vertices_);
        }
    }

    void AddEdge(int source, int destination, int weight = 1) {
        if (source < 0 || source >= num_vertices_ ||
            destination < 0 || destination >= num_vertices_) {
            throw std::out_of_range("Invalid vertex index");
        }

        adj_matrix_[source][destination] = weight;
        if (!directed_) {
            adj_matrix_[destination][source] = weight;
        }
    }

    void DFS() {
        std::vector<bool> visited(num_vertices_, false);
        for (int i = 0; i < num_vertices_; ++i) {
            if (!visited[i]) {
                DFSHelper(i, visited);
            }
        }
    }

    void BFS() {
        std::vector<bool> visited(num_vertices_, false);
        for (int i = 0; i < num_vertices_; ++i) {
            if (!visited[i]) {
                BFSHelper(i, visited);
            }
        }
    }

    // prim minimum spanning tree(based edge)
    std::vector<std::pair<int, int>> PrimMST() {
        std::vector<bool> visited(num_vertices_, false);
        std::vector<int> distances(num_vertices_, std::numeric_limits<int>::max());
        std::vector<int> parent(num_vertices_, -1);
        std::vector<std::pair<int, int>> mst;

        distances[0] = 0;

        for (int i = 0; i < num_vertices_ - 1; ++i) {
            int u = -1;
            for (int j = 0; j < num_vertices_; ++j) {
                if (!visited[j] && (u == -1 || distances[j] < distances[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int v = 0; v < num_vertices_; ++v) {
                if (adj_matrix_[u][v] && !visited[v] && adj_matrix_[u][v] < distances[v]) {
                    distances[v] = adj_matrix_[u][v];
                    parent[v] = u;
                }
            }
        }

        // the number of edge + 1 = the number of vertex(in tree)
        for (int i = 1; i < num_vertices_; ++i) {
            mst.push_back({parent[i], i});
        }

        return mst;
    }

    // kruskal minimum spanning tree(base vertex)
    std::vector<std::pair<int, int>> KruskalMST() {
        std::vector<std::pair<int, std::pair<int, int>>> edges;
        std::vector<std::pair<int, int>> mst;
        std::vector<int> parent(num_vertices_);

        for (int i = 0; i < num_vertices_; ++i) {
            parent[i] = i;
            for (int j = 0; j < num_vertices_; ++j) {
                if (adj_matrix_[i][j]) {
                    edges.push_back({adj_matrix_[i][j], {i, j}});
                }
            }
        }

        std::sort(edges.begin(), edges.end());

        for (auto& edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;

            int parent_u = Find(parent, u);
            int parent_v = Find(parent, v);

            if (parent_u != parent_v) {
                mst.push_back({u, v});
                Union(parent, parent_u, parent_v);
            }
        }

        return mst;
    }
    
    // the shortest path between source to other vertices
    std::vector<int> Dijkstra(int source) {
        std::vector<int> distances(num_vertices_, std::numeric_limits<int>::max());
        std::vector<bool> visited(num_vertices_, false);
        distances[source] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;

            for (int v = 0; v < num_vertices_; ++v) {
                if (adj_matrix_[u][v] && distances[v] > distances[u] + adj_matrix_[u][v]) {
                    distances[v] = distances[u] + adj_matrix_[u][v];
                    pq.push({distances[v], v});
                }
            }
        }

        return distances;
    }

    // the shortest path between any two vertices
    std::vector<std::vector<int>> Floyd() {
        std::vector<std::vector<int>> dist(num_vertices_, std::vector<int>(num_vertices_, std::numeric_limits<int>::max()));

        for (int i = 0; i < num_vertices_; ++i) {
            dist[i][i] = 0;
        }

        for (int u = 0; u < num_vertices_; ++u) {
            for (int v= 0; v < num_vertices_; ++v) {
                if (adj_matrix_[u][v]) {
                    dist[u][v] = adj_matrix_[u][v];
                }
            }
        }

        for (int k = 0; k < num_vertices_; ++k) {
            for (int i = 0; i < num_vertices_; ++i) {
                for (int j = 0; j < num_vertices_; ++j) {
                    if (dist[i][k] != std::numeric_limits<int>::max() &&
                        dist[k][j] != std::numeric_limits<int>::max() &&
                        dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }

private:
    void DFSHelper(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        VisitVertex(vertex);

        for (int i = 0; i < num_vertices_; ++i) {
            if (adj_matrix_[vertex][i] && !visited[i]) {
                DFSHelper(i, visited);
            }
        }
    }

    void BFSHelper(int start, std::vector<bool>& visited) {
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            VisitVertex(vertex);

            for (int i = 0; i < num_vertices_; ++i) {
                if (adj_matrix_[vertex][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void VisitVertex(int vertex) {
        std::cout << vertices_[vertex] << std::endl;
    }

    int Find(std::vector<int>& parent, int i) {
        if (parent[i] == i) {
            return i;
        }
        return Find(parent, parent[i]);
    }

    void Union(std::vector<int>& parent, int u, int v) {
        parent[Find(parent, u)] = Find(parent, v);
    }

private:
    bool directed_;
    bool weighted_;
    int num_vertices_;
    std::vector<T> vertices_;
    std::vector<std::vector<int>> adj_matrix_;
};

enum class GraphType {
    DIRECTED,
    UNDIRECTED
};

enum class EdgeType {
    WEIGHTED,
    UNWEIGHTED
};

Graph<int> CreateGraph(GraphType type, EdgeType edge_type, int num_vertices, int num_edges) {
    Graph<int> graph(type == GraphType::DIRECTED, edge_type == EdgeType::WEIGHTED);

    for (int i = 0; i < num_vertices; ++i) {
        graph.AddVertex(i);
    }

    for (int i = 0; i < num_edges; ++i) {
        int source, destination, weight = 1;
        std::cin >> source >> destination;
        if (edge_type == EdgeType::WEIGHTED) {
            std::cin >> weight;
        }
        graph.AddEdge(source, destination, weight);
    }

    return graph;
}

int main() {
    int num_vertices, num_edges;
    std::cin >> num_vertices >> num_edges;

    Graph<int> graph = CreateGraph(GraphType::UNDIRECTED, EdgeType::UNWEIGHTED, num_vertices, num_edges);

    std::cout << "DFS:" << std::endl;
    graph.DFS();

    std::cout << "BFS:" << std::endl;
    graph.BFS();

    return 0;
} 
