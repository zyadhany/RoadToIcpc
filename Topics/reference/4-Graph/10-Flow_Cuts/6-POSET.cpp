// POSET: Partial order <= (reflexive, antisymmetric, transitive); elements can be incomparable.
// Chain: totally ordered subset (x1 <= x2 <= ...). Antichain: pairwise incomparable subset.
// Dilworth's Thm: Poset Width = Size of Max Antichain = Min Chain Partition size.
// General Poset: Min Chain Cover = N - Max Bipartite Matching (directed edges u_x -> v_y for x < y).
// 2D Points (x1<=x2 & y1<=y2): Antichains have decreasing y when sorted by x -> solve in O(N log N) via std::set / LIS.