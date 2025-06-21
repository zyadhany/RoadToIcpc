#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
 
const int MODE = 1e9+7;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

// macros to define set 

// #define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set tree<long long, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>
const int MXN = 2e5+10;
vp adj[MXN];
ll res[MXN];
ll d;

ordered_set dfs(ll n, ll v=0) {
    ordered_set ord;
    ord.insert(v);
    for (auto [neg, w] : adj[n]) {
        auto st = dfs(neg, w + v);
        if (st.size() > ord.size()) ord.swap(st);
        for (auto a : st) ord.insert(a);
    }
    res[n] = ord.order_of_key(v+d+1);
    return ord;
}

void solve(int tc) {
    ll n;

    cin >> n >> d;
    for (int i = 2; i <= n; i++)
    {
        ll v, w; cin >> v >> w;
        adj[v].push_back({i, w});
    }
    dfs(1);
    
    for (int i = 1; i <= n; i++) cout << res[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
