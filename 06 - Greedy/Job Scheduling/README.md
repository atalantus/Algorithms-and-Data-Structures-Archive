# 06 - Greedy - Job Scheduling

## Problem
Given `n` jobs with different running times and `m` processors.
What is the shortest time to complete all jobs?

## Solution
Iterate over all jobs assigning the job to the currently least busy (by total scheduled running time) processor.

## Approximation
The shortest time will be within factor `2` of the optimal shortest time.

By first sorting the jobs in decreasing order of running time this can be further decreased to a factor of `3/2`.

## Time Complexity
Time Complexity is `O(m+n log m)` with an additional `n log n` if we sort jobs first.