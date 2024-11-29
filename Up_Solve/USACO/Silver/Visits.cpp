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

void req(vii &adj, vi &vis, ll n) {
    if (vis[n]) return; vis[n] = 1;
    for (auto neg: adj[n]) req(adj, vis, neg);
}

void solve(int tc) {
    ll n;

    cin >> n;

    ll sol = 0;
    vi X(n + 1);
    vi vis(n + 1);
    vi nx(n + 1);
    vii adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll v; cin >> v >> X[i];
        nx[i] = v;
        adj[v].push_back(i);
        adj[i].push_back(v);
        sol += X[i];
    }
    
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            ll a = nx[i];
            ll b = nx[a];
            while (a != b) a = nx[a], b = nx[nx[b]];
            a = i;
            while (a != b) a = nx[a], b = nx[b];
            b = nx[a];
            ll mn = X[a];
            while (b != a) mn = min(mn, X[b]), b = nx[b];
            sol -= mn;
            req(adj, vis, i);
        }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("shuffle.in", "r", stdin);
    // freopen("shuffle.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
