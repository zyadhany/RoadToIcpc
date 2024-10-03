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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}


const int MODE = 998244353;

using namespace std;    

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    vi X(n + 1);
    vp Y(m);
    vi Z(k);

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    for (int i = 0; i < m; i++)
        cin >> Y[i].second >> Y[i].first;
    for (int i = 0; i < k; i++)
        cin >> Z[i];

    sortx(X);
    sortx(Y);
    sort(Z.rbegin(), Z.rend());

    vi dp(n + 2);
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = dp[i - 1];
        if (i <= k) dp[i] += Z[i - 1];
    }
    
    ll mx = 0, summ = 0;
    X.push_back(0);
    for (int i = n; i >= 0; i--)
    {
        ll re = X[i + 1];
        while (re && !Y.empty())
        {
            ll tk = min(re, Y.back().second);
            summ += tk * Y.back().first;
            re -= tk;
            Y.back().second -= tk;
            if (!Y.back().second) Y.pop_back();
        }
        
        mx = max(mx, summ + dp[i]);
    }
    
    cout << mx << '\n';             
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
