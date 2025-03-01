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
    ll n, q;

    cin >> n >> q;

    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    vii dp(n, vi(n));

    for (int i = n - 1; i >= 0; i--)
    {
        unordered_map<int, int> Y;
        Y.reserve(n-i);
        ll add = 0;
        for (int j = i+1; j < n; j++)
        {
            if (Y.count(-(X[i]+X[j]))) add += Y[-(X[i]+X[j])];
            dp[i][j] = dp[i+1][j]+add;
            Y[X[j]]++;
        }        
    }

    while (q--)
    {
        ll l, r; cin >> l >> r;
        cout << dp[l-1][r-1] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
