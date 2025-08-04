#include "bits/stdc++.h"
#define ll  long long
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pl pair<ll, ll>
#define vp vector<pl>
#define all(x) x.begin(),x.end()


const int MAXSZ = 1e5+10;
int prime[MAXSZ]={0};
vi primes;
void INIT(){
    for(int i=0;i<MAXSZ;i++)prime[i]=i;
    for(int i=2;i*i<MAXSZ;++i)if(prime[i]==i)
    for(int j=i;j<MAXSZ;j+=i)prime[j]=i;
    for(int i=2;i<MAXSZ;i++)if(prime[i]==i)primes.push_back(i);
    prime[1] = 0;
}

const int N = 9596;
typedef bitset<N> item;
ll primeind(ll x) {
    ll re = lower_bound(all(primes), x) - primes.begin();
    return re;
}

const int MX = 1e5+10;
bitset<N> bt[MX];

void solve() {
    ll n, q; cin >> n >> q;
    vi X(n+1);
    for (int i = 0; i < n; i++) cin >> X[i+1];
    
    vii adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    for (int i = 1; i <= n; i++)
    {
        if (prime[X[i]] == X[i]) {
            bt[i][primeind(X[i])] = 1;
        }
    }

    vi P(n+1);
    function<void(ll, ll)> dfs = [&](ll u, ll p) -> void {
        P[u] = p;
        for (auto neg : adj[u]) if (neg != p) {
            dfs(neg, u);
            bt[u] |= bt[neg];
        }
    };
    dfs(1, 0);
    
    while (q--)
    {
        ll ty; cin >> ty;
        if (ty == 1) {
            ll u; cin >> u;
            cout << bt[u].count() << '\n';
        } else if (ty == 2) {
            ll u, x; cin >> u >> x;
            ll ind = primeind(x);
            cout << bt[u][ind] << '\n';
        } else {
            ll u, x; cin >> u >> x;
            ll ind;
            if (prime[X[u]]==X[u]) {
                ind = primeind(X[u]);
                ll at = u;
                while (at)
                {
                    bt[at][ind] = 0;
                    at = P[at];
                }
            }

            X[u] = x;
            if (prime[X[u]]==X[u]) {
                ind = primeind(X[u]);
                bt[u][ind] = 1;
            }
            ll at = u;
            while (at)
            {
                for (auto neg : adj[at]) if (neg != P[at]) bt[at] |= bt[neg];
                at = P[at];
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    INIT();
    // cin >> t;
    while (t--)
    {
        solve();
    }
}