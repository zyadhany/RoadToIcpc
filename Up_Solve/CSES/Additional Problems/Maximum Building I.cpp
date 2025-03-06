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

vp MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vp Z(n, {-1, n});

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second].second = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }
    while (!s.empty()) s.pop();
    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second].first = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<string> X(n);    
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    vii Y(n, vi(m));

    for (int i = 0; i < m; i++)
        Y[0][i] = (X[0][i] == '.');
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (X[i][j] == '.') Y[i][j] = 1 + Y[i-1][j];
            else Y[i][j] = 0;
        }
    }
    
    ll sol = 0;

    for (int i = 0; i < n; i++)
    {
        vp Z = MonomaticStack(Y[i]);

        for (int j = 0; j < m; j++)
        {
            ll re = Y[i][j] * (Z[j].second - Z[j].first - 1);
            sol = max(sol, re);
        }
    }
    
    cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("dishes.in", "r", stdin);
    // freopen("dishes.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
