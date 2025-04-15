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

ll mxn[310][310][310] = {0};

void solve(ll tc) {
    ll n, m;

    cin >> n >> m;

    while (m--)
    {
        ll w, l, r; cin >> w >> l >> r;
        for (int i = l; i <= r; i++)
            mxn[i][l][r] = max(mxn[i][l][r], w);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int l = n; l > 0; l--)
        {
            for (int r = l + 1; r <= n; r++)
            {
                mxn[i][l][r] = max(mxn[i][l][r], mxn[i][l][r-1]);
                mxn[i][l-1][r] = max(mxn[i][l-1][r], mxn[i][l][r]);
            }
        }
    }
    
    vii dp(n+10, vi(n + 10));
    for (int l = n; l >= 1; l--)
    {
        dp[l][l] = mxn[l][l][l];
        for (int r = l + 1; r <= n; r++)
        {
            for (int i = l; i <= r; i++)
            {
                dp[l][r] = max(dp[l][r], dp[l][i-1]+dp[i+1][r]+mxn[i][l][r]); 
            }
        }
    }

    cout << dp[1][n] << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    freopen("pieaters.in", "r", stdin   );
    freopen("pieaters.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
