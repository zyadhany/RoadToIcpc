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

const int MODE = 1e9 + 7;

ll req(vi &X) {
    ll n = X.size();
    ll m = *max_element(all(X));

    vii dp(n, vi(m + 1, 0));
    dp[0] = vi(m + 1, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= min(X[i], X[i-1]); j++)
            dp[i][j] = dp[i-1][X[i-1]-j];
        for (int j = 1; j <= X[i]; j++) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MODE;
    }
    
    return dp[n-1][X[n-1]];
}

void solve(int tc) {
    ll n;

    cin >> n;
    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    ll sol = 0;

    while (*min_element(all(X)) >= 0)
    {
        sol = (sol + req(X)) % MODE;
        if (n % 2 == 0) break;
        for (auto &x : X) x -= 1;
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("taming.in", "r", stdin);
    // freopen("taming.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
