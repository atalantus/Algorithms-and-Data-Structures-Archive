# 05.02 - Push-Relabel Method
Finds the maximum flow by successively adapting a preflow that saturates a cut until this preflow is a valid flow.

A preflow is similarly defined as a flow with the exception that the total flow out of a node can actually also be less than
the incoming flow of that node.

A node that has more incoming flow than outgoing flow is called **active**.

Additionally the Push-Relabel Method defines a **labelling** function `l` that associates each node with an non-negative integer (height/level) and is **valid**
if the source `s` has a label of `|V|`, the target `t` has a label of `0` and for any residual edge `(u,v)`, `l(u) ≤ l(v) + 1`. (Intuitively if we have a residual edge from `u` to `v` it can only go down - seeing the labelling as height of a node - by at most one.)

We will later use this to define that we can only **push** flow downhill. (Note that the flow can be positive going uphill but we will only push flow downhill.)

The Push-Relabel Method starts with a **preflow** that saturates all outgoing edges from the source `s` and defines a flow
of `0` for all other edges. The labelling for every node except `s` and `t` starts at `0`.

Now the Push-Relabel Method works in two phases.

**Phase 1 - Pushing Flow Downhill:** 

We push our preflow downhill as long as we can. 

If at one point the only non-saturated edges going out of an active node `u` go to nodes at the same or higher level than `u` we must increase `u`'s level to the level of it's lowest successor which it has a non-saturated edge to plus `1`.

Eventually we won't be able to push any more flow meaning all the preflow that can reach the target has reached it.

After this phase we will have the maximum flow value but our preflow will not correctly represent this maximum flow.

Now we move on the second phase.

**Phase 2 - Returning Excess Flow:**

Since we can't push any more flow to the target all the additional excess flow of the active vertices must return to the source to make the current preflow a valid flow. (`0` excess flow means incoming flow equals outgoing flow => valid flow)

We therefore continue to relabel nodes above the sources height `|V|` to push all excess flow back.

After all excess flow is back at the source the preflow will not only be a valid flow but also the maximum since throughout this whole procedure we always maintained a saturated cut.

## Optimizations
These optimizations will not change the asymptotic runtime but might still increase performance.

### Initial Labelling Heuristic
- At the start of the first phase compute the label for each node as the distance to the target node (with BFS from target)
- At the start of the second phase compute the label for each node as the distance to the source node + `|V|` (with BFS from source)

### Gap Heuristic
Keep track of the saturated cut in the residual graph by keeping track of how many vertices for each height value exist.

If we have this height value `l'` for which no node with this height value exists than any node with a height value greater than `l'` and smaller than `|V|` must be disconnencted and can be relabeled to `|V|+1` immeadiately.

## Time Complexity
There exists different algorithms for the Push-Relabel Method which all only differ in the order of choosing the next operation:
- **Goldberg-Tarjan Algorithm:** Any order - Time Complexity: `O(|V|^2|E|)`
- **Relabel-To-Front Algorithm:** Keep list of nodes. Go over nodes in order of list. Each time we relabel a node push it to the front. - Time Complexity: `O(|V|^3)`

## Algorithm
```c++
// Pushes flow from u to v
void push(int u, int v)
{
    // Get minimum of excess flow of u and possible flow t push from u to v

    // Add this minimum to the flow of (u,v)
    // Subtract this minimum from the flow of (v,u)

    // Subtract this minimum from the excess flow of u
    // Add this minimum to the excess flow of v
}

// Relabels node u such that it can push flow down again
void relabel(int u)
{
    // Find the lowest successor v of u such that (u,v) is not saturated

    // Increase u's height to height of this v + 1
}

void max_flow()
{

}
```