#include <bits/stdc++.h>

using namespace std;

// adjacency list of directed graph
vector<vector<int>> dal;
// list of predecessor count for each vertex
// in the directed graph
vector<int> pred;
// list of undirected edges
vector<pair<int, int>> ude;

vector<int> topological_sort(int n)
{
    // order of nodes
    vector<int> ord(n, -1);
    queue<int> q;

    int o = 1;

    // Find a starting node that has no predecessors.
    //
    // While the complete graph is connected the directed graph may not be.
    // Just topological sort over all nodes with no predeccesors once.
    for (int i = 0; i < n; i++)
    {
        if (pred[i] > 0)
            // node has predecessors
            continue;

        if (ord[i] != -1)
            // node has already been explored
            continue;

        // start topological sort for this connected graph with node i
        q.push(i);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            ord[v] = o++;

            for (int u : dal[v])
            {
                // decrease predecessor count
                pred[u]--;

                if (pred[u] == 0)
                    q.push(u);
            }
        }
    }

    return ord;
}

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;

    dal = vector<vector<int>>(n);
    pred = vector<int>(n);
    ude = vector<pair<int, int>>(l);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        dal[a - 1].push_back(b - 1);
        pred[b - 1]++;
    }

    for (int i = 0; i < l; i++)
    {
        int u, v;
        cin >> u >> v;

        ude[i] = make_pair(u - 1, v - 1);
    }

    vector<int> ord = topological_sort(n);

    // check if directed graph is cyclic
    for (int i = 0; i < n; i++)
        if (ord[i] == -1)
        {
            cout << "impossible" << endl;
            return;
        }

    cout << "possible" << endl;

    // direct undirected edges in order of topological order
    for (int i = 0; i < l; i++)
    {
        int a = ude[i].first;
        int b = ude[i].second;

        if (ord[a] > ord[b])
            swap(a, b);

        cout << a + 1 << " " << b + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(numeric_limits<double>::max_digits10);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}