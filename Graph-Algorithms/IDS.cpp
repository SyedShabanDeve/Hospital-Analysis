// IDS (Iterative Deepening Search)
// Combines DFS's low memory usage with BFS's guarantee of finding the
// shallowest goal, by running depth-limited DFS with an increasing limit.
// Student: Syed Shaban | SAP ID: 80414
// Subject: Design and Analysis of Algorithms | Instructor: Sir Karar Haider

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;

    bool depthLimitedSearch(int node, int target, int limit, vector<int> &path) {
        path.push_back(node);

        if (node == target) return true;
        if (limit <= 0) {
            path.pop_back();
            return false;
        }

        for (int neighbor : adjList[node]) {
            if (depthLimitedSearch(neighbor, target, limit - 1, path)) {
                return true;
            }
        }

        path.pop_back();
        return false;
    }

public:
    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    void iterativeDeepeningSearch(int start, int target, int maxDepth) {
        for (int depth = 0; depth <= maxDepth; depth++) {
            vector<int> path;
            cout << "Trying depth limit " << depth << " ... ";

            if (depthLimitedSearch(start, target, depth, path)) {
                cout << "Found node " << target << "!" << endl;
                cout << "Path: ";
                for (int node : path) cout << node << " ";
                cout << endl;
                return;
            }
            cout << "not found." << endl;
        }
        cout << "Node " << target << " not found within depth " << maxDepth << endl;
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

    int start = 0, target = 5, maxDepth = 4;
    g.iterativeDeepeningSearch(start, target, maxDepth);

    return 0;
}
