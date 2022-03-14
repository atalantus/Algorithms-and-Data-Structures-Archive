# 02.05 - Prim's Algorithm
Constructs a MST of a connected graph by repeatedly adding the shortest edge to the subgraph which connects a node already in the subgraph to a node outside of it until we have a MST.

If at the end not all vertices were visited the graph is not connected.

## Time Complexity
Time Complexity: `O(|E| + |V| log |V|)`

## Algorithm
```c++
void prim(int n, vector<vector<pair<int, int>>> adj_list)
{
    // Current set of edges in MST subgraph
    set<tuple<int, int, int>> s;

    // Minimal edge weight which connects a node to the MST subgraph.
    vector<int> c(n, INT_MAX);

    // Already visited property for every node.
    vector<bool> visited(n, false);

    // List of predecessor for each node.
    vector<int> pred(n, -1);
    
    // Priority Queue keeping track of a node and it's minimal edge weight which connects 
    // it to the MST subgraph (sorted in increasing order of edge weight).
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // start at any node (here node 0)
    c[0] = 0;
    visited[0] = true;
    pred[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        pair<int, int> v = pq.top();
        pq.pop();

        // check if this node was already visited
        if (visited[v.second]) continue;

        // add edge to MST subgraph
        s.insert(make_tuple(v.first, pred[v.second], v.second));

        // update visited
        visited[v.second] = true;

        for(pair<int, int> e: adj_list[v.second])
        {
            // check if neighbouring node was already visited
            if (visited[e.second]) 
                continue;

            // check if we have a smaller connection edge for neighbouring node
            if (e.first < c[e.second]) 
            {
                // update predecessor
                pred[e.second] = v.second;
                // update smallest connection edge
                c[e.second] = e.first;

                pq.insert(e);
            }
        }
    }
}
```