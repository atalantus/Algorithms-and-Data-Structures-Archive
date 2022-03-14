# Algorithms and Data Structures Archive

## Contents
- ### [01 - Data Structures](01%20-%20Data%20Structures)
    - #### [01.01 - Disjoint Sets](01%20-%20Data%20Structures/01.01%20-%20Disjoint%20Sets)
        Data Structure for operation and maintainance on disjoint sets over elements also often called Disjoint Set Union (DSU) or Union Find. `O(α(n))`
- ### [02 - Sorting](02%20-%20Sorting)
    - #### [02.01 - Merge Sort](02%20-%20Sorting/02.01%20-%20Merge%20Sort)
        Efficient comparison-based sorting algorithm based on divide and conquer. `O(n log n)`
- ### [03 - Graphs](03%20-%20Graphs)
    - #### [03.01 - Depth First Search (DFS)](03%20-%20Graphs/03.01%20-%20Depth%20First%20Search%20(DFS))
        Depth First Search (DFS) is a graph traversal algorithm starting at a node and exploring one branch as far as possible before backtracking. `O(|V| + |E|)`
    - #### [03.02 - Breadth First Search (BFS)](03%20-%20Graphs/03.02%20-%20Breadth%20First%20Search%20(BFS))
        Breadth First Search (BFS) is a graph traversal algorithm starting at a node and explores all nodes at the present depth before moving on to the nodes at the next depth level. `O(|V| + |E|)`
    - #### [03.03 - Topological Sort (TS)](03%20-%20Graphs/03.03%20-%20Topological%20Sort%20(TS))
        Graph traversal algorithm on a directed graph resulting in a topological order where any predecessor of a node is ordered before any of it's postdecessors. `O(|V| + |E|)`
    - #### [03.04 - Kruskal's Algorithm](03%20-%20Graphs/03.04%20-%20Kruskal's%20Algorithm)
        Constructs a MST of a connected graph by repeatedly adding the next shortest edge not already contained in the subgraph until we have a MST. `O(|E| log |E|)`
    - #### [03.05 - Prim's Algorithm](03%20-%20Graphs/03.05%20-%20Prim's%20Algorithm)
        Constructs a MST of a connected graph by repeatedly adding the shortest edge to the subgraph which connects a node already in the subgraph to a node outside of it until we have a MST. `O(|E| + |V| log |V|)`
    - #### [03.06 - Dijkstra's Algorithm](03%20-%20Graphs/03.06%20-%20Dijkstra's%20Algorithm)
        Finds the Single Source Shortest Path (SSSP) from one node to all other nodes on any graph with non-negative edge weights. `O(|E| + |V| log |V|)`
    - #### [03.07 - Bellman-Ford Algorithm](03%20-%20Graphs/03.07%20-%20Bellman-Ford%20Algorithm)
        Finds the Single Source Shortest Path (SSSP) from one node to all other nodes on any graph. `O(|V||E|)`
    - #### [03.08 - Floyd-Warshall Algorithm](03%20-%20Graphs/03.08%20-%20Floyd-Warshall%20Algorithm)
        Finds the All Pairs Shortest Path (APSP) for any pair of nodes on any graph. `O(|V|^3)`
- ### [04 - Trees](04%20-%20Trees)
    - ### [04.01 - Trie](04%20-%20Trees/04.01%20-%20Trie)
        Data Structure used to efficiently store and maintain a set of strings.
    - ### [04.02 - Segment Tree](04%20-%20Trees/04.02%20-%20Segment%20Tree)
        Data Structure used to efficiently store and maintain information about intervals, or segments.
    - ### [04.03 - Lowest Common Ancestor](04%20-%20Trees/04.03%20-%20Lowest%20Common%20Ancestor)
- ### [05 - Maximum Flow](05%20-%20Maximum%20Flow)
    - #### [05.01 - Ford-Fulkerson Method](05%20-%20Maximum%20Flow/05.01%20-%20Ford-Fulkerson%20Method)
        Finds the maximum flow by repeatedly augmenting an initial flow along augmenting paths until no more augmenting paths exist.
    - #### [05.02 - Push-Relabel Method](05%20-%20Maximum%20Flow/05.02%20-%20Push-Relabel%20Method)
        Finds the maximum flow by successively adapting a preflow that saturates a cut until this preflow is a valid flow.
- ### [06 - Brute Force](06%20-%20Brute%20Force)
    Technique of systematically iterating over all solution candidates until one satisfies the solution requirements.
- ### [07 - Greedy](07%20-%20Greedy)
    Technique of approximating the optimal solution to a problem by iteratively choosing locally optimal solutions for its subproblems.
- ### [08 - Dynamic Programming](08%20-%20Dynamic%20Programming)
    Technique of solving a problem by recursively dividing it into subproblems. After solving a subproblem it's solution is cached for later reuse in case the same subproblem comes up again.
- ### [09 - Number Theory](09%20-%20Number%20Theory)
- ### [10 - Euclidean Geometry](10%20-%20Euclidean%20Geometry)
- ### [11 - Projective Geometry](11%20-%20Projective%20Geometry)
    Greatly simplifies the basic operations in comparison to euclidean geometry and allows for projective transformations.
- ### [12 - Miscellaneous](12%20-%20Miscellaneous)
    - #### [12.01 - Binary Search](12%20-%20Miscellaneous/12.01%20-%20Binary%20Search)
        Algorithm used for finding a specific value/element in an ordered interval range. `O(log n)`

## Additional References
- [cp-algorithms.com](https://cp-algorithms.com)
- [CLRS](https://edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf)
