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

ll dist(pl a, pl b) {
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vp X(n + 1);
    vp Y(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> X[i].first >> X[i].second;
    for (int i = 1; i <= m; i++)
        cin >> Y[i].first >> Y[i].second;

    vector<vp> dp(n+1, vp(m + 1, {INT32_MAX, INT32_MAX}));

    dp[1][0].first = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            ll re;

            re = dp[i-1][j].first+dist(X[i-1],X[i]);
            dp[i][j].first = min(dp[i][j].first,re);

            re = dp[i-1][j].second+dist(Y[j],X[i]);
            dp[i][j].first = min(dp[i][j].first,re);
        
            if (!j) continue;
            re = dp[i][j-1].second+dist(Y[j-1],Y[j]);
            dp[i][j].second = min(dp[i][j].second,re);

            re = dp[i][j-1].first+dist(X[i],Y[j]);
            dp[i][j].second = min(dp[i][j].second,re);
        }
    }
    
    cout << dp[n][m].first << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    //  cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
