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

const int MX = 1e5 + 1;

void solve(int tc) {
    string s, t, c;
    cin >> s >> t >> c;

    ll n = s.size(), m = t.size(), k = n + m;

    vii dp(k + 10, vi(k + 10, INT32_MAX));

    dp[0][0] = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] == INT32_MAX) continue;
            ll h = i - j;
            if (h != m) dp[i + 1][j] = min(dp[i+1][j], dp[i][j] + (c[i] != t[h]));
            if (j != n) dp[i + 1][j + 1] = min(dp[i+1][j+1], dp[i][j] + (c[i] != s[j]));
        }
        
    }
    
    cout << dp[k][n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
