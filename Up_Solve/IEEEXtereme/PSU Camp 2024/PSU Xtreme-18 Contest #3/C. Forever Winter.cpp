#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii Y(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }
    
    ll x, y;

    ll leaf;
    for (int i = 1; i <= n; i++)
        if (Y[i].size() == 1) leaf = i;

    ll node = Y[leaf][0];
    y = Y[node].size() - 1;

    ll center;
    for (auto neg : Y[node])
        if (Y[neg].size() != 1) center = neg;
    x = Y[center].size();

    cout << x << ' ' << y << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
