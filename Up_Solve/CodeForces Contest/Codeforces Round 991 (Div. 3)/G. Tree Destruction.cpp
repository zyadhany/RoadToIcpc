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

const int MX = 1e5 + 1;

ll req(vii &adj, vi &res, ll n, ll p) {
    ll ch = adj[n].size();
    ll mx = ch;
    res[n] = ch;
    vi X;

    for (auto neg : adj[n]) {
        if (neg == p) continue;
        ll re = req(adj, res, neg, n);
        mx = max(mx, re + ch - 1);
        X.push_back(re);
    }
    sort(X.rbegin(), X.rend());

    res[n] = mx;
    if (X.size() >= 2) {
        res[n] = max(res[n], X[0] + X[1] + ch - 2);
    }

    return mx - (p != 0);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vii adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi res(n + 1);
    req(adj, res, 1, 0);
    cout << *max_element(all(res)) << '\n';
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
