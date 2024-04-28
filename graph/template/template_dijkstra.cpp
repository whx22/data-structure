/**
 * @file template_dijkstra.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief matrix net Dijkstra : shortest path (Greedy Algorithm)
 * @version 0.1
 * @date 2023-05-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
using namespace std;

#define MAXSIZE     100
#define INFINITY    65535

using VertexType    = char;
using EdgeType      = int;

typedef struct {
    VertexType  vertex[MAXSIZE];
    EdgeType    edge[MAXSIZE][MAXSIZE];
    int         num_vertex;
    int         num_edge;
} MatrixGraph;

void Dijkstra(const MatrixGraph& G, const int& source, int*& distance, int*& path) {
    bool set[G.num_vertex];
    for (int i = 0; i < G.num_vertex; ++i) {
        set[i] = false;
        distance[i] = G.edge[source][i];
        if (distance[i] != INFINITY) {
            path[i] = source;
        } else {
            path[i] = -1;
        }
    }
    set[source] = true;
    distance[source] = 0;
    path[source] = -1;

    int current_vertex = source;
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

void printShortPath(const MatrixGraph& G, const int& source, int* distance, int* path) {
    int traverse_node;
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