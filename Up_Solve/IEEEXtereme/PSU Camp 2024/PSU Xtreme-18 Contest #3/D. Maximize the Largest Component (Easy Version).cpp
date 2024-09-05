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


vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void dfs(vcc &X, mi &Y, vii &vis, ll l, ll r, ll cnt) {
    if (vis[l][r] || X[l][r] == '.') return;
    Y[cnt]++;
    vis[l][r] = cnt;

    for (int i = 0; i < 4; i++)
    {
        ll a = dx[i] + l;
        ll b = dy[i] + r;
        dfs(X, Y, vis, a, b, cnt);
    }
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vcc X(n + 10, vc(m + 10, '.'));
    vii vis(n + 10, vi(m + 10));
    mi Y;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> X[i][j];
    
    ll cnt = 1;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i][j] == '#' && !vis[i][j])
                dfs(X, Y, vis, i, j, cnt), cnt++;

    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        ll summ = 0;
        mi Z;
        for (int j = 1; j <= m; j++)
        {
            summ += (X[i][j] == '.');
            for (int h = -1; h <= 1; h++)
            {
                ll comp = vis[i + h][j];
                if (comp && Z.count(comp)) continue;
                Z[comp] = 1;
                summ += Y[comp];
            }
        }
        mx = max(mx, summ);            
    }
    
    
    for (int j = 1; j <= m; j++)
    {
        ll summ = 0;
        mi Z;
        for (int i = 1; i <= n; i++)
        {
            summ += (X[i][j] == '.');
            for (int h = -1; h <= 1; h++)
            {
                ll comp = vis[i][j + h];
                if (comp && Z.count(comp)) continue;
                Z[comp] = 1;
                summ += Y[comp];
            }
        }
        mx = max(mx, summ);            
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
