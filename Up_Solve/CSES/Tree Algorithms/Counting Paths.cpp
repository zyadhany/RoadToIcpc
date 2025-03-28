#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
using namespace std;
 
set<ll> req(vii & adj, vii &X, vi &dp, ll u, ll p) {
    set<ll> st(all(X[u]));

    for (auto neg : adj[u]) if (neg != p) {
        auto st2 = req(adj, X, dp, neg, u);
        if (st2.size() > st.size()) swap(st, st2);

        for (auto x : st2) {
            if (st.count(x)) {
                st.erase(x);
                dp[u]++;
            } else {
                st.insert(x);
            }
        }
    }

    dp[u] += st.size();
    return st;
}
 
void solve(ll tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vii X(n + 1);
    vi dp(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        if (u == v) dp[u]++;
        else X[u].push_back(i), X[v].push_back(i);
    }
    
    req(adj, X, dp, 1, 0);

    for (int i = 0; i < n; i++)
    {
        cout << dp[i + 1] << ' ';
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
