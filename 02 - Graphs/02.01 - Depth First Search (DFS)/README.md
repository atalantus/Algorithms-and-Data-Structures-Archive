# 02.01 - Depth First Search (DFS)
Depth First Search (DFS) is a graph traversal algorithm starting at a node and exploring one branch as far as possible before backtracking.

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
        int v = s.top();
        s.pop();

        if (ord[v] != -1)
            // vertex already explored
            continue;
        
        ord[v] = i++;

        for(int u: adj_list[v]) 
            // add neighbour vertex to stack
            st.push(u);
    }
}
```