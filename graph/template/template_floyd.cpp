/**
 * @file template_floyd.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief matrix net Floyd : the shortest path (Dynamic Planning Algorithm)
 * @version 0.1
 * @date 2023-05-02
 * 
 * @copyright Copyright (c) 2023
 * 
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
            G.path[i][j] = -1;
        }
    }
    int source, destination, value;
    for (int i = 0; i < G.num_edge; ++i) {
        cin >> source >> destination >> value;
        G.edge[source][destination] = value;
        // if net is undirected add : G.edge[destination][source] = value;
    }
}

void printSinglePath(const MatrixGraph& G, const int& source, const int& destination) {
    cout << G.vertex[source] << "->" << G.vertex[destination] << endl;
}

void printPath(const MatrixGraph& G, const int& source, const int& destination) {
    if (G.path[source][destination] == -1) {
        printSinglePath(G, source, destination);
    } else {
        int middle = G.path[source][destination];
        printPath(G, source, middle);
        printPath(G, middle, destination);
    }
}

void Floyd(MatrixGraph& G) {
    int distance[G.num_vertex][G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        for (int j = 0; j < G.num_vertex; ++j) {
            distance[i][j] = G.edge[i][j];
            G.path[i][j] = -1;
        }
    }
    for (int mid = 0; mid < G.num_vertex; ++mid) {
        for (int i = 0; i < G.num_vertex; ++i) {
            for (int j = 0; j < G.num_vertex; ++j) {
                if (distance[i][mid] + distance[mid][j] < distance[i][j]) {
                    G.path[i][j] = mid;
                    distance[i][j] = distance[i][mid] + distance[mid][j];
                }
            }
        }
    }
}