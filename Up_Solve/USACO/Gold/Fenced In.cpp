#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll int
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
 
const int MXN = 5e6 + 100;
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

vector<edge> MST_Kruskal(vector<edge> &E) {
    vector<edge> TOK;
    sort(E.begin(), E.end());

    for (auto e : E) {
        if (get(e.u) != get(e.v)) {
            add(e.u, e.v);
            TOK.push_back(e);
        }
    }

    return TOK;
}

void solve(int tc) {
    ll A, B, n, m;
    cin >> A >> B >> n >> m;

    vi X(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> X[i];
    X[n + 1] = A;

    vi Y(m + 2);
    for (int i = 1; i <= m; i++)
        cin >> Y[i];
    Y[m+1] = B;
    
    vector<edge> E;

    sortx(X); sortx(Y);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            ll u, v, w;
            u = (m+1)*(i-1) + j - 1;
            v = (m+1)*i + j - 1;
            w = Y[j] - Y[j-1];
            E.push_back(edge(u, v, w));
        }
    }
    
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m; j++)
        {   
            ll u, v, w;
            u = (m+1)*(i-1) + j - 1;
            v = (m+1)*(i-1) + j;
            w = X[i] - X[i-1];
            E.push_back(edge(u, v, w));
        }
    }

    long long sol = 0;
    sort(E.begin(), E.end());

    for (auto e : E) {
        if (get(e.u) != get(e.v)) {
            add(e.u, e.v);
            sol += e.w;
        }
    }

    cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    INIT();
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
