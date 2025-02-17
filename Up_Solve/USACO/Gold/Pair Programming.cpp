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

bool cons(char a, char b) {
    if (a >= '0' && b >= '0') return 1;
    if (a == '1' || b == '1') return 1;
    if (a == '+' && b == '+') return 1;
    return 0;
}

void solve(int tc) {
    ll n;
    string s, t;

    cin >> n;
    cin >> s >> t;


    vii dp(n + 1, vi(n + 1));
    vii zer(n + 1, vi(n + 1));
    zer[0][0] = 1;    
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == '+') zer[i][0] = 0;
        else if (s[i-1] == '0') zer[i][0] = 1;
        else zer[i][0] = zer[i-1][0];
        
        if (t[i-1] == '+') zer[0][i] = 0;
        else if (t[i-1] == '0') zer[0][i] = 1;
        else zer[0][i] = zer[0][i-1];
    
        dp[i][0] = (1 ^ zer[i][0]);
        dp[0][i] = (1 ^ zer[0][i]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i-1] == '0') zer[i][j] = 1;
            else if (s[i-1] == '+') dp[i][j] = dp[i-1][j] + zer[i-1][j];
            else dp[i][j] = dp[i-1][j], zer[i][j] = zer[i-1][j];

            if (t[j-1] == '0') zer[i][j] = 1;
            else if (t[j-1] == '+') dp[i][j] += dp[i][j-1] + zer[i][j-1];
            else dp[i][j] += dp[i][j-1], zer[i][j] |= zer[i][j-1];

            dp[i][j] %= MODE;
            
            if (s[i-1] == '0' || t[j-1] == '0') continue;
            if (s[i-1] == '+' && t[j-1] == '+' || s[i-1] == '1' && t[j-1] == '+' ||
                s[i-1] == '+' && t[j-1] == '1') dp[i][j] -= (zer[i-1][j-1]);
            if (cons(s[i-1], t[j-1]))
                dp[i][j] = ((dp[i][j]-dp[i-1][j-1])%MODE + MODE) % MODE;
        }
    }
        
    cout << (dp[n][n] + zer[n][n]) % MODE << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("exercise.in", "r", stdin);
    // freopen("exercise.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
