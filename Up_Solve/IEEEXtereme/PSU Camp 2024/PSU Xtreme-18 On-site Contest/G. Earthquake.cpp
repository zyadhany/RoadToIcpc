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

vii Y(1e6);
vi vis(1e6);

void req(ll n) {
    if (vis[n]) return;
    vis[n] = 1;
    for (auto neg : Y[n]) req(neg);
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }

    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        cnt++;
        req(i);
    }
    
    cout << cnt - 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("socdist.in", "r", stdin);
    //freopen("socdist.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
