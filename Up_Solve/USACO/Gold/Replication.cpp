#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 1e9+7;
const ll INF = 1e16;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void solve(ll tc) {
    ll n, m;

    cin >> n >> m;
    vector<string> X(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    vii MX(n, vi(n, INF));
    queue<pl> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (X[i][j] == '#') MX[i][j] = 0, q.push({i, j});
        }
    }
    
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx>=0&&nx<n&&ny>=0&&ny<n&& MX[nx][ny] > MX[x][y]+1) {
                MX[nx][ny] = MX[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    vii dis(n, vi(n, INF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (X[i][j] == 'S') {
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty())
    {
        auto [x, y] = q.front();
        ll dub = dis[x][y]/m;
        ll ndub = (dis[x][y]+1)/m;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx<0||nx>=n||ny<0||ny>=n) continue;
            if (dis[nx][ny] <= dis[x][y] + 1 || X[nx][ny] == '#' || MX[nx][ny] <= dub) continue;
            
            if (ndub >= MX[nx][ny]) dis[nx][ny] = dis[x][y];
            else {
                dis[nx][ny] = dis[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    
    vii TK(n, vi(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (X[i][j] != '#' && dis[i][j] != INF) {
                TK[i][j] = - (dis[i][j]/m)-1;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx<0||nx>=n||ny<0||ny>=n) continue;
            if (TK[nx][ny] <= TK[x][y] + 1 || X[nx][ny] == '#') continue;            
            TK[nx][ny] = TK[x][y]+1;
            q.push({nx, ny});
        }
    }
    
    ll cnt = 0;
    for (auto a : TK) for (auto b : a) cnt += (b != 0);
    cout << cnt << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    // freopen("subrev.in", "r", stdin   );
    // freopen("subrev.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
