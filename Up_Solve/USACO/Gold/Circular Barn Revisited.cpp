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

ll req(deque<ll> &X, ll k) {
    ll n = X.size();

    vii dp(n + 1, vi(k, INT32_MAX));

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0] + (i-1) * X[i-1];
        for (int h = 1; h < k; h++)
        {
            ll re, sum; re = sum = 0;
            for (int j = i; j >= 1; j--)
            {
                sum += X[j - 1];
                dp[i][h] = min(dp[i][h], re + dp[j-1][h-1]);
                re += sum;
            }
        }
    }
    return *min_element(all(dp[n]));
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    deque<ll> X(n);
    for (int i = 0; i < n; i++) cin >> X[i];

    ll res = INT64_MAX;

    for (int i = 0; i < n; i++)
    {
        res = min(res, req(X, k));
        X.push_back(X[0]); X.pop_front();
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
