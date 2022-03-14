# 08 - Dynamic Programming - Longest Common Subsequence (LCS)

## Problem
Given two sequences `X` with length `m` and `Y` with length `n`. Find a subsequence that lies both within `X` and `Y` such that its length is maximal.

**Note:** This differs to the longest common substring problem in that the subsequence can not be consecutive in both sequences.

## Solution
Define `X = <x_1, x_2, ..., x_m>` and `Y = <y_1, y_2, ..., y_n>`. Let `Z = <z_1, z_2, ..., z_k>` be any LCS of `X` and `Y`.

1. If `x_m = y_n` => `z_k = x_m = y_n` and `Z_(k-1)` is LCS of `X_(m-1)` and `Y_(n-1)`
2. If `x_m ≠ y_n` and `z_k ≠ x_m` => `Z` is LCS of `X_(m-1)` and `Y`
3. If `x_m ≠ y_n` and `z_k ≠ y_n` => `Z` is LCS of `X` and `Y_(n-1)`

We now simply compute the length of the LCS with a bottom-up approach.

We build a two-dimensional table with `m+1` rows and `n+1` columns.

The entry at row `i` and column `j` (`[i, j]`) then represents the length of the LCS of the two sequences `X_i` and `Y_j`.

We now fill the table.

First we can fill the `0`-th row and `0`-th column with `0`. (Length of LCS with one Sequence having length `0`)

Now we can iterate through the table starting from the entry `[1, 1]` and fill the values with the above defined recurrance function.

The actual LCS can be reconstructed by starting at the entry `[m+1, n+1]` and backtracking from there.

## Time Complexity
Time Complexity: `O(mn)`