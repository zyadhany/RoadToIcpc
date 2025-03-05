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
 
const int MXN = 1e6 + 1;
int PAR[MXN], RAN[MXN];

ll get(ll n) {
    if (n == PAR[n]) return n;
    return PAR[n] = get(PAR[n]);
}

void add(ll u, ll v) {
    u = get(u), v = get(v);
    if (RAN[u] > RAN[v]) swap(u, v);
    RAN[u] += (RAN[u] == RAN[v]);

    PAR[v] = u;
}

void INIT() {
    for (int i = 0; i < MXN; i++)
    {
        PAR[i] = i;
        RAN[i] = 0;
    }
}

struct edge {
    ll u, v, w;
    edge(){}
    edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}
    bool operator<(edge &e) {
        return w < e.w;
    }
};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<edge> E;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        E.push_back(edge(u, v, w));
    }
    sortx(E);

    vector<edge> TOK;
    for (auto e : E) {
        if (get(e.u) != get(e.v)) {
            add(e.u, e.v);
            TOK.push_back(e);
        }
    }

    if (TOK.size() != n-1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    ll summ = 0;
    for (auto e : TOK) summ += e.w;
    cout << summ << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    INIT();
    // freopen("shortcut.in", "r", stdin);
    // freopen("shortcut.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
