/**
 * 2Sat: given formula  (a1 ∨ b1)∧(a2 ∨ b2)∧··· ∧(am ∨ bm)
 * to montain that make adge for !a1>b1 and !b1>a1
  if a1 is false b1 must be true and via verse.
 * to solve that we can check if a is in same SCC with -b
    then no solution
 */

 /*
 // i^j = 1 (Xor)
 // iorj and -ior-j
 sat.add_disjunction(i, false, j, false);
 sat.add_disjunction(i, true, j, true);
// i^j = 0  (not Xor)
// ior-j and -iorj 
sat.add_disjunction(i, true, j, false);
sat.add_disjunction(i, false, j, true);
}
 */

// X is array of pairs as each element is condtion
// -a if a false, a if true.
bool is2SAT (ll n, vp X) {
    Graph gr((n + 1) * 2);

    for (int i = 0; i < X.size(); i++)
    {
        ll l = abs(X[i].first), r = abs(X[i].second);
        ll a = (X[i].first < 0), b = (X[i].second < 0);
        cout << l + a * n << ' ' << r + (b ^ 1) * n << "||\n";
        gr.addEdge(l + (a ^ 1) * n, r + b * n);
        gr.addEdge(r + (b ^ 1) * n, l + a * n);
    }
    auto Z = gr.stronglyConnectedComponents();
    for (int i = 0; i < Z.size(); i++)
    {
        mi Y;
        for (auto m : Z[i]) {
            if (m > n) m -= n;
            if (Y[m]) return 0;
            Y[m] = 1;
        }
    }

    return (1);
}


struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }

    static void example_usage() {
        TwoSatSolver solver(3); // a, b, c
        solver.add_disjunction(0, false, 1, true);  //     a  v  not b
        solver.add_disjunction(0, true, 1, true);   // not a  v  not b
        solver.add_disjunction(1, false, 2, false); //     b  v      c
        solver.add_disjunction(0, false, 0, false); //     a  v      a
        assert(solver.solve_2SAT() == true);
        auto expected = vector<bool>({true, false, true});
        assert(solver.assignment == expected);
    }
};
