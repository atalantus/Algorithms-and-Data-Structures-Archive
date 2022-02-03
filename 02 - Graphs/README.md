# 02 - Graphs

## Contents
- ### [02.01 - Depth First Search (DFS)](02.01%20-%20Depth%20First%20Search%20(DFS))
    Graph traversal algorithm starting at a node and exploring one branch as far as possible before backtracking.
- ### [02.02 - Breadth First Search (BFS)](02.02%20-%20Breadth%20First%20Search%20(BFS))
    Graph traversal algorithm starting at a node and explores all nodes at the present depth before moving on to the nodes at the next depth level.
- ### [02.03 - Topological Sort (TS)](02.03%20-%20Topological%20Sort%20(TS))
    Graph traversal algorithm on a directed graph resulting in a topological order where any predecessor of a node is ordered before any of it's postdecessors.
- ### [02.04 - Kruskal's Algorithm](02.04%20-%20Kruskal's%20Algorithm)
    Constructs a MST of a connected graph by repeatedly adding the next shortest edge not already contained in the subgraph until we have a MST.
- ### [02.05 - Prim's Algorithm](02.05%20-%20Prim's%20Algorithm)
    Constructs a MST of a connected graph by repeatedly adding the shortest edge to the subgraph which connects a node already in the subgraph to a node outside of it until we have a MST.
- ### [02.06 - Dijkstra's Algorithm](02.06%20-%20Dijkstra's%20Algorithm)
- ### [02.07 - Bellman-Ford Algorithm](02.07%20-%20Bellman-Ford%20Algorithm)
- ### [02.08 - Floyd-Warshall Algorithm](02.08%20-%20Floyd-Warshall%20Algorithm)

## Graph Representations
- **Adjacency Matrix**: For each pair of vertices `u,v`, store existance of an edge `(u,v)∈E`
- **Adjacency List**: For each vertex `v`, store a list of successors `vE`.

## Graph Traversal
A Graph Traversal algorithm visits vertices in a certain order possibly keeping track of additional information. 
DFS, BFS and TS all run in `O(|V| + |E|)` time and can also be used to efficiently check if a graph is connected (DFS, BFS, TS) or if a graph is cyclic (TS).

## Minimum Spanning Tree (MST)
A MST is a subset of a connected graph such that this subset forms a tree (connected and acyclic) and the total sum of edge weights contained in this subset is minimal.

If a graph has negative edge weights we can find a MST by first adding a constant to every edge weight such that they become non-negative.

A **Maxmimum** Spanning Tree can be obtained by firstly inverting all edge weights of the graph and then finding the MST.

Since a MST is a tree it will always contain exactly `|V| - 1` edges.

## Longest Path Problem