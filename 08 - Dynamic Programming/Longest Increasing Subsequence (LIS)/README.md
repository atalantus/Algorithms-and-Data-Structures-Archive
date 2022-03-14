# 07 - Dynamic Programming - Longest Increasing Subsequence (LIS)

## Problem
Given a sequence of numbers `S` with length `n`. Find a subsequence of increasing numbers such that its length is maximal.

## Solution
We build an array `A` of size `n+1`. (consider all possible LIS lengths from `0` up to `n`)

The `i`-th element is the index of the lowest possible value `v` in `S` such that we have an increasing subsequence of length `i`
that ends with value `v`.

We now fill the array.

First the `0`-th entry stores a value representing that no such index value exists (e.g. `-1`).

Now we can iterate over the sequence `S` where for the `i`-th number `n_i` we do a binary search over the values at the indices already computed in `A`
to find the latest index `j` in `A` such that the value `S[j]` is smaller (or equal if we want longest not-strictly increasing subsequence) than
`n_i`.

With this index `j` and the number `n_i` we know have a new increasing subsequence of length `j + 1`.

If the `j+1`-th entry in `A` either hasn't been set so far or the value in `S` referenced by its index is greater than `n_i` update the `j+1`-th entry in `A` to be `i`.

The length of the LIS is than the latest index in `A` which was set. (This can be kept track of with e.g. an additional `max_length` variable.)

Additionally if we want the actual LIS we store an additional array of size `n` where for each number `i` we keep track of the ancestor (number previous to `i` in the LCS which contains `i`) index. Then we can simply reconstruct the LCS.

## Time Complexity
Time Complexity: `O(n log n)`