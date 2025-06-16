/*
Euler's Formula: For any planer graph.
V - E + F = 2
V: Number of vertices
E: Number of edges
F: Number of faces (including the outer face)
planer graph: A graph that can be drawn on a plane without edges crossing.

example:
square has 4 vertices, 5 edges -> 4 size + diagonal edge
V(4) - E(5) + F = 2
F = E - V + 2 = 3. : left and right diagonal face, outer face

Disconnected Graphs:
V - E + F = C + 1
C: Number of connected components

Bound:
if eavery face has at least k edges.
E <= k(V - 2) / (k - 2)


number of cycles:
cycles = E - V + C
the number of inner faces is equal to the number of cycles in the graph.
Cycles = F-1
*/