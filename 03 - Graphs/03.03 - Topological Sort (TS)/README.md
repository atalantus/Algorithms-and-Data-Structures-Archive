# 03.03 - Topological Sort (TS)
Graph traversal algorithm on a directed graph resulting in a topological order where any predecessor of a node is ordered before any of it's postdecessors.

This means that for every edge `e` going from vertex `u` to vertex `v`. `u` comes before `v` in the ordering.

A topological order on a graph exists **iff** the graph is acyclic.

This algorithm can be used to find if a graph is cyclic.

## Time Complexity
Each vertex is visited at most once and for each vertex each successor is considered at most once. => Time Complexity: `O(|V| + |E|)`

## Algorithm
1. For every node, store the number of predecessors.
2. Choose a node with 0 predecessors and remove it from the graph.
3. Repeat until no nodes with 0 predecessors are left.
4. => The order in which the nodes are removed is topological

```c++
void topological_sort(int n, vector<int> pred, vector<vector<int>> adj_list)
{
    // Order of nodes
    //
    // If at the end any of the nodes in this (connected) graph
    // still have an order of -1 this means that the graph is cyclic.
    vector<int> ord(n, -1);
    queue<int> q;

    int o = 1;

    // find a starting node that has no predecessors
    for(int i = 0; i < n; i++)
    {
        if (pred[i] > 0) continue;

        // start topological order at node i
        q.push(i);

        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();

            ord[v] = o++;

            for (int u: adj_list[v])
            {
                // decrease predecessor count
                pred[u]--;
                
                if (pred[u] == 0)
                    q.push(u);
            }
        }

        break;
    }
}
```