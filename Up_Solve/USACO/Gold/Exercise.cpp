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


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vi P;
    for (int i = 2; i <= n; i++)
    {
        bool isit = 1;
        for (auto a : P) {
            if (i % a == 0) {isit = 0; break;}
        }
        if (isit) P.push_back(i);
    }
    
    vi dp(n + 1);
    dp[0] = 1;

    for (auto a : P)
        for (int i = n - a; i >= 0; i--) {
            ll at = a;
            while (at + i <= n) {
                dp[i + at] = (dp[i + at] + dp[i] * at) % m;
                at *= a;
            }
        }
    
    ll sol = 0;
    for (auto x : dp) sol = (sol + x) % m;
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
