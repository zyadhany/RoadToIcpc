#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vi X(n + 1);
    vii Y(n + 1);
    
    for (int i = 1; i <= n; i++)
        cin >> X[i];

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }
    
    if (m % 2 == 0) {
        cout << "0\n";
        return;
    }
    ll mn = INT64_MAX;

    for (int i = 1; i <= n; i++)
    {
        if (Y[i].size() % 2) mn = min(mn, X[i]);
        else
        {
            ll re = INT32_MAX;
            for (auto neg : Y[i])
                if (Y[neg].size() % 2 == 0) re = min(re, X[neg]);
            mn = min(mn, X[i] + re);
        }
    }
    
    cout << mn << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
