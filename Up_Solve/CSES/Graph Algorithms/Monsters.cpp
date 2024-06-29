#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
 
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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
const int MODE = 1e9 + 7;
 
using namespace std;


vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};
vc dir = {'D', 'U', 'R', 'L'};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vcc X(n + 10, vc(m + 10, '#'));
    vii dist(n + 10, vi(m + 10, INT32_MAX));
    pl st;
    queue<pl> que;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> X[i][j];
            if (X[i][j] == 'A') st = {i, j};
            if (X[i][j] == 'M') {
                dist[i][j] = 0;
                que.push({i, j});
            }
        }
    }
    
    while (!que.empty())
    {
        auto k = que.front();
        que.pop();

        for (int i = 0; i < dx.size(); i++)
        {
            ll l = k.first + dx[i];
            ll r = k.second + dy[i];
            ll re = dist[k.first][k.second] + 1;
            if (X[l][r] == '#' || dist[l][r] <= re) continue;
            dist[l][r] = re;
            que.push({l, r});
        }
    }
    
    vii prev(n + 10, vi(m + 10, -1));
    vii vis(n + 10, vi(m + 10, -1));
    que.push(st);
    vis[st.first][st.second] = 0;

    while (!que.empty())
    {
        pl k = que.front();
        que.pop();

        for (int i = 0; i < dx.size(); i++)
        {
            ll l = k.first + dx[i];
            ll r = k.second + dy[i];
            ll re = vis[k.first][k.second] + 1;
            if (X[l][r] == '#' || vis[l][r] != -1 || dist[l][r] <= re) continue;
            vis[l][r] = re;
            prev[l][r] = i;
            que.push({l, r});
        }
    }
    
    pl en;
    for (int i = 1; i <= n; i++) {
        if (prev[i][1] != -1 || X[i][1] == 'A') en = {i, 1};
        if (prev[i][m] != -1 || X[i][m] == 'A') en = {i, m};
    }
    for (int i = 1; i <= m; i++) {
        if (prev[1][i] != -1 || X[1][i] == 'A') en = {1, i};
        if (prev[n][i] != -1 || X[n][i] == 'A') en = {n, i};
    }
    if (!en.first) NO;
    
    vc res;
    while (prev[en.first][en.second] != -1)
    {
        ll re = prev[en.first][en.second];
        res.push_back(dir[re]);
        en.first -= dx[re];
        en.second -= dy[re];
    }
    reverse(all(res));


    cout << "YES\n";
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << '\n';
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