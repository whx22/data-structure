#include <iostream>
using namespace std;

#define MAXSIZE 100
#define INFINITY 65535

using VertexType = char;
using EdgeType = int;

typedef struct {
    VertexType vertex[MAXSIZE];
    EdgeType edge[MAXSIZE][MAXSIZE];
    int num_vertex;
    int num_edge;
} MatrixGraph;

void createN(MatrixGraph &G) {
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
    for (int i = 0; i < G.num_vertex; ++i) {
        cout << "Please input num." << i + 1 << " edge source, destination, value " << endl;
        cin >> source >> destination >> value;
        G.edge[source][destination] = value;
    }
}

// // best template
// void Dijkstra(const MatrixGraph &G, const int &v, int *&distance, int *&path) {
//     // 1. initialize set array & distance array & path array
//     bool set[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         distance[i] = G.edge[v][i];
//         if (distance[i] != INFINITY) {
//             path[i] = v;
//         } else {
//             path[i] = -1;
//         }
//     }
//     set[v] = true;
//     distance[v] = 0;
//     path[v] = -1;

//     int current_vertex_index = v;
//     int minimum = INFINITY;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         // 2. select minimum distance edge to non-access node
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && distance[j] < minimum) {
//                 current_vertex_index = j;
//                 minimum = distance[current_vertex_index];
//             }
//         }
//         set[current_vertex_index] = true;
//         // 3. update the distance array by the newly merge vertex
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if (!set[j] && distance[current_vertex_index] + G.edge[current_vertex_index][j] < distance[j]) {
//                 distance[j] = distance[current_vertex_index] + G.edge[current_vertex_index][j];
//                 path[j] = current_vertex_index;
//             }
//         }
//     } // 4. repeat step 2 & 3 until all vertex have been set
// }

// void pathShortPath(const MatrixGraph &G, const int &v, int *&distance, int *&path) {
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cout << "The shortest path from "\
//         << G.vertex[v] << " to " << G.vertex[i] << " is " << distance[i] << endl;
//         cout << "The path is : " << G.vertex[i];
//         int j = i;
//         while (j != -1) {
//             cout << " <- " << G.vertex[path[j]];
//             j = path[j];
//         }
//         cout << endl;
//     }
// }

// // test code 
// void test_1() {
//     MatrixGraph G;
//     createN(G);
//     int *distance = new int[G.num_vertex];
//     int *path = new int[G.num_vertex];
//     Dijkstra(G, 0, distance, path);
//     pathShortPath(G, 0, distance, path);
//     delete[] distance;
//     delete[] path;
// }

// int main() {
//     test_1();
//     return EXIT_SUCCESS;
// }

// void Dijkstra(const int& node_num, const float**& MatrixGraph, const int& start_node, \
//                 int* distance, int* path) {
//     // 1. initialize set flag array & distance array & path array
//     bool set[node_num];
//     for (int i = 0; i < node_num; ++i) {
//         set[i] = false;
//         distance[i] = MatrixGraph[start_node][i];
//         if (MatrixGraph[start_node][i] == INFINITY) {
//             path[i] = -1;
//         } else {
//             path[i] = start_node;
//         }
//     }
//     set[start_node] = true;
//     path[start_node] = -1;

//     int v;  // record the current access node
//     int minimum_distance = INFINITY;

//     for (int i = 0; i < node_num; ++i) {
//         // 2. select minimum distance edge to non-assess node and
//         // set the non-assess node corresponding to the minimum distance edge flag
//         minimum_distance = INFINITY;
//         for (int j = 0; j < node_num; ++j) {
//             if (set[j] == false && distance[j] < INFINITY) {
//                 v = j;
//                 minimum_distance = distance[v];
//             }
//         }
//         set[v] = true;

//         // 3. update the distance array & path array by the newly merge node
//         for (int j = 0; j < node_num; ++j) {
//             if (set[j] == false \
//                 && distance[v] + MatrixGraph[v][j] < distance[j]) {
//                 distance[j] = distance[v] + MatrixGraph[v][j];
//                 path[j] = v;
//             }
//         }
//     }   // 4. repeat step 2 & 3 until all vertexes have been set
// }

// void Dijkstra(const MatrixGraph& G, const int& v, int*& distance, int*& path) {
//     bool set[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         distance[i] = G.edge[v][i];
//         if (distance[i] != INFINITY) {
//             path[i] = v;
//         } else {
//             path[i] = -1;
//         }
//     }
//     set[v] = true;
//     distance[v] = 0;
//     path[v] = -1;
//
//     int minimum = INFINITY;
//     int current_vertex_index = v;
//     for (int i = 0; i < G.num_vertex - 1; ++i) {
//         minimum = INFINITY;
//         for (int j = 0; j < G.num_vertex; ++j)  {
//             if (!set[j] && distance[j] < minimum) {
//                 current_vertex_index = j;
//                 minimum = distance[j];
//             }
//         }
//         set[current_vertex_index] = true;
//         for (int j = 0; j < G.num_vertex; ++j) {
//             if ( !set[j] \
//                && distance[current_vertex_index] + G.edge[current_vertex_index][j] < distance[j]) {
//                 distance[j] = distance[current_vertex_index] + G.edge[current_vertex_index][j];
//                 path[j] = current_vertex_index;
//             }
//         }
//     }
// }

// dijkstra algorithm exercise 2
// void dijkstra(const MatrixGraph& G, const int& v, int*& distance, int*& path) {
//     bool set[G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         set[i] = false;
//         distance[i] = G.edge[v][i];
//         if (distance[i] != INFINITY) {
//             path[i] = v;
//         } else {
//             path[i] = -1;
//         }
//     }
//     set[v] = true;
//     distance[v] = 0;
//     path[v] = -1;

//     int current_vertex = v;
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

// dijkstra algorithm exercise 4
void dijkstra(const MatrixGraph& G, const int& v, int*& distance, int*& path) {
    bool set[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        set[i] = false;
        distance[i] = G.edge[v][i];
        if (distance[i] != INFINITY) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    set[v] = true;
    distance[v] = 0;
    path[v] = -1;

    int current_vertex = v;
    int minimum = INFINITY;
    for (int i = 0; i < G.num_vertex - 1; ++i) {
        minimum = INFINITY;
        for (int j = 0; j < G.num_vertex; ++j) {
            if (!set[j] && distance[j] < minimum) {
                current_vertex = j;
                minimum = distance[current_vertex];
            }
        }
        set[current_vertex] = true;
        for (int j = 0; j < G.num_vertex; ++j) {
            if (!set[j] && distance[current_vertex] + G.edge[current_vertex][j] < distance[j]) {
                path[j] = current_vertex;
                distance[j] = distance[current_vertex] + G.edge[current_vertex][j];
            }
        }
    }
}

// void printShortPath(const MatrixGraph& G, const int& source, const int*& distance, const int*& path) {
//     int traverse_node = 0;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cout << distance[i] << endl;
//         cout << G.vertex[i];
//         traverse_node = i;
//         while (traverse_node != -1) {
//             cout << " <- " << G.vertex[path[traverse_node]];
//             traverse_node = path[traverse_node];  
//         }
//     } 
// }

void printShortPath(const MatrixGraph& G, const int& source, const int*& distance, const int*& path) {
    int traverse_node = 0;
    for (int i = 0; i < G.num_vertex; ++i) {
        cout << distance[i] << endl;
        cout << G.vertex[i];
        traverse_node = i;
        while (traverse_node != -1) {
            cout << "<-" << G.vertex[path[traverse_node]];
            traverse_node = path[traverse_node];
        }
    }
}