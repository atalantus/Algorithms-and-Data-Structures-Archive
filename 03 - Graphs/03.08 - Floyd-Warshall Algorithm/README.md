# 03.08 - Floyd-Warshall Algorithm
Finds the All Pairs Shortest Path (APSP) for any pair of nodes on any graph.

Negative cycles exists in the graph iff in the end we have negative entries on the diagonal of the distance matrix.

Additionally if the graph is not connected the algorithm as implemented below may still indicate a path of length
close to `INT_MAX` for edges that are in different components. To also work on disconnected graphs we would have to
use a special value than can not be the actual length of any path to represent in our distance matrix and then
only update the distance through the intermediate node if the paths to this intermediate node are actually existant.

## Time Complexity
Time Complexity: `O(|V|^3)`

If the graph is sparse just using Dijkstra's Algorithm for every node once with a running time of `O(|V||E| + |V|^2 log |V|)`
might actually be faster.

## Algorithm
Instead of a distance array representing the minimum distance from any node to a source node we store a distance matrix holding
the current minimum distance from any node to any other node.

We than update these distance entries by considering each node `k` once as an intermediate node in the path from every node `i` to
every other node `j`. If the path through this intermediate node is then shorter we update the distance entry.

```c++
void floyd_warshall(int n, vector<tuple<int, int, int>> edges)
{
    // Distance matrix from every node to the every node.
    vector<vector<int>> d(n, vector<int>(n, INT_MAX));

    // Predecessor of any node.
    // Used for retracing the path from a node to the source node.
    vector<int> pred(n, -1);

    // Update distances from edges to themselves
    for (int i = 0; i < n; i++)
    {
        d[i][i] = 0;
    }

    // Update distances for where we have an edge
    for (tuple<int, int, int> e: edges)
    {
        d[get<1>(e)][get<2>(e)] = get<0>(e);
    }

    // Consider every node once as intermediate node k
    for (int k = 0; k < n; k++)
        // Consider every node as source node i
        for (int i = 0; i < n; i++)
            // Consider every node as target node j
            for (int j = 0; j < n; j++)
            {
                // Check if the path from i to k to j is a shorter path than
                // what we currently have as from i to j.
                //
                // Note that in a disconnected graph we may not even have a path
                // from i to k or from k to j which we would have to check beforehand.
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
}
```