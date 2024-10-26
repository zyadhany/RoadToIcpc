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

void dfs(vii &adj, vi &vis, ll n) {
    if (vis[n]) return;
    vis[n] = 1;
    for (auto neg : adj[n]) dfs(adj, vis, neg);
}

void solve(int tc) {
    ll n;
    
    cin >> n;

    vp X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;
    
    ll l = 0, r = 1e10;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        bool isit = 1;
        vi vis(n + 1);
        vii adj(n + 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ll x = X[i].first - X[j].first;
                ll y = X[i].second - X[j].second;
                if (x * x + y * y <= mid) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }
        
        dfs(adj, vis, 1);
        for (int i = 1; i <= n; i++)
            isit &= vis[i];
        if (isit) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
