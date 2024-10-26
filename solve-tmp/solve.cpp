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

ll req(vii &Y, vi &X, vi &Z, ll n, ll p) {
    ll at = lower_bound(all(Z), X[n]) - Z.begin();
    ll prev = -1;
    bool isit = (at == Z.size());

    if (isit) Z.push_back(X[n]);
    else prev = Z[at], Z[at] = X[n];

    ll sol = Z.size();
    for (auto neg : Y[n]) {
        if (neg == p) continue;
        ll re = req(Y, X, Z, neg, n);
        sol = max(sol, re);
    }

    if (isit) Z.pop_back();
    else Z[at] = prev;

    return sol;
}

void solve(int tc) {
    ll n;

    cin >> n;
    
    vi X(n + 1);
    vii Y(n + 1);

    for (int i = 0; i < n; i++)
        cin >> X[i + 1];

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }

    ll sol = 0;    
    for (int i = 1; i <= n; i++)
    {
        vi tr;
        ll re = req(Y, X, tr, i, 0);
        sol = max(sol, re);
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
