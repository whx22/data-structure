/**
 * @brief Prim algorithm : 
 *  assist array and variable : 
 *  1. lowCost array    : record the minimum cost of vertex to spanning tree
 *  2. vertexSet array  : record whether the vertex is in spanning tree
 *  3. current_vertex   : record the vertex which has been visited current time
 *  4. sum              : record the sum of the weights of the minimal spanning tree
 * 
 *  main process : 
 *  generate a minimum spanning tree in increment per vertex
 *  1. initialize lowCost array & vertexSet array & v & sum
 *  2. select the edge which has the minimum weight and the vertex of the edge has not been visited
 *  3. update the lowCost array
 *  4. repeat step 2 & 3 until all the vertexes have been visited
 *  5. return the sum of the weights of the minimal spanning tree
*/
#include <iostream>
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

void Create(MatrixGraph& G) {
    cout << "Please input the number of vertex and edge :" << endl;
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cout << "Please input num." << i + 1 << " vertex value" << endl;
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = INFINITY;
        }
    }
    int source, destination, value;
    for (int i = 0; i < G.num_edge; ++i) {
        cout << "Please input num." << i + 1 << " edge source, destination, value " << endl;
        cin >> source >> destination >> value;
        G.edge[source][destination] = value;
    }
}

// // print a edge
// void printEdge(const MatrixGraph& G, const int& source, const int& destination) {
//     cout << "(" << G.vertex[source] << ", "
//     << G.vertex[destination] << ")" << endl;
// }

// prim best template
// void Prim(const MatrixGraph& G, const int& v, int& sum) {
//     bool set[G.num_vertex];
//     int lowCost[G.num_vertex];
//     int adjacency_vertex[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         lowCost[i] = G.edge[v][i];
//         if (G.edge[v][i] != INFINITY) {
//             adjacency_vertex[i] = v;
//         } else {
//             adjacency_vertex[i] = -1;
//         }
//     }
//     set[v] = true;
//     lowCost[v] = 0;
//     adjacency_vertex[v] = -1;
//     sum += lowCost[v];
//     int current_vertex_index = v;
//     int minimum = INFINITY;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && lowCost[j] < minimum) {
//                 current_vertex_index = j;
//                 minimum = lowCost[current_vertex_index];
//             }
//         }
//         printEdge(G, adjacency_vertex[current_vertex_index], current_vertex_index);
//         set[current_vertex_index] = true;
//         sum += lowCost[current_vertex_index];
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && G.edge[current_vertex_index][j] < lowCost[j]) {
//                 lowCost[j] = G.edge[current_vertex_index][j];
//                 adjacency_vertex[j] = current_vertex_index;
//             }
//         }
//     }
// }

// // prim exercise 1
// void Prim(const MatrixGraph& G, const int& v, int& sum) {
//     bool set[G.num_vertex];
//     int lowCost[G.num_vertex];
//     int adjVertex[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         lowCost[i] = G.edge[v][i];
//         if (lowCost[i] != INFINITY) {
//             adjVertex[i] = v;
//         } else {
//             adjVertex[i] = -1;
//         }
//     }
//     set[v] = true;
//     lowCost[v] = 0;
//     adjVertex[v] = -1;
//     sum += lowCost[v];

//     int current_vertex_index = v;
//     int minimum = INFINITY;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && lowCost[j] < minimum) {
//                 current_vertex_index = j;
//                 minimum = lowCost[current_vertex_index];
//             }
//         }
//         printEdge(G, adjVertex[current_vertex_index], current_vertex_index);
//         set[current_vertex_index] = true;
//         sum += lowCost[current_vertex_index];
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && G.edge[current_vertex_index][j] < lowCost[j]) {
//                 lowCost[j] = G.edge[current_vertex_index][j];
//                 adjVertex[j] = current_vertex_index;
//             }
//         }
//     }
// }

// void test_1() {
//     MatrixGraph G;
//     Create(G);
//     int sum = 0;
//     Prim(G, 0, sum);
//     cout << sum << endl;
// }

// int main() {
//     test_1();
//     return EXIT_SUCCESS;
// }

// // prim exercise 2
// void Prim(const MatrixGraph& G, const int& v, int& sum) {
// bool        set[G.num_vertex];
// EdgeType    lowCost[G.num_vertex];
// int         adjacency_vertex[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         lowCost[i] = G.edge[v][i];
//         if (G.edge[v][i] != INFINITY) {
//             adjacency_vertex[i] = v;
//         } else {
//             adjacency_vertex[i] = -1;
//         }
//     }
//     set[v] = true;
//     lowCost[v] = 0;
//     adjacency_vertex[v] = -1;
//     sum += lowCost[v];
// int current_vertex_index = v;
// int minimum = INFINITY;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (lowCost[j] < minimum) {
//                 current_vertex_index = j;
//                 minimum = lowCost[current_vertex_index];
//             }
//         }
//         printEdge(G, adjacency_vertex[current_vertex_index], current_vertex_index);
//         set[current_vertex_index] = true;
//         sum += lowCost[current_vertex_index];
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && G.edge[current_vertex_index][j] < lowCost[j]) {
//                 adjacency_vertex[j] = current_vertex_index;
//                 lowCost[j] = G.edge[current_vertex_index][j];
//             }
//         }
//     }
// }

// // prim exercise 3
// void Prim(const MatrixGraph& G, const int& v, int& sum) {
//     bool        set[G.num_vertex];
//     EdgeType    lowCost[G.num_vertex];
//     int         adjacency_vertex[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         lowCost[i] = G.edge[v][i];
//         if (lowCost[i] != INFINITY) {
//             adjacency_vertex[i] = v;
//         } else {
//             adjacency_vertex[i] = -1;
//         }
//     }
//     set[v] = true;
//     lowCost[v] = 0;
//     adjacency_vertex[v] = -1;
//     sum += lowCost[v];
//     int current_vertex_index;
//     int minimum = INFINITY;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (lowCost[j] < minimum) {
//                 current_vertex_index = j;
//                 minimum = lowCost[current_vertex_index];
//             }
//         }
//         printEdge(G, adjacency_vertex[current_vertex_index], current_vertex_index);
//         set[current_vertex_index] = true;
//         sum += lowCost[current_vertex_index];
//         for (int j = 0; j < G.num_vertex; ++i) {
//             if (!set[j] && G.edge[current_vertex_index][j] < lowCost[j]) {
//                 adjacency_vertex[j] = current_vertex_index;
//                 lowCost[j] = G.edge[current_vertex_index][j];
//             }
//         }
//     }
// }

// prim exercise 4
/**
 * @brief 
 *  print edge of matrix graph
 * @param G 
 * @param source 
 * @param destination 
 */
void printEdge(const MatrixGraph& G, const int& source, const int& destination) {
    cout << "( " << G.vertex[source] << ", " << G.vertex[destination] << " )" << endl; 
}

/**
 * @brief Prim algorithm : minimum spanning tree by directed or undirected net 
 *  assist array and variable : 
 *  1. lowCost array            : record the minimum cost of vertex to spanning tree
 *  2. vertexSet array          : record whether the vertex is in spanning tree
 *  3. adjacency vertex array   : record the adjacency vertex of the vertex in spanning tree
 *  4. current_vertex           : record the vertex which has been visited current time
 *  5. sum                      : record the sum of the weights of the minimal spanning tree
 * 
 *  main process : 
 *  generate a minimum spanning tree in increment per vertex
 *  1. initialize lowCost array & vertexSet array & adjacency vertex array & current vertex & sum
 *  2. select the edge which has the minimum weight and the vertex of the edge has not been visited
 *  3. update the lowCost array & adjacency vertex array
 *  4. repeat step 2 & 3 until all the vertexes have been set
 *  5. return the sum of the weights of the minimal spanning tree
*/
/**
 * @brief 
 *  Prim algorithm to generate a minimum spanning tree in increment per vertex
 * @param G : 
 * @param v : 
 * @param sum : 
 */
void Prim(const MatrixGraph& G, const int& v,int& sum) {
    bool        set[G.num_vertex];
    EdgeType    low_cost[G.num_vertex];
    int         adjacency_vertex[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        set[i] = false;
        low_cost[i] = G.edge[v][i];
        if (low_cost[i] != INFINITY) {
            adjacency_vertex[i] = v;
        } else {
            adjacency_vertex[i] = -1;
        }
    }
    set[v] = true;
    low_cost[v] = 0;
    sum += low_cost[v];
    adjacency_vertex[v] = -1;

    int current_vertex = 0;
    int minimum = INFINITY;
    for (int i = 0; i < G.num_vertex - 1; ++i) {
        minimum = INFINITY;
        for (int j = 0; j < G.num_vertex; ++j) {
            if (low_cost[j] < minimum) {
                current_vertex = j;
                minimum = low_cost[current_vertex];
            }
        }
        printEdge(G, adjacency_vertex[current_vertex], current_vertex);
        set[current_vertex];
        sum += low_cost[current_vertex];
        for (int j = 0; j < G.num_vertex; ++j) {
            if (G.edge[current_vertex][j] < low_cost[j]) {
                adjacency_vertex[j] = current_vertex;
                low_cost[j] = G.edge[current_vertex][j];
            }
        }
    }
}