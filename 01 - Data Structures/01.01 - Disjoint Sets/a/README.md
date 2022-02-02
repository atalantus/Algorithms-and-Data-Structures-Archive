# 01.01 - Disjoint Sets - Problem A

## Description
Given a set of nodes and a list of connections between them. 
If two nodes are connected directly or indirectly they are in the same set.

Check if two nodes are in the same set.

## Input
- Integer `t`. `t` test cases follow.
- For each test case:
  - Integers `a, b`: `a` number of nodes from `1` to `a`, `b` number of connections.
  - `b` lines follow. Each line contains two integers `d, e` describing a connection between node `d` and node `e`.

## Output
For each test case, output one line containing "Case #`i`: `x`" where `i` is its number, starting at 1, 
and `x` is either "Yes" or "No" depending on if node 1 and node `a` are in the same set.

## Constraints
- `1 <= t <= 20`
- `1 <= a <= 10^4`
- `0 <= b <= 10^4`
- `1 <= d,e <= a`

## Example 1
```
Input:
2
3 2
1 2
2 3

3 1
1 2

Output:
Case #1: Yes
Case #2: No
```