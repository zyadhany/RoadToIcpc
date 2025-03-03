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

ll MXN = 1e6 + 1;
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
    edge (ll u, ll v, ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator<(const edge& e) {
        return w < e.w;
    }
};

void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n + 10, vi(n + 10, INT32_MAX));
    vector<edge> E;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> X[i][j];

            ll u, v, w;
            u = i*(n+1)+j;
            v = (i-1)*(n+1)+j;
            w = abs(X[i][j] - X[i-1][j]);
            E.push_back(edge(u, v, w));

            v = i*(n+1)+j-1;
            w = abs(X[i][j] - X[i][j-1]);
            E.push_back(edge(u, v, w));
        }
    }
    
    sortx(E);

    ll gl = (n*n+1)/2;
    for (auto e : E) {
        add(e.u, e.v);
        ll s = SZ[get(e.u)];
        if (s >= gl) {
            cout << e.w << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    INIT();

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
