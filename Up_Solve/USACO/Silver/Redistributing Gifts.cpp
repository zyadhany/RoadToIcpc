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

void req(vii &adj, vi &vis, ll n) {
    if (vis[n]) return;
    vis[n] = 1;
    for (auto neg : adj[n]) req(adj, vis, neg);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n + 1, vi(n + 1));
    vii Y(n + 1, vi(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> X[i][j];
            Y[i][X[i][j]] = j;
        }
    }

    vii adj(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (Y[j][i] < Y[j][j]) adj[i].push_back(j);

    vi pos(n + 1, n);
    for (int i = 1; i <= n; i++)
    {
        vi vis(n + 1);
        req(adj, vis, i);
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j]) continue;
            pos[i] = min(pos[i], Y[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << X[i][pos[i]] << '\n';
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
