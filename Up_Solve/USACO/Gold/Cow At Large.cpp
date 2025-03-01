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

const int MODE = 998244353;

using namespace std;

multiset<ll> req(vii &adj, vi &Z, ll n, ll p, ll dpt) {

    multiset<ll> st;

    for (auto neg : adj[n]) {
        if (neg == p) continue;
        auto stt = req(adj, Z, neg, n, dpt+1);
        if (st.size() < stt.size()) swap(st, stt);

        for (auto a : stt) st.insert(a);
    }

    if (adj[n].size() == 1 && p) st.insert(dpt);
    
    auto it = st.lower_bound(dpt*2-1);
    if (it != st.end() && dpt*2 >= *it) Z[n] = 1;

    return st;
}

ll dfs(vii &adj, vi &Z, ll n, ll p) {
    if (Z[n]) return 1;
    ll res = 0;
    for (auto neg : adj[n]) if (neg != p) {
        res += dfs(adj, Z, neg, n);
    }
    return res;
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vii adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi Z(n + 1);

    req(adj, Z, k, 0, 0);

    ll sol = dfs(adj, Z, k, 0);
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
