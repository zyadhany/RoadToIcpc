/**
 * 2Sat: given formula  (a1 ∨ b1)∧(a2 ∨ b2)∧··· ∧(am ∨ bm)
 * to montain that make adge for !a1>b1 and !b1>a1
  if a1 is false b1 must be true and via verse.
 * to solve that we can check if a is in same SCC with -b
    then no solution
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

