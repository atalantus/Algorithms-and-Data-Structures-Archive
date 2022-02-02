# 01.01 - Disjoint Sets
Data Structure for operation and maintainance on disjoint sets over elements also often called **Disjoint Set Union** (DSU) or **Union Find**.

In general it has 3 operations:
- `make_set(x)`: Adds the node `x` to the datastructure
- `find_set(x)`: Finds the **root**/**representative** of the set of node `x`
- `union_set(x, y)`: Unites the two sets of node `x` and node `y`

## Path Compression
When traversing to the root of a node's set we afterwards make sure to update the parent
of each node traversed to directly point to the set's root.

## Union by Size
Instead of choosing arbitrarily one node's set to merch into the other node's set
during the `union_set(x, y)` operation we always merge the smaller set into the bigger one.

## Time Complexity
With the Path Compression and Union by Size optimization the time complexity is near constant being `O(α(n))` with `α(n)` being the inverse Ackermann function.