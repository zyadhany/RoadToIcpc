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

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

ll req(vii &adj, vp &Z, set<ll> &vis, vector<set<pl>> &appl, pl col, ll n) {
    queue<ll> q;
    q.push(n);
    vis.insert(n);
    ll res = Z[n].second;
    appl[n].insert(col);

    while (!q.empty())
    {
        ll tp = q.front();
        q.pop();

        for (auto neg : adj[tp]) {
            if (Z[neg].first != col.first && Z[neg].first != col.second) continue;
            if (vis.count(neg)) continue;
            vis.insert(neg);
            q.push(neg);
            res += Z[neg].second;
            appl[neg].insert(col);
        }
    }

    return res;
}

void solve(int tc) {
    ll n;

    cin >> n;
    vii X(n + 10, vi(n + 10, -1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> X[i][j];
        }
    }
    
    ll at = 1;
    vii vis(n + 10, vi(n + 10));
    vp Z(1);
    vii adj(1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j]) continue;
            queue<pl> q;
            vp got;
            q.push({i, j});
            got.push_back({i, j});
            vis[i][j] = at;
            ll cnt = 1;

            while (!q.empty())
            {
                pl tp = q.front();
                q.pop();
                
                for (int dir = 0; dir < 4; dir++)
                {
                    ll x = dx[dir] + tp.first;
                    ll y = dy[dir] + tp.second;

                    if (X[x][y] != X[i][j] || vis[x][y]) continue;
                    vis[x][y] = at;
                    got.push_back({x, y});
                    q.push({x, y});
                    cnt++;
                }
            }
            Z.push_back({X[i][j], cnt});
            adj.push_back(vi());
            set<ll> took;

            for (auto [a, b] : got) {
                for (int dir = 0; dir < 4; dir++)
                {
                    ll x = dx[dir] + a;
                    ll y = dy[dir] + b;
                    if (!vis[x][y] || vis[x][y] == at || took.count(vis[x][y])) continue;
                    took.insert(vis[x][y]);
                    adj[at].push_back(vis[x][y]);
                    adj[vis[x][y]].push_back(at);
                }
                
            }

            at++;
        }
    }
 
    ll solone, soltwo;
    solone = soltwo = -1;
    vector<set<pl>> appl(at);
    for (int i = 1; i < adj.size(); i++)
    {
        pl col;
        col.first = Z[i].first;
        solone = max(solone, Z[i].second);

        for (auto neg : adj[i]) {
            col.second = Z[neg].first;
            if (neg < i || appl[i].count(col)) continue;
            set<ll> vis;
            ll re = req(adj, Z, vis, appl, col, i);
            soltwo = max(soltwo, re);
        }
    }
    
    soltwo = max(solone, soltwo);
    cout << solone << '\n';
    cout << soltwo << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
