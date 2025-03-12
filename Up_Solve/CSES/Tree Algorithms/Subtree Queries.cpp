#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;


using namespace std;


class Graph {
public:
    int size;
    vi vis;
    vii adj;

    vi Travese, Indeg, SubSize;

    ll dfs(int n, int p) {
        ll summ = 1;
        Indeg[n] = Travese.size();
        Travese.push_back(n);
        for (auto neg : adj[n])
            if (neg != p) summ += dfs(neg, n);
        return (SubSize[n] = summ);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Graph(ll n) {
        size = n;
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        SubSize.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


ll rangequery(const vi& Z, int l, int r) {
	ll summ = 0;
	for (int i = r; i > 0; i -= i & -i)
		summ = (summ + Z[i]);
    
    for (int i = l - 1; i > 0; i -= i & -i)
        summ = (summ - Z[i]);

    return summ;
}

void updatepoint(vi& Z, ll n, int at) {
	for (int i = at; i < Z.size(); i += i & -i)
		Z[i] = (Z[i] + n);
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i + 1];
    }
    
    Graph gr(n);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
    }
    
    gr.dfs(1, 0);

    vi BIT(n + 1);
    for (int i = 1; i <= n; i++)
    {
        updatepoint(BIT, X[i], gr.Indeg[i] + 1);
    }
    while (q--)
    {
        ll ty; cin >> ty;

        if (ty == 1) {
            ll l, r; cin >> l >> r;
            ll v = r - X[l];
            X[l] = r;
            updatepoint(BIT, v, gr.Indeg[l]+1);
        } else {
            ll l; cin >> l;
            cout << rangequery(BIT, gr.Indeg[l]+1, gr.Indeg[l] + gr.SubSize[l]) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("hopscotch.in", "r", stdin);
    // freopen("hopscotch.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
