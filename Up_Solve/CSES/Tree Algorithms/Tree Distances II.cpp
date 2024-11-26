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

pl req(vii &adj, vp &X, ll n, ll p) {
    pl &res = X[n];
    res = {0, 1};

    for (auto neg : adj[n]) {
        if (neg == p) continue;
        pl re = req(adj, X, neg, n);
        res.first += re.first + re.second;
        res.second += re.second;
    }

    return res;
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
    
    vp X(n + 1);

    req(adj, X, 1, 0);

    vi res(n + 1);
    res[1] = X[1].first;
    stack<pl> st;
    st.push({1, 0});
    while (!st.empty())
    {
        auto [tp, p] = st.top();
        st.pop();

        if (p) {
            ll num = n - X[tp].second;
            ll re = res[p] - (X[tp].first + X[tp].second);
            res[tp] = X[tp].first + num + re;
        }

        for (auto neg : adj[tp]) {
            if (neg != p) st.push({neg, tp});
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';    
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