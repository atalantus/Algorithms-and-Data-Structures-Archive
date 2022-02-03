# 02.02 - Breadth First Search (BFS)
Graph traversal algorithm starting at a node and explores all nodes at the present depth before moving on to the nodes at the next depth level.

This means that the order in which nodes are explored from the starting node is increasing the path length of this node to the starting node. 

Thus BFS can be easily used to solve the SSSP problem on unweighted graphs.

One can also find other additional properties of the shortest path by storing their value along inside the `parent` list.

## Time Complexity
Each vertex is visited at most once and for each vertex each successor is considered at most once. => Time Complexity: `O(|V| + |E|)`

## Algorithm
```c++
void bfs(int n, int s, vector<vector<int>> adj_list)
{
    // Store the parent node for each node as it get's explored.
    // Retracing nodes to the source node gives the shortest 
    // length path from the source node to any node.
    //
    // If we would be interested in any additional properties of 
    // this path we could use a tupel as vector type and store those
    // property values along with the parent index.
    //
    // In this example we additionally store the length of the path
    // directly as the second value of the pair.
    vector<pair<int, int>> parent(n, make_pair(-1, -1));

    // source node has itself as parent and a path length of 0
    parent[s] = make_pair(s, 0);

    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int u: adj_list[v])
        {
            if (parent[u].first != -1)
                // node already explored
                continue;
            
            // set parent
            parent[u].first = v;
            // set path length
            parent[u].second = parent[v].second + 1;

            q.push(u);
        }
    }
}
```