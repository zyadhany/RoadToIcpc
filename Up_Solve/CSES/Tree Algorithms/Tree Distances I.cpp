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
 
ll req(vii &adj, vp &X, ll n, ll p) {
    pl &res = X[n];
    res = {0, 0};
    
    for (auto neg : adj[n]) {
        if (neg == p) continue;
 
        ll re = req(adj, X, neg, n) + 1;
 
        if (re > res.first) swap(res.first, res.second), res.first = re;
        else if (re > res.second) res.second = re;
    }
 
    return res.first;
}
 
void solve(int tc) {
    ll n;
 
    cin >> n;
 
    vii adj(n + 1);
 
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vp X(n + 1, {INT32_MIN, INT32_MIN});
    req(adj, X, 1, 0);
    stack<pl> st;
    st.push({1, 0});
    while (!st.empty())
    {
        auto [tp, p] = st.top();
        st.pop();
 
        if (X[p].first == X[tp].first + 1) {
            if (X[p].second + 1 > X[tp].first) swap(X[tp].first, X[tp].second), X[tp].first = X[p].second + 1;
            else if (X[p].second + 1 > X[tp].second) X[tp].second = X[p].second + 1;
        }
        else {
            if (X[p].first + 1 > X[tp].first) swap(X[tp].first, X[tp].second), X[tp].first = X[p].first + 1;
            else if (X[p].first + 1 > X[tp].second) X[tp].second = X[p].first + 1;
        }
 
        for (auto neg : adj[tp]) {
            if (neg == p) continue;
            st.push({neg, tp});   
        }
    }
 
    for (int i = 0; i < n; i++)
        cout << X[i + 1].first << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("milkvisits.in", "r", stdin);
    // freopen("milkvisits.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}