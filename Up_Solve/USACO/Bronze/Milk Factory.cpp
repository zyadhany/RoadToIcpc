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

ll req (vii &Y, vi &vis, ll n) {
    if (vis[n]) return 0;
    vis[n] = 1;

    for (auto neg : Y[n]) vis[n] += req(Y, vis, neg);

    return vis[n];
}

void solve(int tc) {
    ll n;

    cin >> n;

    vii Y(n + 1);
    vi ind(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        Y[v].push_back(u);
        ind[u]++;
    }
    
    ll st = -1;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i]) continue;
        if (st != -1) MUN;
        st = i;
    }
    
    if (st == -1) MUN;

    vi vis(n + 1);
    ll cnt = req(Y, vis, st);

    if (cnt == n) cout << st << '\n';
    else MUN;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    
    #ifndef ONLINE_JUDGE
        freopen("factory.in", "r", stdin);
        freopen("factory.out", "w", stdout);
    #endif
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
