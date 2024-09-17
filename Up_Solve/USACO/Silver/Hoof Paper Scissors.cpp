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

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n;
    cin >> n;

    vii X(n + 1, vi(3));

    mc Y; 
    Y['P'] = 0;
    Y['H'] = 1;
    Y['S'] = 2;

    for (int i = 1; i <= n; i++)
    {
        char c; cin >> c;
        ll re = Y[c];

        X[i][re] = 1;
        for (int j = 0; j < 3; j++)
            X[i][j] += X[i - 1][j];
    }
    
    ll mx = 0;

    for (int i = 0; i < n; i++)
    {
        ll l = 0, r = 0;

        for (int j = 0; j < 3; j++)
        {
            l = max(l, X[i][j]);
            r = max(r, X[n][j] - X[i][j]);
        }
        
        mx = max(mx, l + r);
    }
    

    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
