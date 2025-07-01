#include "bits/stdc++.h"

#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define int ll
#define pl pair<ll, ll>
#define vp vector<pl>
using namespace std;

void solve() {
    ll n;

    cin >> n;

    vi X(n + 1);

    for (int i = 1; i <= n; i++)
    {
        char c; cin >> c;
        if (c == '(') X[i]  = 1;
        else X[i] = -1;
    }
    
    vector<set<ll>> adj(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    ll sol = 0;

    vi sz(n+1);
    
    function<ll(ll, ll)> dfssz = [&](ll u, ll p) -> ll {
        sz[u] = 1;
        for (auto neg : adj[u]) if (neg != p) sz[u] += dfssz(neg, u);
        return sz[u];
    };
    function<ll(ll, ll, ll)> getcen = [&](ll u, ll p, ll n) -> ll {
        sz[u] = 1;
        for (auto neg : adj[u])
            if (neg != p && sz[neg] > n / 2) return getcen(neg, u, n);
        return u;
    };


    function<void(ll)> cendec = [&](ll u) -> void {
        ll n = dfssz(u, 0);
        ll cen = getcen(u, 0, n);
        n = dfssz(cen, 0);
        // solve from cen as root.

        function<vi(vi&, ll, ll, ll, ll)> dfs = [&](vi &par, ll u, ll p, ll cnt, ll st) -> vi {
            st += X[u];
            if (st < 0) cnt++, st = 0;
            if (st == 0) par[cnt]++;

            vi ch(sz[u]+1);
            for (auto neg : adj[u]) if (neg != p) {
                auto tm = dfs(par, neg, u, cnt, st);
                for (int i = 0; i < tm.size(); i++) ch[i] += tm[i];                
            }
            if (X[u] > 0) {
                ch.push_back(ch.back());
                for (int i = ch.size() - 1; i > 0; i--) ch[i] = ch[i-1];                
                ch[1]++;
            } else {
                for (int i = 0; i < ch.size() - 1; i++) ch[i] = ch[i+1];   
                ch[0] = 0;             
            }
            return ch;
        };

        ll re = 0;
        vi P(n+5), C(n+5);

        for (auto neg : adj[cen]) {
            vi par(sz[neg]+1);
            // cout << cen << ' ' << neg << endl;
            auto ch = dfs(par, neg, cen, 0, 0);
            if (X[cen] == 1) re += par[1];
            else re += ch[1];
            if (X[cen] > 0) {
                ch.push_back(ch.back());
                for (int i = ch.size() - 1; i > 0; i--) ch[i] = ch[i-1];    
                ch[0]=0;            
            } else {
                for (int i = 0; i < ch.size() - 1; i++) ch[i] = ch[i+1];                
            }

            if (cen == 1) {
                cout << neg << "|\n";
                for (int i = 0; i < ch.size(); i++) cout << i << ' ' << ch[i] << '\n';
                
            }
            for (int i = 0; i < ch.size(); i++)
            {
                if (cen == 1) {
                    // cout << n
                    // cout << neg << ' ' << re << "|\n";
                    // cout << i << ' ' << ch[i] << ' ' << P[i] << '\n'; 
                    // re = 0;
                }
                re += ch[i] * P[i];
            }
            for (int i = 0; i < par.size(); i++)
            {
                re += par[i] * C[i];
            }
            
            for (int i = 0; i < ch.size(); i++) C[i] += ch[i];            
            for (int i = 0; i < par.size(); i++) P[i] += par[i];            
        }

        // cout << cen << ' ' << n << ' ' << re << "|\n";
        sol += re;
        // cout << cen << ' ' << n << ' ' << re << endl;
        for (auto neg : adj[cen]) {
            adj[neg].erase(cen);
            cendec(neg);
        }                                                                                                                                         
    };

    cendec(1);
    cout << sol << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // INIT();
    // cin >> t;
    while (t--)
    {
        solve();
    }
}