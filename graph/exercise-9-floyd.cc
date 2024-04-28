/**
 * @file exercise_floyd.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// #include <iostream>
// // #include <vector>
// // #include <algorithm>
// using namespace std;

// #define MAXSIZE 100
// #define INFINITY 65535

// using VertexType = char;
// using EdgeType = int;

// typedef struct {
//     VertexType  vertex[MAXSIZE];
//     EdgeType    edge[MAXSIZE][MAXSIZE];
//     int         path[MAXSIZE][MAXSIZE];     // record the path vertex index
//     int         num_vertex;
//     int         num_edge;
// } MatrixGraph;
// void createU(MatrixGraph& G) {
//     cout << "Please input the number of vertex and edge :" << endl;
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cout << "Please input num." << i + 1 << " vertex value" << endl;
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = INFINITY;
//             G.path[i][j] = -1;
//         }
//     }
//     int source, destination, value;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cout << "Please input num." << i + 1 << " edge source, destination, value " << endl;
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = value;
//     }
// }
// void printSinglePath(const MatrixGraph& G, const int& source, const int& destination) {
//     cout << G.vertex[source] << "->" << G.vertex[destination] << endl;
// }
// void printPath(const MatrixGraph& G, const int& start, const int& end) {
//     if (G.path[start][end] == -1) {
//         printSinglePath(G, start, end);
//     } else {
//         int middle = G.path[start][end];
//         printPath(G, start, middle);
//         printPath(G, middle, end);
//     }
// }
// void Floyd(MatrixGraph& G) {
//     int distance[G.num_vertex][G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             distance[i][j] = G.edge[i][j];
//             G.path[i][j] = -1;
//         }
//     }
//     for (int mid = 0; mid < G.num_vertex; ++mid) {
//         for (int i = 0; i < G.num_vertex; ++i) {
//             for (int j = 0; j < G.num_vertex; ++j) {
//                 if (distance[i][mid] + distance[mid][j] < distance[i][j]) {
//                     distance[i][j] = distance[i][mid] + distance[mid][j];
//                     G.path[i][j] = mid;
//                 }
//             }
//         }
//     }
// }

// void test_1() {
//     MatrixGraph G;
//     createU(G);
//     Floyd(G);
//     printPath(G, 0, G.num_vertex - 1);
// }

// int main() {
//     test_1();
//     return EXIT_SUCCESS;
// }

// /**
//  * @brief print path by floyd algorithm calculate path table
//  * 
//  * @param Path 
//  * @param start 
//  * @param end 
//  */
// void printPath(const int** Path, const int& start, const int& end) {
//     if (Path[start][end] == -1) {
//         // print
//     } else {
//         int middle = Path[start][end];
//         printPath(Path, start, middle);
//         printPath(Path, middle, end);
//     }
// }

// /**
//  * @brief 
//  * 
//  * @param node_num 
//  * @param Matrix 
//  * @param Path
//  */
// void Floyd(const int& node_num, float** MatrixGraph, int** Path) {
//     // initialize the minimum_distance[][] & Path[][]
//     float distance[node_num][node_num]; // recode the minimum distance value
//     for (int i = 0; i < node_num; ++i) {
//         for (int j = 0; j < node_num; ++j) {
//             distance[i][j] = MatrixGraph[i][j];
//             Path[i][j] = -1;
//         }
//     }

//     // 每个节点作为中间节点, 判断每个节点是否能够缩短各节点间的距离
//     for (int mid = 0; mid < node_num; ++mid) {
//         for (int i = 0; i < node_num; ++i) {
//             for (int j = 0; j < node_num; ++j) {
//                 if (distance[i][mid] + distance[mid][j] < distance[i][j]) {
//                     distance[i][j] = distance[i][mid] + distance[mid][j];
//                     Path[i][j] = mid;
//                 }
//             }
//         }
//     }
// }

//// print the shortest path by Floyd algorithm Path[][]
//void PrintPath(const int**& Path, const int& start, const int& end) {
//    if (Path[start][end] == -1) {
//        // print
//    } else {
//        int mid = Path[start][end];
//        PrintPath(Path, start, mid);
//        PrintPath(Path, mid, end);
//    }
//}
//
//// calculate Path[][]
//void Floyd(const int& node_num, const double**& MatrixGraph, int**& Path) {
//    double distance[node_num][node_num];
//    for (int i = 0; i < node_num; ++i) {
//        for (int j = 0; j < node_num; ++j) {
//            distance[i][j] = MatrixGraph[i][j];
//            Path[i][j] = -1;
//        }
//    }
//    for (int mid = 0; mid < node_num; ++mid) {
//        for (int i = 0; i < node_num; ++i) {
//            for (int j = 0; j < node_num; ++j) {
//                if (distance[i][mid] + distance[mid][j] < distance[i][j]) {
//                    distance[i][j] = distance[i][mid] + distance[mid][j];
//                    Path[i][j] = mid;
//                }
//            }
//        }
//    }
//}

// #include <iostream>
// using namespace std;

// #define MAXSIZE     100
// #define INFINITY    65535

// using VertexType    = char;
// using EdgeType      = int;

// typedef struct {
//     VertexType  vertex[MAXSIZE];
//     EdgeType    edge[MAXSIZE][MAXSIZE];
//     int         path[MAXSIZE][MAXSIZE];
//     int         num_vertex;
//     int         num_edge;
// } MatrixGraph;

// void create(MatrixGraph& G) {
//     cin >> G.num_vertex >> G.num_edge;
//     for (int i = 0; i < G.num_vertex; ++i) {
//         cin >> G.vertex[i];
//     }
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             G.edge[i][j] = INFINITY;
//             G.path[i][j] = -1;
//         }
//     }
//     int source, destination, value;
//     for (int i = 0; i < G.num_edge; ++i) {
//         cin >> source >> destination >> value;
//         G.edge[source][destination] = value;
//         // if net is undirected add : G.edge[destination][source] = value;
//     }
// }

// void printSinglePath(const MatrixGraph& G, const int& source, const int& destination) {
//     cout << G.vertex[source] << "->" << G.vertex[destination] << endl;
// }

// void printPath(const MatrixGraph& G, const int& source, const int& destination) {
//     if (G.path[source][destination] == -1) {
//         printSinglePath(G, source, destination);
//     } else {
//         int middle = G.path[source][destination];
//         printPath(G, source, middle);
//         printPath(G, middle, destination);
//     }
// }

// void Floyd(MatrixGraph& G) {
//     int distance[G.num_vertex][G.num_vertex];
//     for (int i = 0; i < G.num_vertex; ++i) {
//         for (int j = 0; j < G.num_vertex; ++j) {
//             distance[i][j] = G.edge[i][j];
//             G.path[i][j] = -1;
//         }
//     }
//     for (int mid = 0; mid < G.num_vertex; ++mid) {
//         for (int i = 0; i < G.num_vertex; ++i) {
//             for (int j = 0; j < G.num_vertex; ++j) {
//                 if (distance[i][mid] + distance[mid][j] < distance[i][j]) {
//                     G.path[i][j] = mid;
//                     distance[i][j] = distance[i][mid] + distance[mid][j];
//                 }
//             }
//         }
//     }
// }

#include <iostream>
using namespace std;

#define MAXSIZE     100
#define INFINITY    65535

using VertexType    = char;
using EdgeType      = int;

typedef struct {
    VertexType  vertex[MAXSIZE];
    EdgeType    edge[MAXSIZE][MAXSIZE];
    int         distance[MAXSIZE][MAXSIZE];
    int         path[MAXSIZE][MAXSIZE];
    int         num_vertex;
    int         num_edge;
} MatrixGraph;

void create(MatrixGraph& G) {
    cin >> G.num_vertex >> G.num_edge;
    for (int i = 0; i < G.num_vertex; ++i) {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.edge[i][j] = INFINITY;
            G.distance[i][j] = INFINITY;
            G.path[i][j] = -1;
        }
    }
    int source = 0, destination = 0, value = 0;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> value;
        G.distance[source][destination] = G.edge[source][destination] = value;
    }
}

void printSingleEdge(const MatrixGraph& G, const int& source, const int& destination) {
    cout << "(" << G.vertex[source] << ", " << G.vertex[destination] << ")" << endl;
}

void printShortPath(const MatrixGraph& G, const int& source, const int& destination) {
    if (G.path[source][destination] == -1) {
        printSingleEdge(G, source, destination);
    } else {
        int middle = G.path[source][destination];
        printShortPath(G, source, middle);
        printShortPath(G, middle, destination);
    }
}

void Floyd(MatrixGraph& G) {
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            G.distance[i][j] = G.edge[i][j];
            G.path[i][j] = -1;
        }
    }
    for (int mid = 0; mid < G.num_vertex; ++mid) {
        for (int i = 0; i < G.num_vertex; ++i) {
            for (int j = 0; j < G.num_vertex; ++j) {
                if (G.distance[i][mid] + G.distance[mid][j] < G.distance[i][j]) {
                    G.path[i][j] = mid;
                    G.distance[i][j] = G.distance[i][mid] + G.distance[mid][j];
                }
            }
        }
    }
}