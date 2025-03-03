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

vi dfs(vii &adj, vi &vis, vi &Z, ll n) {
    if (vis[n] == 1) return vi();
    if (vis[n] == -1) {
        vi sol({n});
        while (Z.back() != n)
        {
            sol.push_back(Z.back());
            Z.pop_back();
        }
        sol.push_back(n);
        reverse(all(sol));
        return sol;
    }
    vis[n] = -1;
    Z.push_back(n);

    for (auto neg : adj[n]) {
        auto sol = dfs(adj, vis, Z, neg);
        if (!sol.empty()) return sol;
    }

    Z.pop_back();
    vis[n] = 1;
    return vi();
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vi vis(n + 1);
    vi Z;
    for (int i = 1; i <= n; i++) {
        vi sol = dfs(adj, vis, Z, i);
        if (!sol.empty()) {
            cout << sol.size() << '\n';
            for (auto a : sol) cout << a << ' ';
            cout << '\n';
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("tractor.in", "r", stdin);
    // freopen("tractor.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
