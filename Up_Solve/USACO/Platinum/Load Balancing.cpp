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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

// this function erases one occurrence of the value (x).
void Erase(ordered_set &s,int x) { 
    s.erase(s.upper_bound(x));
}

pl calco(ordered_set &ord, ll k) {
    ll l, r;

    if (ord.size() <= k) return {0, INT32_MAX};
    r = *ord.find_by_order(k) - 1;
    l = *ord.find_by_order(ord.size() - k - 1) + 1;
    return {l, r};
}

ll req(ordered_set &L, ordered_set &R) {
    ll l = 1, r = max(L.size(), R.size());
    while (l < r)
    {
        ll mid = (l + r) / 2;

        pl a = calco(L, mid);
        pl b = calco(R, mid);

        ll st = max(a.first, b.first);
        ll en = min(a.second, b.second);

        if (st <= en) r = mid;
        else l = mid + 1;
    }
    
    return l;
}

void solve(int tc) {
    ll n;

    cin >> n;

    map<ll, vi> X;
    ordered_set L, R;
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        X[x].push_back(y);
        R.insert(y);
    }

    ll sol = n;
    for (auto x : X) {
        for (auto y : x.second) {
            Erase(R, y);
            L.insert(y);
        }
        ll re = req(L, R);
        sol = min(sol, re);
    }  

    cout << sol << '\n'; 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
