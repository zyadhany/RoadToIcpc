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

ll req(vii &adj, vi &dp, ll n, ll p, ll k) {
    multiset<ll> st;
    ll &re = dp[n];
    for (auto neg : adj[n]) if (neg != p) {
        ll a = req(adj, dp, neg, n, k);
        if (!a) return 0;
        st.insert(abs(dp[neg])+1);
    }
    ll mx = 0;
    while (!st.empty())
    {
        ll at = *st.begin();
        st.erase(st.begin());
        if (at >= k) {mx = at; continue;}

        auto it = st.lower_bound(k-at);
        if (it == st.end()) {
            if (re) return 0;
            re = at;
            continue;
        }
        if (*it >= k) mx = at;
        st.erase(it);
    }

    if (!re) re=-mx;
    return 1;
}

void solve(int tc) {
    ll n;

    cin >> n;
    
    vii adj(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll l = 1, r = n - 1;
    while (l < r)
    {
        ll mid = (l + r+1) / 2;
        vi dp(n + 1);
        ll re = req(adj, dp, 1, 0, mid);
        if (re && dp[1] <= 0) l = mid;
        else r = mid - 1;
    }
    
    cout << l << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
