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

const int MODE = 1e9;

using namespace std;

ll iscyc;

ll req(vi &X, vi &vis, ll n, ll h) {
    ll &res = vis[n];
    if (res < 0) {
        res += h;
        iscyc = n;
    }
    if (res) return res;
    res = -h;

    res = req(X, vis, X[n], h + 1) + (iscyc == 0);
    if (iscyc == n) iscyc = 0;
    
    return res;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n + 1);
    vi res(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    
    for (int i = 1; i <= n; i++)
    {
        if (res[i]) continue;
        iscyc = 0;
        req(X, res, i, 1);
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("mootube.in", "r", stdin);
    // freopen("mootube.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
