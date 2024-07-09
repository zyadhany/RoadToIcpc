#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
vc DIR = {'R', 'L', 'D', 'U'};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vcc X(20, vc(20, '.'));
    X[3][3] = X[3][10] = X[10][3] = X[10][10] = '$';
    X[6][6] = X[7][6] = X[6][7] = X[7][7] = '#';
    X[9][2] = X[9][3] = X[10][2] = '#';    
    X[9][10] = X[9][11] = X[10][11] = '#';
    for (int i = 0; i <= 13; i++)
        X[i][0] = X[0][i] = X[13][i] = X[i][13] = '#';

    queue<pl> que;
    vii vis(20, vi(20));
    vii prev(20, vi(20, -1));
    vc res;
    que.push({n, m});
    vis[n][m] = 1;
    pl en;

    while (!que.empty())
    {
        pl k = que.front();
        que.pop();

        if (X[k.first][k.second] == '$') {
            en = k;
            break;
        }

        for (int i = 0; i < dx.size(); i++)
        {
            ll l = dx[i] + k.first;    
            ll r = dy[i] + k.second;    
            if (vis[l][r] || X[l][r] == '#') continue;
            vis[l][r] = 1;
            prev[l][r] = i;
            que.push({l, r});
        }
    }

    while (prev[en.first][en.second] != -1)
    {
        ll opp = prev[en.first][en.second];
        res.push_back(DIR[opp]);
        en.first -= dx[opp];
        en.second -= dy[opp];
    }
    
    reverse(all(res));
    cout << res.size() << '\n';
    for (auto a : res) cout << a;
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
