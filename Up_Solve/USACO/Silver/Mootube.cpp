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

const int MODE = 1e9;

using namespace std;

ll req(vector<vp> &adj, ll n, ll p, ll k) {
    ll res = 1;
    for (auto neg: adj[n]) {
        if (neg.first == p || neg.second < k) continue;
        res += req(adj, neg.first, n, k);
    }
    return res;
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vector<vp> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    
    while (q--)
    {
        ll l, r;
        cin >> r >> l;
        cout << req(adj, l, 0, r) - 1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
