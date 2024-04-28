// shortest path
#include <iostream>

// Dijkstra : find shortest path algorithm 
#define MAX_EDGE 20
#define MAX_VERTEX 20
#define INFINITY 65535

typedef struct {
    int vertex[MAX_VERTEX];
    int arc[MAX_EDGE][MAX_EDGE];
    int numVertex, numEdge;
} MGraph;

typedef int PathArc[MAX_VERTEX];        // record the show shortest path vertex index
typedef int ShortPathTable[MAX_VERTEX]; // record the shortest path weight
