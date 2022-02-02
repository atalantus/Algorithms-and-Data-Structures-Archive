#include <bits/stdc++.h>

using namespace std;

// parent for each node's set.
// a value of -1 means this node is the root of its set
vector<int> parent;
// size for each node's set if that node is the root
vector<int> set_size;

/**
 * Find the root of the set of a node and apply path compression.
 */
int find_set(int x) {
    // find root
    int r = x;
    while (true) {
        int p = parent[r];
        if (p == -1) break;
        r = p;
    }

    // path compression
    int c = x;
    while (c != r) {
        int p = parent[c];
        parent[c] = r;
        c = p;
    }

    return r;
}

/**
 * Unite two sets via comparing the sets' sizes.
 */
void union_set(int x, int y) {
    int rx = find_set(x);
    int ry = find_set(y);

    if (rx == ry) return;

    if (set_size[rx] > set_size[ry])
        swap(rx, ry);
    
    parent[rx] = ry;
    set_size[ry] += set_size[rx];
}

void solve() {
    int a, b;
    cin >> a >> b;

    parent = vector<int>(a, -1);
    set_size = vector<int>(a, 1);

    for (int i = 0; i < b; ++i) {
        int d, e;
        cin >> d >> e;

        union_set(d - 1, e - 1);
    }

    if (find_set(0) == find_set(a - 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(numeric_limits<double>::max_digits10);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}