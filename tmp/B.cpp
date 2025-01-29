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

const int MODE = 998244353;

ll summtion(vi &X) {
    ll re = 0;
    for (auto a : X) re += a;
    return re;
}

mi req(vii &adj, vi &X, vi &Z, set<ll> &st, ll n, ll p) {
    mi Y; Y[X[n]]++;

    for (auto neg : adj[n]) {
        if (p == neg) continue;
        mi T = req(adj, X, Z, st, neg, n);
        if (T.size() > Y.size()) swap(T, Y);
        for (auto [a, b] : T) Y[a] += b;
    }

    auto it = st.find(X[n]);
    if (next(it) != st.end()) {
        ll a = *next(it);
        if (Y.count(a)) {
            Z[n] = Y[a];
        }
    }

    return Y;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n + 1);
    set<ll> st;

    for (int i = 0; i < n; i++)
    {
        cin >> X[i + 1];
        st.insert(X[i + 1]);
    }
    
    vii adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi Z(n + 1);
    req(adj, X, Z, st, 1, 0);

    vp Y;
    for (int i = 1; i <= n; i++)
    {
        Y.push_back({X[i], i});
    }
    sort(Y.rbegin(), Y.rend());
    
    mi freq;
    for (int i = 1; i <= n; i++)
        freq[X[i]]++;
    
    vi sol;

    for (int i = 1; i < n; i++)
    {
        if (Y[i].first == Y[0].first) continue;
        auto it = st.find(Y[i].first);
        ll nx = *next(it);

        if (Z[Y[i].second] < freq[nx]) {
            sol.push_back(Y[i].second);
        }
    }
    
    sortx(sol);
    cout << sol.size() << ' ';
    for (auto a : sol) cout << a << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("spainting.in", "r", stdin);
    // freopen("spainting.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
