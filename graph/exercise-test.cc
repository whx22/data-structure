#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
template <typename T>
class Graph {
public:
    /**
     * @brief Construct a new Graph object
     * 
     * @param directed 
     * @param weighted 
     */
    Graph(bool directed = false, bool weighted = false) 
    : directed_(directed), weighted_(weighted), num_vertices_(0) {}

    /**
     * @brief Graph object add vertex
     * 
     * @param value 
     */
    void addVertex(const T& value) {
        vertices_.push_back(value);
        ++num_vertices_;
        adj_matrix_.resize(num_vertices_);
        for (auto& row : adj_matrix_) {
            row.resize(num_vertices_);
        }
    }

    /**
     * @brief Graph object add edge
     * 
     * @param source 
     * @param destination 
     * @param weight 
     */
    void addEdge(int source, int destination, int weight = 1) {
        if (source < 0 || source >= num_vertices_ || destination < 0 || destination >= num_vertices_) {
            throw std::out_of_range("Invalid vertex index");
        }
        adj_matrix_[source][destination] = weight;
        if (!directed_) {
            adj_matrix_[destination][source] = weight;
        }
    }

    /**
     * @brief Graph Depth First Search all connectivity component
     * 
     */
    void DFS() {
        std::vector<bool> visited(num_vertices_, false);
        for (int i = 0; i < num_vertices_; ++i) {
            if (!visited[i]) {
                DFSHelper(i, visited);  
            }
        }
    }

    /**
     * @brief Graph Breadth First Search all connectivity component
     * 
     */
    void BFS() {
        std::vector<bool> visited(num_vertices_, false);
        for (int i = 0; i < num_vertices_; ++i) {
            if (!visited[i]) {
                BFSHelper(i, visited);
            }
        }
    }

private:
    /**
     * @brief Graph Depth First Search current connectivity component
     * 
     * @param vertex 
     * @param visited 
     */
    void DFSHelper(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        visitVertex(vertex);
        for (int i = 0; i < num_vertices_; ++i) {
            if (!visited[i] && adj_matrix_[vertex][i]) {
                DFSHelper(i, visited);
            }
        }
    }

    /**
     * @brief Graph Breadth First Search current connectivity component
     * 
     * @param start 
     * @param visited 
     */
    void BFSHelper(int start, std::vector<bool>& visited) {
        std::queue<int> assist_queue;
        visited[start] = true;
        assist_queue.push(start);
        while (!assist_queue.empty()) {
            int current_vertex = assist_queue.front();
            assist_queue.pop();
            for (int i = 0; i < num_vertices_; ++i) {
                if (!visited[i] && adj_matrix_[current_vertex][i]) {
                    visited[i] = true;
                    assist_queue.pop(i);
                }
            }
        }
    }

    /**
     * @brief visit current vertex
     * 
     * @param vertex 
     */
    void visitVertex(int vertex) {
        std::cout << vertices_[vertex] << std::endl;
    }

private:
    bool directed_;
    bool weighted_;
    int num_vertices_;
    std::vector<T>  vertices_;
    std::vector<std::vector<int>> adj_matrix_;
};