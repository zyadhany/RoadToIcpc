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
    ll n, k;

    cin >> n >> k;
    vi X(n + 1);
    vii dp(n + 1, vi(k + 1, INT32_MAX));
    for (int i = 0; i < n; i++)
        cin >> X[i + 1];

    ll mx = 0, summ = 0;
    dp[0] = vi(k + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, X[i]); summ += X[i];
        dp[i][0] = mx * i - summ;

        for (int j = 1; j <= k; j++)
        {
            ll rmx = 0, rsum = 0;

            for (int h = i; h >= 1; h--)
            {
                rmx = max(rmx, X[h]), rsum += X[h];
                dp[i][j] = min(dp[i][j], dp[h-1][j-1] + (i - h + 1) * rmx - rsum);
            }
        }        
    }
    
    cout << *min_element(all(dp[n])) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
