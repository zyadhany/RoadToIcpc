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

void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n + 1, vi(2));

    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        X[x][y] = 1;
    }
    
    ll res = 0;
    for (int i = 0; i <= n; i++)
    {
        if (X[i][0] && X[i][1]) res += n - 2;
    
        if (!i || i == n) continue;
        if (X[i][0] && X[i - 1][1] && X[i + 1][1]) res++;
        if (X[i][1] && X[i - 1][0] && X[i + 1][0]) res++;
    }

    cout << res << '\n';
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
