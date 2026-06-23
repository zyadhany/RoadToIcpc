// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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

const int SIZE = 1e6 + 1;
const int MODE = 998244353;
const ll INF = 2e16;
using namespace std;



void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vi X(n), P(1);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        ll v = X[i];
        while (v--) P.push_back(i);
        if (i) X[i] += X[i-1];
    }
    for (int i = 1; i <= m; i++) P[i] += P[i-1];
    
    
    vii dp(m+1, vi(m+1, INF));
    for (int i = 0; i <= m; i++)
    {
        if (i < X[0]) dp[i][i] = X[0]-i;
        else dp[i][i] = P[i];
    }

    for (ll j = m-1; j >= 0; j--)
        for (ll k = m; k >= 0; k--)
            dp[j][k] = min(dp[j][k], dp[j+1][k]);   
    // cout << dp[4][4] << ' ' << dp[3][4] << "|\n";
    for (int i = 1; i < n; i++)
    {
        vii TM(m+1, vi(m+1, INF));
        for (ll j = 0; j <= m; j++)
        {
            for (ll k = j; k <= m; k++)
            {
                ll ad = 0;
                if (X[i] >= k) ad = X[i]-k;
                else {
                    ll tk = min(j, k-X[i]);
                    // if (tk > j) break;
                    ad = P[k] - P[k-tk] - i * tk;
                }
                TM[j][k] = ad + dp[j][k-j];
                // cout << j << ' ' << k << ' ' << TM[j][k] << "|\n";
            }            
        }
        // cout << "||||||||||||\n";
        for (ll j = m-1; j >= 0; j--)
            for (ll k = m-1; k >= 0; k--)
                TM[j][k] = min(TM[j][k], TM[j+1][k]);        
        swap(dp, TM);
        cout << dp[1][9] << "|\n";
    }
    

    ll sol = INF;
    for (int i = 0; i <= m; i++) sol = min(sol, dp[i][m]);
    cout << sol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    for (int i = 1; i <= size; i++) solve(i);
}