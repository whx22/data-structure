/**
 * @file 1_3_shortest_path.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief shortest path algorithm in graph
 * @version 0.1
 * @date 2023-03-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

namespace Dijkstra {
/**
 * @brief Dijkstra algorithm
 *  assist array and variable algorithm : 
 *  distance array: record the shortest distance from v0 to other vertex
 *  path array: record the path from v0 to other vertex
 *  set array: record the vertex whether has been visited
 *  
 *  main process :
 *  1. initialize distance array & path array & set array
 *  2. select the vertex which has the minimum distance and the vertex has not been visited
 *  3. update the distance array & path array by the selected vertex
 *  4. repeat step 2 & 3 until all the vertexes have been visited
 *  5. return the distance array & path array
 */
#define MAX_VERTEX 20
#define INFINITY 65535
/**
 * @brief 
 * 
 * @param n         : vertex number
 * @param MGraph    : matrix graph
 * @param v0        : start vertex
 * @param distance  : distance array
 * @param path      : path array 
 */
void Dijkstra(const int& vertex_num, float** MGraph, int v0, int distance[], int path[]) {
    // initialize set array & distance array & path array   
    int set[vertex_num];
    for (int i = 0; i < vertex_num; ++i) {
        set[i] = 0;
        distance[i] = MGraph[v0][i];
        // if a vertex is connected to v0, then the path is v0
        if (distance[i] < INFINITY) {
            path[i] = v0;
        } else {
            path[i] = -1;
        }
    }
    set[v0] = 1;
    distance[v0] = 0;

    // main process
    int min = INFINITY; // record the minimum distance 
    int v;              // record the vertex which is selected
    for (int i = 0; i < vertex_num - 1; ++i) {
        // select the vertex which has the minimum distance and the vertex has not been visited
        for (int j = 0; j < vertex_num; ++j) {
            if (set[j] == 0 && distance[j] < min) {
                min = distance[j];
                v = j;
            }
        }
        set[v] = 1;
        //  update the distance array & path array by the selected vertex
        for (int j = 0; j < vertex_num; ++j) {
            if (set[j] == 0 && distance[v] + MGraph[v][j] < distance[j]) {
                distance[j] = distance[v] + MGraph[v][j];
                path[j] = v;
            }
        }
    }
} 


}   // namespace Dijkstra

#include <iostream>
using namespace std;
namespace Floyd {
#define MAX_VERTEX 1000
/**
 * @brief 
 * 
 * @param start_vertex  : the start vertex 
 * @param end_vertex    : the end vertex
 * @param path          : path array
 */
void printPath(int start_vertex, int end_vertex, int path[][MAX_VERTEX]) {
    if (path[start_vertex][end_vertex] == -1) {
        cout << start_vertex << " -> " << end_vertex << endl;
    } else {
        printPath(start_vertex, path[start_vertex][end_vertex], path);
        printPath(path[start_vertex][end_vertex], end_vertex, path);
    }
}
/**
 * @brief Floyd algorithm
 *  assist array and variable algorithm :
 *  1. distance array: record the shortest distance from vi to vj
 *  2. path array: record the path from vi to vj
 *  
 *  
 * 
 */

/**
 * @brief 
 * 
 * @param n         : vertex number   
 * @param MGraph    : matrix graph     
 * @param path      : path array : record the path from vi to vj
 */
void Floyd(const int& n, const int**& MGraph, int** path) {
    // 1. initialize distance array & path array
    int distance[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distance[i][j] = MGraph[i][j];
            path[i][j] = -1;
        }
    }
    // 2. use v as the intermediate vertex
    // if the distance from vi to vj is shorter than the distance from vi to vk + vk to vj then update the distance from vi to vj
    int v;
    for (v = 0; v < n; ++v) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][v] + distance[v][j] < distance[i][j]) {
                    distance[i][j] = distance[i][v] + distance[v][j];
                    path[i][j] = v;
                }
            }
        }
    }
}

}   // namespace Floyd