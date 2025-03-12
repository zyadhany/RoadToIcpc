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

set<ll> req(vii &adj, vi &X, vi &Z, ll n, ll p) {
    set<ll> st({X[n]});

    for (auto neg : adj[n]) if(neg != p) {
        auto tm = req(adj, X, Z, neg, n);
        if (tm.size() > st.size()) swap(tm, st);
        st.insert(all(tm));
    }

    Z[n] = st.size();
    return st;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n + 1);
    vii adj(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i + 1];
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi Z(n+1);
    req(adj, X, Z, 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << Z[i] << ' ';
    }
    
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("hopscotch.in", "r", stdin);
    // freopen("hopscotch.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
