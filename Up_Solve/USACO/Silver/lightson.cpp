#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<int, int>
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

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};
ll n, m;

void req(vector<vector<vp>> &X, vii &vis, vii &Y, ll l, ll r) {
    if (l <= 0 || l > n || r <= 0 || r > m) return;

    for (auto neg : X[l][r]) {
        if (vis[neg.first][neg.second]) continue;
        Y[neg.first][neg.second] = 1;
        ll cnt = 0;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (!i && !j) continue;
                cnt += Y[i + neg.first][j + neg.second];
            }
        }

        if (cnt) {
            vis[neg.first][neg.second] = 1;
            req(X, vis, Y, neg.first, neg.second);        
        }
    }
}

void solve(int tc) {
    cin >> n >> m;

    vector<vector<vp>> X(n + 10, vector<vp>(m + 10));
    for (int i = 0; i < m; i++)
    {
        ll x, y, u, v;
        cin >> x >> y >> u >> v;
        X[x][y].push_back({u, v});
    }
    
    vii vis(n + 10, vi(m + 10));
    vii Y(n + 10, vi(m + 10));
    vis[1][1] = 1;
    Y[1][1] = 1;

    req(X, vis, Y, 1, 1);

    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cnt += Y[i][j];
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("ccski.in", "r", stdin);
    // freopen("ccski.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
