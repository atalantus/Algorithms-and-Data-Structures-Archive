# 08 - Dynamic Programming - 0-1 Knapsack Problem

## Problem
Having `n` different items each with its own value and weight. 
Find the combination of items such that the total value is maximal and the weight does not exceed a certain threshold `W`. 

The decision version of this Knapsack Problem is weakly **NP-complete**.

## Solution
We build a two-dimensional table with `n+1` rows and `W+1` columns. (so we have both a row representing no items and a column representing a weight limit of `0`)

The entry at row `i` and column `j` (`[i, j]`) then represents the maximum value that can be obtained by only taking items 
from `1` to `i` into account while not exceeding the weight limit `j`.

We now fill the table.

First we can fill the `0`-th row with `0`. (max value with no items is `0` for any weight limit)

Then the entry `[i, j]` is the maximum of the two values `[i-1, j]` and `[i-1, w-w_i] + v_i` where `w_i` and `v_i` are the
weight and value of item `i`.

The list of chosen items for a given weight limit `w` can be reconstructed by starting at the entry `[n+1, w+1]` and backtracking from there.

## Time Complexity
This algorithms runs in the **pseudo-polynomial time** `O(nW)`.