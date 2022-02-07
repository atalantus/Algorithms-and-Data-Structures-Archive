# 06 - Greedy
Technique of approximating the optimal solution to a problem by iteratively choosing locally optimal solutions for its subproblems.

Greedy and Dynamic Programming algorithms work somewhat similar in the sense that both techniques divide a problem into suproblems.

However Greedy algorithms always just choose the locally optimal solution for the next subproblem while a Dynamic Programming approach
takes the complete possible solution space for all its dependent suproblems into account.

## Application
Greedy algorithms are applicable to optimization problems that can be formulated as a problem where one makes consecutive choices.

This means that some problems can actually be efficiently and optimally solved with greedy approaches (Kruskal's Algorithm, Prim's Algorithm, Dijkstra's Algorithm) while other solutions for for example NP-hard problems can be efficiently approximated within a factor of the actual
optimal solution. (Knapsack Problem within factor `1/2` of optimal solution, Job Scheduling within factor `3/2` of optimal solution, Various Facility Location Problems)

## Usage
We iteratively make each choice locally optimal until we either found a solution to the original problem or ran out of choice candidates.