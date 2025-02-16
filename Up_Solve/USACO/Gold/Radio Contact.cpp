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

int sq(int a) { return a * a; }

int dis(pl a, pl b) {  // distance squared between two points
	return sq(a.first- b.first) + sq(a.second - b.second);
}


void solve(int tc) {
    ll n, m;

    cin >> n >> m;
    vii dp(n + 1, vi(m + 1, INT32_MAX));

    vp A(n + 1), B(m + 1);
    cin >> A[0].first >> A[0].second;
    cin >> B[0].first >> B[0].second;

    string s, t; cin >> s >> t;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='N') A[i+1]={A[i].first, A[i].second+1};
        if (s[i]=='S') A[i+1]={A[i].first, A[i].second-1};
        if (s[i]=='E') A[i+1]={A[i].first+1, A[i].second};
        if (s[i]=='W') A[i+1]={A[i].first-1, A[i].second};
    }
    for (int i = 0; i < m; i++)
    {
        if (t[i]=='N') B[i+1]={B[i].first, B[i].second+1};
        if (t[i]=='S') B[i+1]={B[i].first, B[i].second-1};
        if (t[i]=='E') B[i+1]={B[i].first+1, B[i].second};
        if (t[i]=='W') B[i+1]={B[i].first-1, B[i].second};
    }
    
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dis(A[i + 1], B[j]));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dis(A[i], B[j + 1]));
			dp[i + 1][j + 1] =
			    min(dp[i + 1][j + 1], dp[i][j] + dis(A[i + 1], B[j + 1]));
		}
	}
    
    cout << dp[n][m] << '\n';
}   

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
