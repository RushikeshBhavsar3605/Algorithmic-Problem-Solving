# Graph Shortest Path Algorithm

## Dijkstra's Algorithm

**Properties:**

- Works with both directed and undirected graphs
- Handles both cyclic and acyclic graphs
- Fails with negative weighted edges
- Gets stuck in infinite loops (TLE) when negative cycles are present
- Single-source shortest path algorithm
- Time complexity: O((V+E) log V) using priority queue

**Algorithm:**

```text
1. Initialize distances: dist[source] = 0, all others = infinite
2. Create priority queue with source vertex
3. While priority queue is not empty:
    a. Extract vertex u with minimum distance
    b. For each neighbor v of u:
        - If dist[u] + weight(u, n) < dist[v]:
            - Update dist[v] = dist[u] + weight(u, v)
            - Add v to priority queue
4. Return distance array
```

## Bellman-Ford Algorithm

**Properties:**

- Can detect negative cycles in the graph
- Works with directed graphs
- Can work with undirected graphs but requires adding edges in both directions
- Handles negative edge weights
- Single-source shortest path algorithm
- Time complexity: O(V × E)

**Algorithm:**

```text
1. Initialize distances: dist[source] = 0, all others = ∞
2. Relax all edges V-1 times:
    For each edge (u,v) with weight w:
        If dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
3. Check for negative cycles:
    For each edge (u,v) with weight w:
        If dist[u] + w < dist[v]:
            Return "Negative cycle detected"
4. Return distance array
```

## Floyd-Warshall Algorithm

**Properties:**

- Multi-source shortest path algorithm (all pairs)
- Can detect negative cycles
- Works with both positive and negative edge weights
- Dijkstra's algorithm can be used as alternative but fails with negative cycles
- Floyd-Warshall is preferred when you need shortest paths between all pairs of vertices
- Time complexity: O(V³)

**Algorithm:**

```text
1. Initialize distance matrix:
   dist[i][j] = weight of edge from i to j (if exists)
   dist[i][i] = 0
   dist[i][j] = ∞ (if no direct edge)
2. For k from 0 to V-1:
    For i from 0 to V-1:
        For j from 0 to V-1:
            If dist[i][k] + dist[k][j] < dist[i][j]:
                dist[i][j] = dist[i][k] + dist[k][j]
3. Check diagonal for negative values to detect negative cycles
4. Return distance matrix
```

## Algorithm Comparison

| Algorithm      | Use Case                               | Negative Weights | Negative Cycles | Time Complexity |
| -------------- | -------------------------------------- | ---------------- | --------------- | --------------- |
| Dijkstra       | Single-source, no negative weights     | ❌               | ❌              | O((V+E) log V)  |
| Bellman-Ford   | Single-source, detects negative cycles | ✅               | ✅ (detects)    | O(V×E)          |
| Floyd-Warshall | All-pairs, detects negative cycles     | ✅               | ✅ (detects)    | O(V³)           |
