# 03.04 - Kruskal's Algorithm
Constructs a MST of a connected graph by repeatedly adding the next shortest edge not already contained in the subgraph until we have a MST.

This algorithm makes use of a Disjoint Sets data structure.

If afterwards any vertices remain in different sets the graph is not connected.

## Time Complexity
Time Complexity: `O(|E| log |E|)`

## Algorithm
```c++
void kruskal(int n, vector<tuple<int, int, int>> edges)
{
    // sort edges in increasing order of weight
    sort(edges.begin(), edges.end());

    // current set of edges in MST subgraph
    set<tuple<int, int, int>> s;

    // disjoint sets data structure initialized over all nodes
    disjoint_sets ds(n);

    for(tuple<int, int, int> e: edges)
    {
        // check if vertices are in different sets
        if (ds.find_set(get<1>(e)) != ds.find_set(get<2>(e)))
        {
            // add edge to MST subgraph and merge sets
            s.insert(e);
            ds.union_sets(get<1>(e), get<2>(e));
        }
    }
}
```