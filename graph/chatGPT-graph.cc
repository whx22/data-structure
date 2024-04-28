/**
 * @file chatGPT_graph.cpp
 * @author huxin wang (2019120573@jou.edu.cn)
 * @brief 
 * @version 0.1
 * @date 2023-08-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9;

// 边的结构体
struct Edge {
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

// 图的类
class Graph {
public:
    // 构造函数
    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }

    // 添加边
    void addEdge(int from, int to, int weight) {
        adj[from].push_back(Edge(from, to, weight));
        adj[to].push_back(Edge(to, from, weight));
    }

    // 深度优先搜索
    void dfs(int start) {
        vector<bool> visited(n, false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int cur = s.top();
            s.pop();

            if (visited[cur]) {
                continue;
            }

            visited[cur] = true;
            cout << cur << " ";

            for (auto e : adj[cur]) {
                if (!visited[e.to]) {
                    s.push(e.to);
                }
            }
        }

        cout << endl;
    }

    // 广度优先搜索
    void bfs(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (visited[cur]) {
                continue;
            }

            visited[cur] = true;
            cout << cur << " ";

            for (auto e : adj[cur]) {
                if (!visited[e.to]) {
                    q.push(e.to);
                }
            }
        }

        cout << endl;
    }

    // Prim算法
    int prim() {
        vector<bool> visited(n, false);
        vector<int> dist(n, INF);
        dist[0] = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            ans += dist[u];

            for (auto e : adj[u]) {
                if (!visited[e.to] && e.weight < dist[e.to]) {
                    dist[e.to] = e.weight;
                }
            }
        }

        return ans;
    }

    // Kruskal算法
    int kruskal() {
        int ans = 0;
        vector<Edge> edges;

        for (int i = 0; i < n; i++) {
            for (auto e : adj[i]) {
                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto e : edges) {
            int pu = find(parent, e.from);
            int pv = find(parent, e.to);

            if (pu != pv) {
                ans += e.weight;
                parent[pu] = pv;
            }
        }

        return ans;
    }

    // Dijkstra算法
    vector<int> dijkstra(int start) {
        vector<int> dist(n, INF);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int u = p.second;
            if (dist[u] < p.first) {
                continue;
            }

            for (auto e : adj[u]) {
                if (dist[u] + e.weight < dist[e.to]) {
                    dist[e.to] = dist[u] + e.weight;
                    pq.push(make_pair(dist[e.to], e.to));
                }
            }
        }

        return dist;
    }

    // Floyd算法
    vector<vector<int>> floyd() {
        vector<vector<int>> dist(n, vector<int>(n,INF));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (auto e : adj[i]) {
                dist[e.from][e.to] = e.weight;
                dist[e.to][e.from] = e.weight;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        return dist;
    }

private:
    int n;
    vector<vector<Edge>> adj;

    int find(vector<int>& parent, int u) {
        while (parent[u] != u) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }

        return u;
    }
};

int main() {
    // 创建一个包含5个节点的图
    Graph g(5);

    // 添加边
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 8);

    // 深度优先搜索
    cout << "DFS: ";
    g.dfs(0);

    // 广度优先搜索
    cout << "BFS: ";
    g.bfs(0);

    // Prim算法
    cout << "Prim: " << g.prim() << endl;

    // Kruskal算法
    cout << "Kruskal: " << g.kruskal() << endl;

    // Dijkstra算法
    vector<int> dist = g.dijkstra(0);
    cout << "Dijkstra: ";
    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    // Floyd算法
    vector<vector<int>> floydDist = g.floyd();
    cout << "Floyd: " << endl;
    for (int i = 0; i < floydDist.size(); i++) {
        for (int j = 0; j < floydDist[i].size(); j++) {
            cout << floydDist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}