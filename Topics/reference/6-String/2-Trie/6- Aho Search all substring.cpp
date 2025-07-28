// give string s and q strings t for each t tell how many time it appear is string s as substring.
void solve() {
    string s;
    cin >> s;

    AhoCorasick aho;

    ll q; cin >> q;
    for (int i = 0; i < q; i++)
    {
        string t; cin >> t;
        aho.add_string(t, i);
    }    
    ll at = 0;
    for (auto c : s) {
        at = aho.go(at, c);
        t[at].output++;
    }
    
    for (int i = 1; i <= curnd; i++)
    {
        t[aho.get_link(i)].adj.push_back(i);
    }

    vi res(q);
    function<ll(ll)> dfs = [&](ll u) -> ll {
        ll got = t[u].output;
        for (auto v : t[u].adj) got += dfs(v);
        for (auto v : t[u].ind) res[v] = got;
        return got;
    };
    dfs(0);
    for (auto a : res) cout << a << '\n';
}