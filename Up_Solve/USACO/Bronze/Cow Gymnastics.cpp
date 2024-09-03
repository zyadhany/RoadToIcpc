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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll k, n;

    cin >> k >> n;

    vii X(k, vi(n));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            bool isit = 1;

            for (int a = 0; a < k && isit; a++)
            {
                ll l, r;
                for (int b = 0; b < n; b++)
                {
                    if (X[a][b] == i) l = b;
                    if (X[a][b] == j) r = b;
                }
                if (r < l) isit = 0;
            }
            
            res += isit;
        }
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
