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

void req(vii &Y, vi &vis, vi &X, ll n) {
    if (vis[n]) return;
    vis[n] = 1;
    X.push_back(n);

    for (auto neg : Y[n]) {
        req(Y, vis, X, neg);    
    }
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    vi vis(n + 1, 0);
    vi L, R;
    vii Y;
    req(adj, vis, L, 1);
    vis.assign(n + 1, 0);
    req(adj, vis, R, n);
    vis.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vi X;
        req(adj, vis, X, i);
        sortx(X);
        Y.push_back(X);
    }

    set<ll> st(all(L)), en(all(R));
    ll sol = INT64_MAX;
    for (auto &X : Y) {
        ll l = INT64_MAX;
        ll r = INT64_MAX;
        for (auto x : X) {
            auto it = st.lower_bound(x);
            if (it != st.end()) l = min(l, *it - x);
            if (it != st.begin()) l = min(l, x - *prev(it));
            it = en.lower_bound(x);
            if (it != en.end()) r = min(r, *it - x);
            if (it != en.begin()) r = min(r, x - *prev(it));
        }
        ll re = l * l + r * r;
        sol = min(sol, re);
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
