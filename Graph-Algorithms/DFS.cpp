// DFS (Depth-First Search)
// Student: Syed Shaban | SAP ID: 80414
// Subject: Design and Analysis of Algorithms | Instructor: Sir Karar Haider

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;

    void dfsUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    void dfs(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal starting from node " << start << ": ";
        dfsUtil(start, visited);
        cout << endl;
    }
};

int main() {
    // Sample graph with 6 nodes (0-5)
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.dfs(0);

    return 0;
}
