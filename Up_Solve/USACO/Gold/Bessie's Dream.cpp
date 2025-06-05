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
using namespace std;

const int MODE = 998244353;
const ll INF = 1e8;
const int MXN = 1010;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
ll dp[MXN][MXN][4][2];

ll n, m;
bool isvalid(ll l, ll r) {
    return (l >= 0 && l < n && r >= 0 && r < m);
}

void solve(int tc) {
    cin >> n >> m;

    vii X(n, vi(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            for (int h = 0; h < 4; h++)
                for (int c = 0; c < 2; c++)
                    dp[i][j][h][c] = INF;
    }

    // x, y, dir, col
    queue<vi> q;
    q.push({0, 0, 0, 0});
    dp[0][0][0][0] = 0;
    while (!q.empty())
    {
        int x = q.front()[0], y = q.front()[1];
        int dir = q.front()[2], col = q.front()[3];
        ll w = dp[x][y][dir][col];
        q.pop();
        
        if (X[x][y] == 2) col = 1;
        if (X[x][y] == 4) col = 0;
        
        bool isdone = 0;
        for (int i = 0; i < 4; i++)
        {
            ll nx = dx[i] + x;
            ll ny = dy[i] + y;  
            if (X[x][y] == 4 && i != dir) continue;
            if (!isvalid(nx, ny) || dp[nx][ny][i][col] <= w+1) continue;
            if (X[nx][ny] == 0) continue;
            else if (X[nx][ny] != 3 || col) {
                isdone = 1;
                dp[nx][ny][i][col] = w + 1;
                q.push({nx, ny, i, col});
            }
        }

        if (X[x][y] == 4 && !isdone) {
            for (int i = 0; i < 4; i++)
            {
                ll nx = dx[i] + x;
                ll ny = dy[i] + y;
                if (!isvalid(nx, ny) || dp[nx][ny][i][col] <= w+1) continue;
                if (X[nx][ny] == 0) continue;
                else if (X[nx][ny] != 3 || col) {
                    dp[nx][ny][i][col] = w + 1;
                    q.push({nx, ny, i, col});
                }
            }
        }
    }
    
    ll res = INF;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res = min(res, dp[n-1][m-1][i][j]);
        }
    }
    
    if (res == INF) cout << "-1\n";
    else cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
