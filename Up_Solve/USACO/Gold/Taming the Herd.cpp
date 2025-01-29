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

using namespace std;

const int MODE = 998244353;


void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n + 1);
    vii dp(n + 1, vi(n + 1, INT32_MAX));
    vii pref(n + 1, vi(210));

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        pref[i][X[i]-i+100]=1;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < pref[i].size(); j++)
            pref[i][j] += pref[i-1][j];    

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            for (int h = i; h >= j; h--)
                dp[i][j] = min(dp[i][j], dp[h-1][j-1] + (i-h+1) -(pref[i][100-h]-pref[h-1][100-h]));    
    for (int i = 1; i <= n; i++) cout << dp[n][i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
