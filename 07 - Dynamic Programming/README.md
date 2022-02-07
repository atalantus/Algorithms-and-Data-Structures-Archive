# 07 - Dynamic Programming
Technique of solving a problem by recursively dividing it into subproblems. After solving a subproblem it's solution is cached for later reuse in case the same subproblem comes up again.

## Application
In general Dynamic Programming is applicabale to a problem if it has an **optimal substructure** and **overlapping subproblems**.

Optimal substructure means that the optimal solution to the problem consists in intself of optimal solutions to subproblems.

Overlapping subproblems means that a recursive algorithm for solving such a problem would compute the same subproblem repeatedly.

## Usage
There are two ways to apply Dynamic Programming to a problem **top-down** and **bottom-up**.

These simply differ in the way the solution for the original problem gets computed. 

The top-down strategy works similar to a normal recursive approach were we recursively solve subproblems but also maintain a table
and check first if we have already computed its solution.

The bottom-up strategy instead starts of by solving the smallest possible subproblem and iteratively going to the next "higher" problem storing all solutions in a table until we reach the original problem.

Generally the top-down approach works best when the subproblem space of an original problem is sparse meaning that only few of all possibil subproblems will get explored.

On the other hand bottom-up is better for dense subproblem spaces and since it's easily implemented iteratively it has no additional overhead compared to the recursive top-down approach.