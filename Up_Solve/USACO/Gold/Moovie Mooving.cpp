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
    ll n, k;
    
    cin >> n >> k;

    vi X(n);
    vii Y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        ll m; cin >> m;
        Y[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> Y[i][j];
    }
    
    int sol = INT32_MAX;
    vi dp(1 << n);
    for (int i = 1; i < 1<<n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i&(1<<j))) continue;
            ll b = (i ^ (1<<j));
            ll ind = upper_bound(all(Y[j]), dp[b]) - Y[j].begin() - 1;
            if (ind != -1) dp[i] = max(dp[i], Y[j][ind] + X[j]);
        }
        
        if (dp[i] >= k) sol = min(sol, __builtin_popcount(i));
    }

    if (sol == INT32_MAX) cout << "-1\n";
    else cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
