#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll int
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
using namespace std;

const int MODE = 1e9+7;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

const int MXN = 1010;
int dist[MXN][MXN][40];
int X[MXN][MXN];
int adj[40][40];

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int h = 0; h < k; h++)
                dist[i][j][h] = n * m + 10;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            adj[i][j] = n*m + 10;
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i][j];
            X[i][j]--;
        }
    }
    
    for (int h = 0; h < k; h++)
    {
        queue<pl> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (X[i][j] == h) {
                    q.push({i, j});
                    dist[i][j][h] = 0;
                }
            }
        }

        while (!q.empty())
        {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++)
            {
                ll nx = dx[i] + x;
                ll ny = dy[i] + y;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                ll nw = dist[x][y][h]+1;
                if (dist[nx][ny][h] > nw) {
                    dist[nx][ny][h] = nw;
                    q.push({nx, ny});
                }
            }
        }
    }
        
    ll q; cin >> q;
    while (q--)
    {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        ll sol = abs(c - a) + abs(d - b);
        
        for (int i = 0; i < k; i++)
        {
            ll re = dist[a][b][i] + dist[c][d][i] + 1;
            sol = min(sol, re);
        }        
    
        cout << sol << '\n';
    }
        
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
