# 05 - Maximum Flow
Problem of finding a maximum flow inside a flow network.

Two general solution methods exist:

1. **Ford-Fulkerson Method:** Start with a valid flow and successively increase it (such that its still a valid flow) until it saturates a cut => the flow is maximal
2. **Push-Relabel Method:** Start with a preflow (non-valid flow) that saturates a cut and then successively adapt the preflow (such that it still saturates a cut) until its a valid flow => the flow is maximal

Different problems can in fact be formulated as a maximum flow problem such as maximal bipartite matchings, the baseball elimination problem or project selection.

## Contents
- ### [05.01 - Ford-Fulkerson Method](05.01%20-%20Ford-Fulkerson%20Method)
    Finds the maximum flow by repeatedly augmenting an initial flow along augmenting paths until no more augmenting paths exist.
- ### [05.02 - Push-Relabel Method](05.02%20-%20Push-Relabel%20Method)
    Finds the maximum flow by successively adapting a preflow that saturates a cut until this preflow is a valid flow.

## Flow Network
Directed Graph where each edge has a non-negative capacity and there are two designated vertices, the **source** `s` and the **target** `t`.

Additionally the following transformations can be used:
- **Undirected Graph**: Replace each undirected edge with two antiparallel directed edges
- **Antiparallel Edges**: Insert one additional vertex `w`, remove one of the antiparallel edges `(u, v)` with capacity `c` and insert the two new edges `(u, w)`, `(w, v)` both with capacity `c`
- **Multiple souces/sinks**: Add super-source/sink and edges with infinite capacity to other sources/sinks
- **Vertex capacity**: Split up vertex into two vertices (input and output) and add an edge from input to output with the vertex capacity

## Flow
For a given Flow Network the Flow is a function which assigns each edge a flow value such that:
1. The flow of an edge this value is **less or equal** to the capacity of this edge 
2. The flow into a vertex **equals** the flow out of the vertex.

The **value** of a Flow is the total flow leaving the source minus the total flow coming into the source.

The **Maximum Flow Problem** is the problem of finding a flow for a given flow network such that the value of this flow is maximal.

An edge with a flow equal to its capacity is called **saturated**.

## Residual Network
For a given flow network with edges in `E` and a flow `f` the residual network is the actual underlying graph maintained and updated by max-flow algorithms.

It has the same vertices as the original flow network but different edges.

For any two pairs of vertices `u,v` there exists a **residual edge** `(u,v)` in the residual graph with its capacity defined by:
- If `(u,v)∈E`: `c(u,v) - f(u,v)` (allows to send more flow along this edge until its saturated)
- If `(v,u)∈E`: `f(v,u)` (allows to send flow back / undo flow)
- Otherwise: `0`

The residual network is then the network over all those edges with capacity greater than `0`.

## Augmenting Flow
If `f` is a flow in a flow network with edges in `E` and `f'` is a flow in the corresponding residual network, then the augmentation `(f ↑ f')` of `f` by `f'` is a flow in the flow network defined as

`(f ↑ f')` for the edge `(u,v)` is:
- If `(u,v)∈E`: `f(u,v) + f'(u,v) - f'(v,u)`
- Otherwise: `0`

## Augmenting Path
For a given flow network and its corresponding residual network an augmenting path is a simple path in the residual network going from `s` to `t`.

The **residual capacity** of such a path is defined as the minimum capacity of all edges along the path.

The flow of an augmenting path is defined as its residual capacity on any edge along the path and `0` on all others.

## Cut
A Cut of a flow network is a partition of vertices into two subsets `S` and `T` such that `s∈S` and `t∈T`.

The **capacity** of a cut is defined as the total capacity of all edges going from `S` to `T`.

A **minimum cut** of a network is a cut whose capacity is minimum over all possible cuts.

The **net flow** of a cut is equal to total flow of all edges going from `S` to `T` minus the total flow of all edges going from `T` to `S`.

(**Note:** The net flow of any cut is equal to the flow value.)

A cut is **saturated** if the flow of all edges going from `S` to `T` is equal to that edge's capacity.

## Max-Flow Min-Cut Theorem
For a given flow network the maximum flow value is equal to the capacity of the minimum cut.

This intuitively makes sense as the minimum cut defines the "bottleneck" of the total flow going from `s` to `t`.

This means the following statements are equivalent:
- The flow of a network is maximal
- No augmenting paths exist
- There exists a saturated cut
