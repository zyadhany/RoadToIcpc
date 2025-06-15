#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
 
const int MODE = 1e9 + 7;
const int MXN = 1e3+10;
 
// i-th, j comp, i is k borders, is border at left or right most
ll dp[MXN][MXN][3][2];
 
void solve(int tc) {
    ll n;
    cin >> n;
 
    fill(&dp[0][0][0][2], &dp[MXN-1][MXN-1][2][1] + 1, 0);
 
    dp[1][1][2][1] = 1;    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // new comp
            ll summ = (dp[i][j][0][0] + dp[i][j][1][0] + dp[i][j][2][0]);
            summ += (dp[i][j][0][1] + dp[i][j][1][1] + dp[i][j][2][1]);

            dp[i+1][j+1][2][0] += summ * (j-1);
            dp[i+1][j+1][2][0] %= MODE;
            dp[i+1][j+1][2][1] += summ * 2;
            dp[i+1][j+1][2][1] %= MODE;
 
            // add
            dp[i+1][j][1][0] += dp[i][j][0][0] * (j*2-2);
            dp[i+1][j][1][0] += dp[i][j][1][0] * (j*2-3) + dp[i][j][1][1] * (j*2-2);
            dp[i+1][j][1][0] += dp[i][j][2][0] * (j*2-4);
            if (j > 1) dp[i+1][j][1][0] += dp[i][j][2][1] * (j*2-3);
            dp[i+1][j][1][0] %= MODE;

            dp[i+1][j][1][1] += dp[i][j][0][0] * 2;
            dp[i+1][j][1][1] += dp[i][j][1][0] * 2 + dp[i][j][1][1];
            dp[i+1][j][1][1] += dp[i][j][2][0] * 2;
            if (j > 1) dp[i+1][j][1][1] += dp[i][j][2][1];
            dp[i+1][j][1][1] %= MODE;

            // merge
            if (j>1) {
                dp[i+1][j-1][0][0] += (j-1)*dp[i][j][0][0];
                dp[i+1][j-1][0][0] += (j-2)*dp[i][j][1][0] + (j-1)*dp[i][j][1][1];
                dp[i+1][j-1][0][0] += (j-3)*dp[i][j][2][0] + (j-2)*dp[i][j][2][1];
                dp[i+1][j-1][0][0] %= MODE;
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res += dp[n][1][i][j];
        }
    }
    res %= MODE;    
    cout << res << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("cbarn.in", "r", stdin);
    // freopen("cbarn.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
