#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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


const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;
    vi X(n + 1);
    vii Z(2, vi(1024));

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    Z[0].assign(1024, 0);
    ll l , r;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2) l = 0, r = 1;
        else l = 1, r = 0;

        for (int j = 0; j < 1024; j++)
        {
            ll re = __builtin_popcount(j ^ X[i]);
            Z[l][j] = Z[r][j] + re;
            if (j) Z[l][j] = min(Z[l][j], Z[l][j - 1]);
        }
    }
        
    cout << Z[l].back();
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
