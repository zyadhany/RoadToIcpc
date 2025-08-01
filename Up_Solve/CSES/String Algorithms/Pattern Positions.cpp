#include "bits/stdc++.h"
#define ll long long
#define vi vector<ll>
#define pl pair<ll, ll>
#define vp vector<pl>
#define vii vector<vi>
using namespace std;
#define ln "\n"


const int K = 26;

struct Vertex {
    int next[K];
    ll output = INT32_MAX;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    vi adj;

    vi ind; // ind of pattern

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

const int MXTRIE = 5e5;
int curnd = 0;
Vertex t[MXTRIE];

struct AhoCorasick {
    void add_string(string const& s, int ind = -1) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = ++curnd;
                t[curnd] = Vertex(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].ind.push_back(ind);
    }

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }
    int go(int v, char ch) {
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }

    AhoCorasick() {
        t[0] = Vertex();
        curnd = 1;
    }
};

void solve() {
    string s;
    cin >> s;

    AhoCorasick aho;

    ll q; cin >> q;
    vi sz(q);
    for (int i = 0; i < q; i++)
    {
        string t; cin >> t;
        sz[i] = t.size();
        aho.add_string(t, i);
    }    
    ll at = 0;
    ll ind = 0;
    for (auto c : s) {
        ind++;
        at = aho.go(at, c);
        t[at].output = min(t[at].output, ind);
    }
    
    for (int i = 1; i <= curnd; i++)
    {
        t[aho.get_link(i)].adj.push_back(i);
    }

    vi res(q, INT32_MAX);
    function<ll(ll)> dfs = [&](ll u) -> ll {
        ll got = t[u].output;
        for (auto v : t[u].adj) got = min(got, dfs(v));
        for (auto v : t[u].ind) res[v] = got;
        return got;
    };
    dfs(0);
    for (int i = 0; i < q; i++)
    {
        if (res[i] == INT32_MAX) cout << "-1\n";
        else cout << res[i] - sz[i] + 1 << '\n';
        }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // freopen("puzzle.in", "r", stdin);
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
