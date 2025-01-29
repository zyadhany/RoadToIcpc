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

using namespace std;

const int MODE = 1e9 + 7;

ll getrat(ll w, ll v) {
    return floor(v * 1000.0 / w);
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vp L, R;
    ll m = 0;
    for (int i = 0; i < n; i++)
    {
         ll a, b; cin >> a >> b;
        if (a < k) L.push_back({a, b}), m += a;
        else R.push_back({a, b});
    }
    
    vi dp(m + 1, -1);
    dp[0] = 0;
    for (auto [w, v] : L) {
        for (int i = m - w; i >= 0; i--)
        {
            if (dp[i] == -1) continue;
            dp[i + w] = max(dp[i+w], dp[i] + v);
        }
    }

    ll sol = 0;
    for (int i = k; i < dp.size(); i++)
        if (dp[i] != -1) sol = max(sol, getrat(i, dp[i]));

    for (int j = 0; j < R.size(); j++) {
        auto [w, v] = R[j];
        sol = max(sol, getrat(w, v));
        for (int i = 1; i < R.size(); i++)
            if (i != j) sol = max(sol, getrat(w + R[i].first, v + R[i].second));
        for (int i = 1; i < dp.size(); i++)
            if (dp[i] != -1) sol = max(sol, getrat(w + i, v + dp[i]));
    }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
