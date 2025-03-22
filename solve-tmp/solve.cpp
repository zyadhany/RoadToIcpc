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
 
const int MODE = 1e9 + 7;

using namespace std;

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

ll req(vii &adj, vi &match, vi &vis, ll n) {
    if (vis[n]) return 0;
    vis[n] = 1;
    
    for (auto v : adj[n]) {
        if (match[v] == -1 || (!vis[match[v]] && req(adj, match, vis, match[v]))) {
            match[n] = v;
            match[v] = n;
            return 1;
        }
    }
    return 0;
}

ll maxMatching(vii &adj, ll sz) {
    vi match(sz, -1);
    ll result = 0;
    
    for (ll i = 0; i < sz; i++) {
        vi vis(sz, 0);
        if (match[i] == -1) result += req(adj, match, vis, i);
    }
    
    return result;
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    ll sz = n* m;
    vi X(sz);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a; cin >> a;
            if (a == 'G') X[i*m+j] = 1;
            else if (a == 'W') X[i*m+j] = 2;
            else X[i*m+j] = 0;
        }
    }

    vii adj(sz);
    vi deg(sz);
    vi tk(sz);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (X[i*m+j] != 2) continue;
            for (int d = 0; d < 4; d++)
            {
                ll l = i + dx[d];
                ll r = j + dy[d];
                if (l < 0 || r < 0 || l >= n || r >= m) continue;
                if (X[l*m+r] == 1) {
                    deg[i*m+j]++;
                    deg[l*m+r]++;
                    adj[i*m+j].push_back(l*m+r);
                    adj[l*m+r].push_back(i*m+j);
                }
            }
        }
    }
    
    cout << maxMatching(adj, sz) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}