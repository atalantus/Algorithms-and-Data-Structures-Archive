# 03.03 - Topological Sort (TS) - Problem A

## Description
Given a graph with directed and undirected edges. Direct every undirected edge such that the resulting graph is acyclic.

## Input
- Integer `t`. `t` test cases follow.
- For each test case:
    - Integers `n, m, l`: `n` is the number of nodes from `1` to `n`. `m` is the number of directed edges. `l` is the number of undirected edges.
    - `m` lines follow each containing two integers `a, b` representing a directed edge going from node `a` to node `b`
    - `l` lines follow each containing two integers `u, v` represnenting an undirected edge going from node `u` to node `v`

## Output
If such a resulting graph is not possible print "Case #`i`: impossible" where `i` is the test case number starting at `1`. Otherwise print "Case #`i`: possible", followed by `l` lines. The `i`-th line should contain two integers `a_i, b_i` meaning the previously undirected `i`-th edge is now directed going from node `a_i` to node `b_i`.

## Constraints
- `1 <= t <= 20`
- `1 <= n <= 1000`
- `0 <= m + l <= 10000`
- There are no loop edges.
- There is at most one total edge between any two nodes.

## Example 1
```
Input:
3
4 2 3
1 2
4 3
3 1
2 4
2 3

4 4 1
1 2
4 3
3 1
2 4
2 3

8 5 6
2 1
3 2
2 6
4 5
5 8
1 4
2 5
3 7
4 8
6 7
6 8

Output:
Case #1: possible
1 3
4 2
2 3
Case #2: impossible
Case #3: possible
4 1
2 5
3 7
4 8
7 6
6 8
```

## Example 2
```
Input:
3
7 4 4
6 2
6 5
4 2
6 4
3 7
5 7
4 7
3 5

8 4 2
1 6
6 4
3 1
4 3
7 6
1 2

7 5 4
6 5
5 7
5 4
2 7
5 3
6 4
1 5
1 2
6 1

Output:
Case #1: possible
3 7
7 5
7 4
3 5
Case #2: impossible
Case #3: possible
6 4
1 5
1 2
1 6
```