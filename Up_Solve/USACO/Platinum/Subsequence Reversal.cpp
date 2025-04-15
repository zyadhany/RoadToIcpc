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

const int MXN = 52;
ll dp[MXN][MXN][MXN][MXN] = {0};

void solve(ll tc) {
    ll n;

    cin >> n;

    vi X(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
    }
    
    for (int l = n; l >= 1; l--)
    {
        for (int r = l; r <= n; r++)
        {
            for (int a = 50; a >= 0; a--)
            {
                for (int b = a; b <= 50; b++)
                {
                    if (l == r) {
                        dp[l][r][a][b] = (a <= X[l] && X[l] <= b);
                        continue;
                    }

                    ll &mx = dp[l][r][a][b];
                    mx = max({dp[l][r][a][b-1], dp[l][r][a+1][b], dp[l+1][r][a][b], dp[l][r-1][a][b]});

                    if (X[l] >= a && X[l] <= b) mx = max({mx, 1 + dp[l+1][r][X[l]][b]});
                    if (X[r] <= b && X[r] >= a) mx = max({mx, 1 + dp[l][r-1][a][X[r]]});
                    if (X[l] >= a && X[l] <= b && X[r] <= b && X[r] >= a && X[l] <= X[r]) mx = max({mx, 2 + dp[l+1][r-1][X[l]][X[r]]});
                    swap(X[l], X[r]);

                    if (X[l] >= a && X[l] <= b) mx = max({mx, 1 + dp[l+1][r-1][X[l]][b]});
                    if (X[r] <= b && X[r] >= a) mx = max({mx, 1 + dp[l+1][r-1][a][X[r]]});
                    if (X[l] >= a && X[l] <= b && X[r] <= b && X[r] >= a && X[l] <= X[r]) mx = max({mx, 2 + dp[l+1][r-1][X[l]][X[r]]});

                    swap(X[l], X[r]);
                }
            }
        }
    }
    
    cout << dp[1][n][1][50] << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    // freopen("subrev.in", "r", stdin   );
    // freopen("subrev.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
