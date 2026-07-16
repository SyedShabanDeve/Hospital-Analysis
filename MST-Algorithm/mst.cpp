#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) {
        parent.resize(n);
        rank_.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;

        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
        return true;
    }
};

vector<Edge> kruskalMST(int n, vector<Edge>& edges, int& totalWeight) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu(n);
    vector<Edge> mst;
    totalWeight = 0;

    for (const Edge& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
            if ((int)mst.size() == n - 1) break;
        }
    }

    return mst;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter each edge as: u v weight (0-indexed vertices)\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int totalWeight;
    vector<Edge> mst = kruskalMST(n, edges, totalWeight);

    if ((int)mst.size() != n - 1) {
        cout << "Graph is disconnected. MST does not exist.\n";
        return 0;
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (const Edge& e : mst) {
        cout << e.u << " -- " << e.v << " == " << e.weight << "\n";
    }
    cout << "Total weight of MST: " << totalWeight << "\n";

    return 0;
}

