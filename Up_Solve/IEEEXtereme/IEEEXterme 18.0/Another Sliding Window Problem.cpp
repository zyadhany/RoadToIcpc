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

ll req(vii &dp, vi &X, ll l, ll r) {
    if (l == r) return X[l];
    if (l > r) return 0;
    ll &res = dp[l][r];
    if (res != -1) return (res);
    
    if ((r - l + 1) % 2) {
        res = max(X[r], req(dp, X, l, r - 1));
        return res;
    }

    res = X[l] + X[r];
    res = max(res, req(dp, X, l + 1, r - 1));

    return (res);
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;
    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    vp Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i].first;
        Q[i].second = i;
    }
    sortx(Q);
    vi pref(q);
    vii dp(n, vi(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll mx = req(dp, X, i, j);
            pl p = {mx, -1};
            ll at = lower_bound(all(Q), p) - Q.begin();
            if (at < pref.size()) pref[at] += X[j] - X[i];
        }
    }
        
    for (int i = 1; i < q; i++)
        pref[i] += pref[i - 1];
    vi res(q);
    for (int i = 0; i < q; i++)
        res[Q[i].second] = pref[i];
    for (int i = 0; i < q; i++)
        cout << res[i] << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
