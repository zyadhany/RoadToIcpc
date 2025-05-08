import pandas as pd
from io import BytesIO

# Create structured data from the extracted PDF content
categories = {
    "Data structures": [
        "DSU", "Segment trees", "Segment Tree with Lazy Propagation", "Sparse table",
        "Fenwick Tree / BIT", "Lower bound on BIT", "Merge Sort Tree", "Ordered Set",
        "SQRT Decomposition", "Mo's algo", "Segment Tree Beats", "Implicit Segment Tree",
        "DSU with Rollbacks", "DSU on Tree", "Monotonous Queue", "MOs with DSU",
        "Divide and Conquer on Queries", "Wavelet Tree", "SQRT Decomposition Split and Build Technique",
        "Persistent Segment Tree", "Persistent Segment Tree with Lazy Propagation",
        "Segment Tree Merging", "Treap"
    ],
    "Strings": [
        "KMP", "Trie", "Hashing", "Z-algo", "Manacher", "Suffix array", "Aho corasick",
        "Number of pal in range", "Suffix automaton", "Persistent Trie"
    ],
    "Number Theory": [
        "Sieve", "Binary Exponentiation", "Modular Inverse", "Combinatorics Basics",
        "nCr Modulo Any Mod", "Pigeonhole Principle", "Stars And Bars",
        "Hockey Stick Identity", "Inclusion Exclusion Principle", "Bionomial theorem",
        "Catalan Number", "Burnside's Lemma", "Lucas Theorem", "Prefix Sum Queries of nCi",
        "Extended Euclid", "Linear Diophantine Equations", "Chinese Remainder Theorem",
        "Euler Totient (phi function)", "Mobius Function", "Primality tests",
        "Linear Congruence Equation", "Pollard Rho", "Primitive Root", "Discrete Log",
        "Discrete Root", "Prime Counting Function", "Sum of The Number of Divisors in cbrt(n)",
        "Baby Step Giant Step"
    ],
    "Math & Probability": [
        "Matrix Power", "FFT", "NTT", "FWHT", "Gaussian Elimination",
        "Gaussian Elimination module prime", "Inverse of a Matrix",
        "Inverse of a Matrix mod 2 (Xor Inverse)", "Basis Vector", "Probability & Expectation",
        "Linearity of Expectation", "Expected Value Powers Technique"
    ],
    "Trees": [
        "LCA", "Rerooting technique", "Dp on trees", "Small to large", "Tree Isomorphism",
        "HLD", "Centroid decomposition"
    ],
    "Graph Theory": [
        "DFS and BFS", "Dijkstra's Algorithm", "Dijkstra on Segment Tree", "0/1 BFS",
        "Prim's MST", "Krushkal's MST", "Bellman Ford", "Floyd Warshall", "Graph Coloring",
        "Min colors to color a graph", "Inverse Graph (given erased edges)", "DFS Tree",
        "Articulation Bridges and Bridge Tree", "Online Articulation Bridges",
        "Articulation Points.", "SCC", "Chinese Postman Problem", "SPFA", "2 SAT",
        "Eulerian Path on a Directed Graph", "Eulerian Path on an Undirected Graph",
        "Number of 3 and 4 length Cycles", "Counting Labeled Graphs", "Edge Coloring of Simple Graph",
        "Edge Coloring of Bipartite Graph", "Kirchoffs Theorem ft Number of MSTs",
        "Hamiltonian Path Heuristic Algorithm"
    ],
    "Matching & Flows": [
        "Max Matching Bipartite", "Max Flow"
    ],
    "DP": [
        "Bitmask DP", "Digit DP", "SOS DP", "Divide and Conquer Optimization",
        "Convex Hull Trick", "Li Chao Tree", "Knuth Optimization"
    ],
    "Geometry": [
        "Point and Vector", "Lines & Segments", "Circles", "Polygons", "Point in Polygon",
        "Convex Hull", "Line Sweep", "Segment Segment Intersection(2D)", "Plane Plane Intersection",
        "Picks Theorem", "Closest Pair of Points", "All Pair Segment Intersection.",
        "Half Plane Intersection"
    ],
    "Game Theory": [
        "Nim Game", "Grundy Number", "Games on Arbitrary Graphs"
    ],
    "Miscelleneous": [
        "Two Pointers", "Binary Search", "Fraction Binary Search", "Ternary Search",
        "Parallel Binary Search", "Bishop Placement", "Gray Code", "Randomized Algorithms",
        "Bitsets"
    ]
}

# Create a DataFrame in long format
rows = []
for topic, items in categories.items():
    for item in items:
        rows.append({"Category": topic, "Topic": item})

df = pd.DataFrame(rows)

# Save to Excel
output = BytesIO()
df.to_excel(output, index=False, sheet_name="Topics Scale")
output.seek(0)

