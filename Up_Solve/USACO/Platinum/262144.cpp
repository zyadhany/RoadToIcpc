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
    ll n;

    cin >> n;

    vii dp(n, vi(100, -1));
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        dp[i][a] = i;
    }

    for (int j = 1; j < 100; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (dp[i][j-1] == -1 || dp[i][j-1] == n-1) continue;
            dp[i][j] = dp[dp[i][j-1]+1][j-1];            
        }
    }
    
    ll res = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (dp[i][j] != -1) res = max(res, (ll)j);
        }
    }
    
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
