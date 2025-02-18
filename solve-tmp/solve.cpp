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

ll req(vii &dp, vii &adj, ll l, ll r) {
    if (r < l) return 0;
    if (l == r) return 1;
    ll &res = dp[l][r];
    if (res != -1) return res;
    res = r - l + 1;

    for (int i = 0; i < 26; i++)
    {
        ll a = lower_bound(all(adj[i]), l) - adj[i].begin();
        ll b = upper_bound(all(adj[i]), l) - adj[i].begin();
        for (int j = a; j < b; j++)
        {
            for (int h = a; h <= j; h++)
            {
                ll ans = req(dp, adj, l, adj[i][h]-1);
                ans += req(dp, adj, adj[i][j]+1, r);
                ans += req(dp, adj, adj[i][h]+1, adj[i][j]-1);
                res = min(res, ans);
            }
        }
        
    }
    
    return res;
}

void solve(int tc) {
    ll n;
    string s;

    cin >> s;

    n = s.size();
    vii adj(26);
    vii dp(n, vi(n, -1));

    for (int i = 0; i < n; i++)
        adj[s[i]-'a'].push_back(i);    

    cout << req(dp, adj, 0, n-1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("movie.in", "r", stdin);
    // freopen("movie.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
