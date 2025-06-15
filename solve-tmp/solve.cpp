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
 
const int MODE = 1e9+7;

void solve(int tc) {
    ll n, st, en;
    cin >> n >> st >> en;

    vii dp(n+1, vi(n+1));
    dp[1][1] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == st-1 || i == en-1) {
                dp[i+1][j+1] = (dp[i+1][j+1]+ dp[i][j]) % MODE;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MODE;
            } else {
                dp[i+1][j+1] = (dp[i+1][j+1] + (j+1 - (i >= st) - (i >= en)) * dp[i][j]) % MODE;
                dp[i+1][j-1] = (dp[i+1][j-1] + (j-1) * dp[i][j]) % MODE;
            }
        }
    }
    
    cout << dp[n][1] << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("kangaroo.in", "r", stdin);
    // freopen("kangaroo.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}