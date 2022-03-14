# 05.01 - Ford-Fulkerson Method
Finds the maximum flow by repeatedly augmenting an initial flow along augmenting paths until no more augmenting paths exist.

The Ford-Fulkerson Method starts with an initial valid flow being `0` for every edge and successively augments this flow (maintaining it as a valid flow) by finding an augmented path until no more augmented path could be found.

## Dinic's Algorithm
Dinic's Algorithm uses the **blocking flow** of the shortest path**s** (**Note: Plural!**) by number of edges to augment the flow.

For this it additionally defines the **Level Graph** for a given residual network which is basically the residual graph with the subset of its edges that are actually part of some shortest path from the source to any node. 

This level graph can contain more edges than the simple BFS-Graph
as it will also contain multiple shortest paths of the same length to the same node (unlike BFS which would only explores one of those).

When finding an augmented path we now not only find **one of the** shortest paths and augment by its bottleneck value but instead augment by the **blocking flow** of the level graph.

The blocking flow of the level graph is a flow such that every path from `s` to `t` contains a saturated edge.

Such a blocking flow can be efficiently found using the Ford-Fulkerson Algorithm applied to the level graph. (This will be much simpler since we won't need any additional residual edges but can instead directly operate on the level graph.)

After augmenting the flow once by the blocking flow the next shortest path from `s` to `t` will have a higher length.

## Time Complexity
There exists different algorithms for the Ford-Fulkerson Method which all only differ in the way the augmented path gets chosen:
- **Ford-Fulkerson Algorithm:** Any path (**DFS**) - Time Complexity: `O(|E|U)` where `U` is the value of the maximum flow. (Also possibly non-terminating for irrational capacities.)
- **Edmonds-Karp:** Shortest path by number of edges (**BFS**) - Time Complexity: `O(|V||E|^2)`
- **Dinic's Algorithm:** Using Blocking Flows - Time Complexity: `O(|V|^2|E|)`

## Algorithm
For a simpler implementation we modify the definition of the antiparallel residual edges in our residual networks allowing those to have a capacity of `0` and negative flow values.

This will work nicely when searching an augmented path (flow < capacity), computing bottleneck value (capacity - flow) and augmenting flow.

```c++
// Number of nodes in residual network.
// 0th node is sink.
// n-1-th node is target.
int n;

// Adjacency Matrix for the residual network.
//
// For large networks consider using a list
// of hash maps to store edges for faster access
// and less storage space.
//
// Each edge (u,v) is represented by a tuple of 
// (current flow, capacity)
vector<vector<pair<int, int>>> adj_matrix(n, 
                vector<pair<int, int>>(n, {0, 0}));

// Adds an edge with capacity c from node u to node v.
//
// Note that this assumes that we do not already have 
// an edge from u to v nor from v to u.
void add_edge(int u, int v, int c)
{
    // add normal edge to residual network
    adj_matrix[u][v] = {0, c};
    // add antiparallel edge to residual network
    adj_matrix[v][u] = {0, 0};
}

// Find an augmenting path.
//
// In this example we simply do Ford-Fulkerson
// with DFS.
vector<pair<int, int>> find_augmenting_path()
{
    // Stores for any node its predecessor and
    // the bottleneck value along the path.
    vector<pair<int, int>> path(n, {-1, -1});

    stack<int> s;

    // Start at source
    s.push(0);

    // As long as we haven't visited the target
    while (!s.empty() && path[n-1].first == -1)
    {
        int u = s.top();
        s.pop();

        if (path[u].first != -1)
            // Already visited node
            continue;

        // Go over all possible edges
        for(int v = 0; v < n; v++)
        {
            // edge
            pair<int, int> e = adj_matrix[u][v];

            // Check if current flow of this edge < capacity
            // (Otherwise this edge wouldn't appear in our
            // residual graph anyways.)
            if (e.first >= e.second) 
                continue;

            // Check if node was already explored
            if (path[v].first != -1)
                continue;

            // Set path predecessor for node
            path[v].first = u;
            
            // Previous path bottleneck value
            int pb = path[u].second;

            // Current edge bottleneck value
            int cb = e.second - e.first;

            // Set path bottleneck value for node
            // (minimum of both or current if no
            // previous value)
            path[v].second = pb == -1 || cb < pb ? cb : pb;

            // Push node
            s.push(v);
        }
    }
}

// Finds the maximum flow in the defined residual network.
int max_flow()
{
    // Current flow value.
    int flow_value = 0;

    // Find augmenting paths as long as we can
    while (true)
    {
        // Find augmenting path
        vector<pair<int, int>> path = find_augmenting_path();

        if (path[n-1].first == -1)
            // No augmenting path was found.
            // (no predecessor for target node)
            break;

        // Augmented path's bottleneck value
        int bv = path[n-1].second

        // Increase flow value by path's bottleneck value
        flow_value += bv;

        // Retrace augmented path and updated residual edges
        int c = n-1;
        while (true)
        {
            if (c == 0)
                // Retraced back to source
                break;

            // Add bottleneck flow to residual edge 
            // from predecessor to current
            adj_matrix[path[c].first][c].first += bv;
            // Subtract bottleneck flow from antiparallel
            // residual edge from current to predecessor
            adj_matrix[c][path[c].first] -= bv;

            c = path[c].first;
        }
    }

    // At this point the flow value is maximal
    return flow_value;
}
```