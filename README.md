# Algorithms and Data Structures Archive

## Contents
- ### [01 - Data Structures](01%20-%20Data%20Structures)
    - #### [01.01 - Disjoint Sets](01%20-%20Data%20Structures/01.01%20-%20Disjoint%20Sets)
        Data Structure for operation and maintainance on disjoint sets over elements also often called Disjoint Set Union (DSU) or Union Find. `O(α(n))`
- ### [02 - Graphs](02%20-%20Graphs)
    - #### [02.01 - Depth First Search (DFS)](02%20-%20Graphs/02.01%20-%20Depth%20First%20Search%20(DFS))
        Depth First Search (DFS) is a graph traversal algorithm starting at a node and exploring one branch as far as possible before backtracking. `O(|V| + |E|)`
    - #### [02.02 - Breadth First Search (BFS)](02%20-%20Graphs/02.02%20-%20Breadth%20First%20Search%20(BFS))
        Breadth First Search (BFS) is a graph traversal algorithm starting at a node and explores all nodes at the present depth before moving on to the nodes at the next depth level. `O(|V| + |E|)`
    - #### [02.03 - Topological Sort (TS)](02%20-%20Graphs/02.03%20-%20Topological%20Sort%20(TS))
        Graph traversal algorithm on a directed graph resulting in a topological order where any predecessor of a node is ordered before any of it's postdecessors. `O(|V| + |E|)`
    - #### [02.04 - Kruskal's Algorithm](02%20-%20Graphs/02.04%20-%20Kruskal's%20Algorithm)
        Constructs a MST of a connected graph by repeatedly adding the next shortest edge not already contained in the subgraph until we have a MST. `O(|E| log |E|)`
    - #### [02.05 - Prim's Algorithm](02%20-%20Graphs/02.05%20-%20Prim's%20Algorithm)
        Constructs a MST of a connected graph by repeatedly adding the shortest edge to the subgraph which connects a node already in the subgraph to a node outside of it until we have a MST. `O(|E| + |V| log |V|)`
    - #### [02.06 - Dijkstra's Algorithm](02%20-%20Graphs/02.06%20-%20Dijkstra's%20Algorithm)
        Finds the Single Source Shortest Path (SSSP) from one node to all other nodes on any graph with non-negative edge weights. `O(|E| + |V| log |V|)`
    - #### [02.07 - Bellman-Ford Algorithm](02%20-%20Graphs/02.07%20-%20Bellman-Ford%20Algorithm)
        Finds the Single Source Shortest Path (SSSP) from one node to all other nodes on any graph. `O(|V||E|)`
    - #### [02.08 - Floyd-Warshall Algorithm](02%20-%20Graphs/02.08%20-%20Floyd-Warshall%20Algorithm)
        Finds the All Pairs Shortest Path (APSP) for any pair of nodes on any graph. `O(|V|^3)`
- ### [03 - Trees](03%20-%20Trees)
- ### [04 - Maximum Flow](04%20-%20Maximum%20Flow)
- ### [05 - Brute Force](05%20-%20Brute%20Force)
    Technique of systematically iterating over all solution candidates until one satisfies the solution requirements.
- ### [06 - Greedy](06%20-%20Greedy)
    Technique of approximating the optimal solution to a problem by iteratively choosing locally optimal solutions for its subproblems.
- ### [07 - Dynamic Programming](07%20-%20Dynamic%20Programming)
    Technique of solving a problem by recursively dividing it into subproblems. After solving a subproblem it's solution is cached for later reuse in case the same subproblem comes up again.
- ### [08 - Number Theory](08%20-%20Number%20Theory)
- ### [09 - Geometry](09%20-%20Geometry)
- ### [10 - Miscellaneous](10%20-%20Miscellaneous)
    - #### [10.01 - Binary Search](10%20-%20Miscellaneous/10.01%20-%20Binary%20Search)
        Algorithm used for finding a specific value/element in an ordered interval range. `O(log n)`

## Additional References
- [cp-algorithms.com](https://cp-algorithms.com)
- [CLRS](https://edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf)
