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

const  int INF = 1e9;
const int MXN = 3e5+10;
pl X[MXN]={pl()};
ll Y[MXN] = {0};
pl dp1[MXN], dp2[MXN];
vector<int> adj[MXN];

void dfs1(ll n, ll p) {
    
    for (auto neg : adj[n]) if (neg != p) {
        if (adj[neg].empty()) {
            dp1[n].first += X[neg].first;
            dp1[n].second += X[neg].second;
        }
    }

    for (auto neg : adj[n]) if (neg != p && !adj[neg].empty()) {
        dfs1(neg, n);
        pl re = dp1[neg];
        re.first += (Y[neg]+1) * re.second;
        dp1[n].first += re.first;
        dp1[n].second += re.second;
    }
}

void dfs2(ll n, ll p, pl tp) {
    tp.first += 3 * tp.second;
    dp2[n] = dp1[n];
    dp2[n].first += tp.first;
    dp2[n].second += tp.second;
    
    for (auto neg : adj[n]) if (neg != p && !adj[neg].empty()) {
        pl nx = dp2[n];
        pl re = dp1[neg];
        re.first += (Y[neg]+1) * re.second;
        nx.first -= re.first;
        nx.second -= re.second;
        dfs2(neg, n, nx);
    }
}

void solve(int tc) {
    ll n; cin >> n;
    
    ll st;
    for (int i = 1; i <= n; i++)
    {
        string s; ll m; cin >> s >> m;
        if (s == "bessie") st = i;
        Y[i] = s.size();
        if (!m) X[i].first += s.size(), X[i].second++;
        for (int j = 0; j < m; j++)
        {
            ll v; cin >> v;
            adj[i].push_back(v);
        }
    }

    dfs1(st, 0);
    dfs2(st, 0, {0, 0});

    ll mn = INT64_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (!adj[i].empty()) {
            mn = min(mn, dp2[i].first);
        }
    }

    cout << mn << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}