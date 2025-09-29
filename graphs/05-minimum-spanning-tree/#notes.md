# Graph Minimum Spanning Tree Algorithm

## Properties of MST:

- A tree in which we have N nodes and N-1 edges
- All nodes in a tree are reachable to each other
- MST doesn't contain cycle because of 1st rule

## Algorithms to find MST:

- Prim's Algorithm
- Kruskal's Algorithm (Disjoint Set)

## Prim's Algorithm:

- The main role of prims is to connect all nodes with minimum cost
- Because of this principle we only need to keep the minimum cost edges because we simply don't care about shortest path
- So the underline algorithm is simple that is to only keep minimum edges at each adjacent node and doesn't care about anything else
- Greedy is the intuition

## Disjoint Set

- It's used to determine if 2 nodes belongs to the same component or not in constant time
- We can find current belongings in each step (edge) separately in constant time
