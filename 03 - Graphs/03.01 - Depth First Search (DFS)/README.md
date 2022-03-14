# 03.01 - Depth First Search (DFS)
Graph traversal algorithm starting at a node and exploring one branch as far as possible before backtracking.

## Time Complexity
Each vertex is visited at most once and for each vertex each successor is considered at most once. => Time Complexity: `O(|V| + |E|)`

## Algorithm
```c++
void dfs(int n, int s, vector<vector<int>> adj_list)
{
    // order of exploration per node
    // -1 is not explored
    vector<int> ord(n, -1);

    stack<int> st;
    st.push(s);

    int i = 1;

    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        if (ord[v] != -1)
            // vertex already explored
            continue;
        
        ord[v] = i++;

        for(int u: adj_list[v]) 
            // add neighbour vertex to stack
            // if not already explored
            if (ord[u] == -1)
                st.push(u);
    }
}
```
