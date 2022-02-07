# 06 - Greedy - 0-1 Knapsack Problem

## Problem
Having `n` different items each with its own value and weight. 
Find the combination of items such that the total value is maximal and the weight does not exceed a certain threshold `W`. 

The decision version of this Knapsack Problem is weakly **NP-complete**.

## Solution
We construct two solutions.

The first solution iterates over all items in decreasing order of value per unit of weight and adds the item if it still fits the weight limit.

The second solution is simply the first item that was not added in our first solution.

Now we choose the maximum of both solutions.

**Note:** Only doing the first solution can be arbitrarily bad. Consider for any `W > 2` only the two items `(value: 2, weight: 1)`,
`(value: W, weight: W)`. The first solution will always return only `2` as the maximum value while the optimal value is clearly `W`.

## Approximation
The solution found by this Greedy approach is within a factor of `1/2` of the optimal solution.

## Time Complexity
This algorithms runs in `O(n log n)` time but can be improved up to linear `O(n)` time with using recursion and linear time median.