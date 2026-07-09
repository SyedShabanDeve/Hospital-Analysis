# Graph Traversal Algorithms — BFS, DFS, IDS

| Field | Details |
|---|---|
| **Student Name** | Syed Shaban |
| **SAP ID** | 80414 |
| **Subject** | Design and Analysis of Algorithms |
| **Instructor** | Sir Karar Haider |

## Files

| File | Algorithm | Description |
|---|---|---|
| `BFS.cpp` | Breadth-First Search | Level-by-level traversal using a queue |
| `DFS.cpp` | Depth-First Search | Recursive traversal, goes as deep as possible before backtracking |
| `IDS.cpp` | Iterative Deepening Search | Runs depth-limited DFS with an increasing depth limit until the target is found — combines DFS's low memory use with BFS's shortest-path guarantee |

All three use the same sample undirected graph (6 nodes, edges: 0-1, 0-2, 1-3, 2-4, 3-5, 4-5) so the outputs can be compared directly.

## How to Compile & Run

```bash
g++ BFS.cpp -o bfs && ./bfs
g++ DFS.cpp -o dfs && ./dfs
g++ IDS.cpp -o ids && ./ids
```

### Expected Output

- **BFS** (from node 0): `0 1 2 3 4 5`
- **DFS** (from node 0): `0 1 3 5 4 2`
- **IDS** (0 → target 5): finds the shortest path `0 1 3 5` at depth limit 3
