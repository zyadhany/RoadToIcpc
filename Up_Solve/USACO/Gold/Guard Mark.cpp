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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, h;

    cin >> n >> h;

    vii X(n, vi(3));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> X[i][j];

    ll sol = -1;
    vi dp((1<<n), -1);
    for (int i = 1; i < (1<<n); i++)
    {
        if (__builtin_popcount(i) == 1) {
            dp[i] = X[__builtin_ctz(i)][2];
            continue;
        }
        
        for (int j = 0; j < n; j++)
        {
            if (!(i&(1<<j))) continue;
            ll b = i - (1<<j);
            if (dp[b] >= X[j][1])
                dp[i] = max(dp[i], min(X[j][2], dp[b]-X[j][1]));
        }
        
        if (dp[i]<0) continue;
        ll summ = 0;
        for (int j = 0; j < n; j++)
            if (i & (1<<j)) summ += X[j][0];
        if (summ >= h) sol = max(sol, dp[i]);        
    }

    if (sol == -1) cout << "Mark is too tall\n";
    else cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
