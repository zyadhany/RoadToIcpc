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

pl req(vii &adj, ll n, ll p) {
    pl res = {0, n};
    for (auto neg : adj[n]) {
        if (neg != p) {
            pl re = req(adj, neg, n);
            re.first++;
            if (re.first > res.first) res = re;
        }
    }
    return res;
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
    
    pl k = req(adj, 1, 0);
    k = req(adj, k.second, 0);
    cout << k.first << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("milkvisits.in", "r", stdin);
    // freopen("milkvisits.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
