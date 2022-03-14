# 03.07 - Bellman-Ford Algorithm
Finds the Single Source Shortest Path (SSSP) from one node to all other nodes on any graph.

## Time Complexity
Time Complexity: `O(|V||E|)`

## Algorithm
Start with the shortest path of length 1 and then successively construct all shortest paths of length
2, 3, ..., |V| - 1. If after |V| - 1 steps we can still find a shorter path to any node this node must be
included in a negative cycle.

```c++
void bellman_ford(int n, int s, vector<tuple<int, int, int>> edges)
{
    // Distance from every node to the source node.
    vector<int> d(n, INT_MAX);

    // Predecessor of any node.
    // Used for retracing the path from a node to the source node.
    vector<int> pred(n, -1);

    // start at source node
    d[s] = 0;
    pred[s] = s;

    // compute paths of all different lengths
    for (int i = 0; i < n - 1; i++)
    {
        for (vector<tuple<int, int, int>> e: edges)
        {
            if (d[get<1>(e)] + get<0>(e) < d[get<2>(e)]>)
            {
                // smaller distance through edge e
                // update
                d[get<2>(e)] = d[get<1>(e)] + get<0>(e);
                pred[get<2>(e)] = get<1>(e);
            }
        }
    }

    // if we now still find a shorter path of length n
    // we must have a negative cycle
    for (vector<tuple<int, int, int>> e: edges)
    {
        if (d[get<1>(e)] + get<0>(e) < d[get<2>(e)]>)
        {
            // smaller distance through edge e
            // negative cycle
            return;
        }
    }
}
```