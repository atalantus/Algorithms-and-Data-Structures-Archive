# 02.06 - Dijkstra's Algorithm
Finds the Single Source Shortest Path (SSSP) between two nodes on any graph with non-negative edge weights.

## Time Complexity
Time Complexity: `O(|E| + |V| log |V|)`

## Algorithm
```c++
void dijkstra(int n, int s, vector<vector<pair<int, int>>> adj_list)
{
    // Distance from every node to the source node.
    // A distance of -1 means there is no path between the two nodes.
    vector<int> d(n, -1);

    // Predecessor of any node.
    // Used for retracing the path from a node to the source node.
    vector<int> pred(n, -1);

    // Priority Queue over nodes and their respective distance to the source node.
    // Sorted in increasing order of distance to source node.
    priority_queue(pair<int, int>, vector<pair<int, int>>, greater<>) pq;

    // start at source node
    d[s] = 0;
    pred[s] = s;
    pq.push(make_pair(0, s));

    while (!pq.empty())
    {
        pair<int, int> v = pq.top();
        pq.pop();

        // check if node was already explored with a smaller distance to source node
        if (d[v.second] != -1 && d[v.second] < v.first) 
            continue;
        
        for(pair<int, int> e: adj_list[v.second])
        {
            // new distance for postdecessor node
            int nd = d[v.second] + e.second;

            // check if new distance is new best for postdecessor node
            if (d[e.first] == -1 || nd < d[e.first])
            {
                d[e.first] = nd;
                pq.push(make_pair(nd, e.first));
            }
        }
    }
}
```