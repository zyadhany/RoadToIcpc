#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 1e9+7;

const int MXN = 1e5 + 1;
int PAR[MXN];
int VAL[MXN];

ll get(ll k) {
    if (k == PAR[k]) return k;
    return PAR[k] = get(PAR[k]);
}
 
void add(ll u, ll v) {
    u = get(u), v = get(v);
    if (u == v) return;
    if (VAL[u] < VAL[v]) swap(u, v);
    VAL[u] += VAL[v];
    PAR[v] = u;    
}
 
void INIT() {
    for (int i = 0; i < MXN; i++) {
        PAR[i] = i;
        VAL[i] = 1;
    } 
}

void solve(ll tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        add(u, v);
    }

    vi X;
    for (int i = 1; i <= n; i++)
    {
        ll re = VAL[get(i)];
        if (re) X.push_back(re);
        VAL[get(i)] = 0;
    }
    
    bitset<MXN> bt;
    bt[0] = 1;
    
    for (auto a : X) bt |= (bt << a);
    for (int i = 1; i <= n; i++) cout << bt[i];
    cout << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    INIT();
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
