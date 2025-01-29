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

void floydWarshall(vii &dist)
{
    for (int k = 0; k < dist.size(); k++)
        for (int i = 0; i < dist.size(); i++)
            for (int j = 0; j < dist.size(); j++) 
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

void solve(int tc) {
    ll n, m, k;
    string s;

    cin >> n >> m >> k;
    cin >> s;

    vii dis(m, vi(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> dis[i][j];
    floydWarshall(dis);

    vii pref(n + 1, vi(m));

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            pref[i][j] = pref[i-1][j] + dis[s[i-1]-'a'][j];

    vii dp(n + 1, vi(m, INT32_MAX));
    for (int i = 0; i < m; i++) dp[k][i] = pref[k][i];
    for (int i = k + 1; i <= n; i++)
    {
        ll mnpre = *min_element(all(dp[i-1]));
        for (int j = 0; j < m; j++)
        {
            if (i + k - 1 <= n) dp[i+k-1][j] = mnpre + pref[i+k-1][j] - pref[i-1][j];
            dp[i][j] = min(dp[i][j], dp[i-1][j] + dis[s[i-1]-'a'][j]);
        }        
    }

    cout << *min_element(all(dp[n])) << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
