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

const int MODE = 998244353;

using namespace std;

ll MXN = 2e5 + 1;
vi PAR(MXN);
vi SZ(MXN, 1);

ll get(ll n) {
    if (n == PAR[n]) return n;
    return PAR[n] = get(PAR[n]);
}

void add(ll u, ll v) {
    ll a = get(u), b = get(v);
    if (a == b) return;
    PAR[b] = a;
    SZ[a] += SZ[b];
}

void INIT() {
    for (int i = 0; i < MXN; i++)
        PAR[i] = i;    
}

struct edge {
    ll u, v, w;
    bool operator<(const edge& e) {
        return w < e.w;
    }
};

struct query {
    ll ind, k, v;
    bool operator<(const query& q) {
        return k < q.k;
    }
};

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vector<edge> E(n-1);
    for (int i = 0; i < n-1; i++)
        cin >> E[i].u >> E[i].v >> E[i].w;
    sortx(E);    

    vector<query> Q(q);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].k >> Q[i].v;
        Q[i].ind = i;
    }
    sort(Q.rbegin(), Q.rend());
    
    vi res(q);

    for (auto p : Q) {
        while (!E.empty() && E.back().w >= p.k) {
            add(E.back().u, E.back().v);
            E.pop_back();
        }
        res[p.ind] = SZ[get(p.v)] - 1;        
    }

    for (auto a : res) cout << a << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    INIT();

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
