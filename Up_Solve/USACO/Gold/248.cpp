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

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    vii dp(n, vi(n, -1));    
    ll mx = *max_element(all(X));
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i] = X[i];
        for (int j = i+1; j < n; j++)
        {
            for (int h = i + 1; h <= j; h++)
            {
                if (dp[i][h-1] != -1 && dp[i][h-1]==dp[h][j]) {
                    dp[i][j] = dp[i][h-1] + 1;
                }
            }
            
            mx = max(mx, dp[i][j]);
        }
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
