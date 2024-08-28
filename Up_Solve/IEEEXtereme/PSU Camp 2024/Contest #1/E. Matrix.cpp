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

const int MODE = 998244353;

using namespace std;

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii X(n + 1, vi(m + 1, INT32_MAX));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> X[i][j];
        }  
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ll mx = INT32_MAX;
            for (int h = 0; h < 4; h++)
            {
                ll l = dx[h] + i;
                ll r = dy[h] + j;
                if (l && r && l <= n && r <= m) {
                    if (mx == INT32_MAX) mx = 0;
                    mx = max(mx, X[l][r]);
                }
            }
            X[i][j] = min(mx, X[i][j]);
        }  
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << X[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
            solve(i);
}
