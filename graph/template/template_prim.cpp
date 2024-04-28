/**
 * @file template_prim.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief matrix net prim algorithm : minimum spanning tree
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

/**
 * @brief 
 *  print the edge from source to destination in MatrixGraph G
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
void prim(const MatrixGraph& G, const int& v, int& sum) {
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
    adjacency_vertex[v] = -1;
    sum += low_cost[v];
    
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
        set[current_vertex] = true;
        sum += low_cost[current_vertex];
        for (int j = 0; j < G.num_vertex; ++i) {
            if (G.edge[current_vertex][j] < low_cost[j]) {
                adjacency_vertex[j] = current_vertex;
                low_cost[j] = G.edge[current_vertex][j];
            }
        }
    }
}