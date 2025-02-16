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


const int MODE = 998244353;
using namespace std;

ll dis(pl a, pl b) {
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n+1);
    vi Y(n+1);

    for (int i = 1; i <= n; i++) cin >> X[i];
    for (int i = 1; i <= n; i++) cin >> Y[i];
    
    vii dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = max({dp[i-1][j-1] + (abs(X[i]-Y[j])<=4),
                            dp[i][j-1], dp[i-1][j]});
    cout << dp[n][n] << '\n';    
}   

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
