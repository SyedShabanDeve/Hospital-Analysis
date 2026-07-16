# Minimum Spanning Tree (Kruskal's Algorithm)

| Field | Details |
|---|---|
| **Student Name** | Syed Shaban |
| **SAP ID** | 80414 |
| **Subject** | Design and Analysis of Algorithms |
| **Instructor** | Sir Karar Haider |

Finds the Minimum Spanning Tree of a weighted, undirected graph using Kruskal's algorithm with a Disjoint Set Union (union-find with path compression and union by rank).

## How to Compile & Run

```bash
g++ -std=c++11 mst.cpp -o mst && ./mst
```

### Sample Input

```
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```

### Expected Output

```
Edges in the Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Total weight of MST: 19
```
