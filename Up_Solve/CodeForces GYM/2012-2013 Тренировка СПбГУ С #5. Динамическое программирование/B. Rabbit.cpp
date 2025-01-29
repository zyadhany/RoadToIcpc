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
    string s;

    cin >> n >> s;

    vi dp(n + 1, -1);
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (s[i-1]=='w') continue;
        for (int step = 1; step <= 5; step+=2)
        {
            if (step > i) break; // to not get negative index.
            if (dp[i-step] != -1) dp[i] = max(dp[i], (s[i-1] == '\"') + dp[i-step]);
        }
    }
    
    cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
