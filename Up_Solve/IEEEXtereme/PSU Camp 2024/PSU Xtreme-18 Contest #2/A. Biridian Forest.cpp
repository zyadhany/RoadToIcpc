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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vcc X(n + 10, vc(m + 10, 'T'));
    vii vis(n + 10, vi(m + 10, INT_MAX));

    queue<pl> que;

    pl st;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> X[i][j];

            if (X[i][j] == 'E') que.push({i, j}), vis[i][j] = 0;
            else if (X[i][j] == 'S') st = {i, j};
        }
    }
    

    ll sol = 0;

    while (!que.empty())
    {
        pl at = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            ll l = dx[i] + at.first;
            ll r = dy[i] + at.second;
            
            if (X[l][r] == 'T' || vis[l][r] != INT_MAX) continue;
            vis[l][r] = vis[at.first][at.second] + 1;
            que.push({l, r});
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i][j] >= '1' && X[i][j] <= '9' && vis[i][j] <= vis[st.first][st.second])
                sol += X[i][j] - '0'; 
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
