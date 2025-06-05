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
const int MXN = 22;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
ll dp[MXN][MXN][MXN][MXN][4][2][2];

void solve(int tc) {
    ll n;
    cin >> n;

    vcc X(n+10, vc(n+10, 'H'));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> X[i][j];

    fill(&dp[0][0][0][0][0][0][0], &dp[MXN-1][MXN-1][MXN-1][MXN-1][3][1][1], INF);

    dp[n][1][n][1][2][0][0] = 0;
    queue<vi> q;
    q.push({n,1,n,1,2,0,0});
    while (!q.empty())
    {
        ll x = q.front()[0], y = q.front()[1];
        ll x2 = q.front()[2], y2 = q.front()[3];
        ll d = q.front()[4];
        ll b = q.front()[5], b2 = q.front()[6];
        ll w = dp[x][y][x2][y2][d][b][b2];
        q.pop();

        ll nx, ny, nx2, ny2, nd, nb, nb2;

        nx=x+dx[d], ny=y+dy[d], nx2=x2+dx[(d+3)%4], ny2=y2+dy[(d+3)%4], nd=d;
        if (X[nx][ny]=='H')nx=x,ny=y;
        if (X[nx2][ny2]=='H')nx2=x2,ny2=y2;
        nb=(b|(nx==1&&ny==n)), nb2 = (b2|(nx2==1&&ny2==n));
        if (dp[nx][ny][nx2][ny2][nd][nb][nb2] > w+1) {
            dp[nx][ny][nx2][ny2][nd][nb][nb2] = w+1;
            q.push({nx,ny,nx2,ny2,nd,nb,nb2});
        }
        
        nx=x, ny=y, nx2=x2, ny2=y2, nd=d, nb=b, nb2=b2;
        nd = (nd+1)%4;
        if (dp[nx][ny][nx2][ny2][nd][nb][nb2] > w+1) {
            dp[nx][ny][nx2][ny2][nd][nb][nb2] = w+1;
            q.push({nx,ny,nx2,ny2,nd,nb,nb2});
        }
        nd = (nd+2)%4;
        if (dp[nx][ny][nx2][ny2][nd][nb][nb2] > w+1) {
            dp[nx][ny][nx2][ny2][nd][nb][nb2] = w+1;
            q.push({nx,ny,nx2,ny2,nd,nb,nb2});
        }
    }
    
    ll res = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int i2 = 1; i2 <= n; i2++)
                for (int j2 = 1; j2 <= n; j2++)
                    for (int d = 1; d < 4; d++)
                        res = min(res, dp[i][j][i2][j2][d][1][1]);    
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
