# 04.02 - Segment Tree
Data Structure used to efficiently store and maintain information about intervals, or segments.

- Segment tree is a binary tree
- Each node stores a value `v` for the interval `[l,r]`
- Root node represents the full interval `[0,n-1]`
- If node `v` represents `[l,r]`, its left child represents `[l,m]` and its right child
`[m+1,r]` where `m=(l+r)/2`
- Leaves represent unit-intervals `[t,t]`
- segment tree has height `H = floor(log2(2n-1))`

## Implementation Optimizations
- Round `n` up to power of `2` (fill tail with `0`) for complete binary tree 
- Store node values in array of length `2n` 
- Begin with storing root node at index `1` (`0`th element is unused)
- Children of node `i` are stored at `2i` and `2i+1`
- Calculate layer `l` of node `i` in tree as `l = floor(log2 i)`
- Calculate `[l,r]` bounds of node `i` as `[(i - (1 << l)) << (H - l), (((i - (1 << l)) + 1) << (H - l)) - 1]` (**Note:** That always calculating bounds on demand may decrease performance instead of storing bounds additionally to node values. Depends on cache locality.)

## Operations
### build(input a[], index i) - `O(n)`
Recursively build the segment tree for input `a`.

Start at root node and as long as we're not at a leaf recursively call build on left, right child.

When at leaf store input value from `a` and return it.

On return of left and right child store the sum of the two values and return it.

### sum(interval [l,r], index i) - `O(log n)`
Return the sum of the values stored in the interval `[l,r]`

1. Check if we're completely outside the interval. If so return `0`.
2. Propagate
3. Check if we're fully inside the interval. If so return node value.
4. Return the sum of the left child **plus** the sum of the right child (**Note:** For Segment Trees of different kind - e.g. storing maximum/minimum of interval - we would choose another binary operator than Addition.)

### propagate(index i) - `O(1)`
Additionally to node value store lazy value representing not yet propagated additional values for an interval.

1. Add lazy value `z` to node `i` at `[l,r]`: add value `(r-l+1)*z`
2. If not at leaf add lazy value to child nodes
3. Reset lazy value for node `i` to `0`

## range_add(interval [l,r], value v, index i) - `O(log n)`
Add value to all nodes in interval `[l,r]`.

1. Check if completely outside of interval. If so return.
2. Check if we're fully inside the interval. If so add value as lazy value, propagate and return.
3. If we're not at leaf. Recursively call range_add on children. Update node value as left child value **plus** right child value.