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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void req(vii &adj, set<ll> &st, vi &sk, vi &vis, ll n) {
    if (vis[n] != -1) {
        for (int i = vis[n]; i < sk.size(); i++)
            st.insert(sk[i]);
        return;
    }
    vis[n] = sk.size();
    sk.push_back(n);

    for (auto neg : adj[n]) req(adj, st, sk, vis, neg);

    vis[n] = -1;
    sk.pop_back();
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii Y(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        if (a > b) Y[u].push_back(v);
        if (a < b) Y[v].push_back(u);
    }
    
    set<ll> st;
    vi sk;
    vi vis(n + 1, -1);

    for (int i = 1; i <= n; i++)
        req(Y, st, sk, vis, i);
    

    cout << st.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("fenceplan.in", "r", stdin);
    //freopen("fenceplan.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
