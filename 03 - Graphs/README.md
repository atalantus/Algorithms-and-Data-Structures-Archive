# 03 - Graphs

## Contents
- ### [03.01 - Depth First Search (DFS)](03.01%20-%20Depth%20First%20Search%20(DFS))
    Graph traversal algorithm starting at a node and exploring one branch as far as possible before backtracking. `O(|V| + |E|)`
- ### [03.02 - Breadth First Search (BFS)](03.02%20-%20Breadth%20First%20Search%20(BFS))
    Graph traversal algorithm starting at a node and explores all nodes at the present depth before moving on to the nodes at the next depth level. `O(|V| + |E|)`
- ### [03.03 - Topological Sort (TS)](03.03%20-%20Topological%20Sort%20(TS))
    Graph traversal algorithm on a directed graph resulting in a topological order where any predecessor of a node is ordered before any of it's postdecessors. `O(|V| + |E|)`
- ### [03.04 - Kruskal's Algorithm](03.04%20-%20Kruskal's%20Algorithm)
    Constructs a MST of a connected graph by repeatedly adding the next shortest edge not already contained in the subgraph until we have a MST. `O(|E| log |E|)`
- ### [03.05 - Prim's Algorithm](03.05%20-%20Prim's%20Algorithm)
    Constructs a MST of a connected graph by repeatedly adding the shortest edge to the subgraph which connects a node already in the subgraph to a node outside of it until we have a MST. `O(|E| + |V| log |V|)`
- ### [03.06 - Dijkstra's Algorithm](03.06%20-%20Dijkstra's%20Algorithm)
    Finds the Single Source Shortest Path (SSSP) from one node to all other nodes on any graph with non-negative edge weights. `O(|E| + |V| log |V|)`
- ### [03.07 - Bellman-Ford Algorithm](03.07%20-%20Bellman-Ford%20Algorithm)
    Finds the Single Source Shortest Path (SSSP) from one node to all other nodes on any graph. `O(|V||E|)`
- ### [03.08 - Floyd-Warshall Algorithm](03.08%20-%20Floyd-Warshall%20Algorithm)
    Finds the All Pairs Shortest Path (APSP) for any pair of nodes on any graph. `O(|V|^3)`

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

## Shortest Path Problem
There are multiple different Shortest Path Problems: **Single Pair Shortest Path** (SPSP), **Single Source Shortest Path** (SSSP), **All Pairs Shortest Path** (APSP).

There are different algorithmic approaches depending on properties of the graph and the path problem.

For Example the SSSP on directed, acyclic graph can simply be found via Topological Sort and traversing nodes in topological order updating the distances to the source node. This takes `O(|V| + |E|)` time.

Even simpler is the SSSP on an unweighted graph which can simply be found via BST in also `O(|V| + |E|)` time.

Theoretically speaking all optimal SPSP algorithms also solve SSSP for the given source node within the same asymptotic time bound.

## Longest Path Problem
Finding the longest simple path between two nodes in a graph is NP-hard for general graphs.

However there are two different approaches working in polynomial time for directed acyclic graphs.

Approach 1 `O(|V||E|)`:
1. Negate all edge weights
2. Shortest path is now the longest path in the original graph (use Bellman-Ford)

Approach 2 ``O(|V| + |E|)`:
1. Compute topological order of nodes
2. Process nodes in topological order
3. For each node check wether the distance to any of its successors can be increased by passing over this node