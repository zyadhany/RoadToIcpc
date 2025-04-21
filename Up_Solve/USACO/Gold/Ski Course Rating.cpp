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

const int MXN = 3e5;
int P[MXN], R[MXN], V[MXN], SZ[MXN];

ll get(ll n) {
    if (n == P[n]) return n;
    return P[n] = get(P[n]);
}

ll add(ll u, ll v, ll d, ll t) {
    u = get(u), v = get(v);
    if (u == v) return 0;

    if (R[v] > R[u]) swap(u, v);
    R[u] += (R[v] == R[u]);

    SZ[u] += SZ[v];
    V[u] += V[v];
    P[v] = u;

    ll cnt = 0;
    if (SZ[u] >= t) cnt = V[u], V[u] = 0;
    return cnt * d;
}

void INIT() {
    for (int i = 0; i < MXN; i++)
    {
        P[i] = i;
        R[i] = 0;
        SZ[i] = 1;
    }
}

void solve(int tc) {
    ll n, m, t;
    cin >> n >> m >> t;


    vii adj;
    vii X(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i][j];
        
            if (j) {
                ll d = abs(X[i][j] - X[i][j-1]);
                adj.push_back({d, i*m+j, i*m+j-1});
            }

            if (i) {
                ll d = abs(X[i][j] - X[i-1][j]);
                adj.push_back({d, i*m+j, (i-1)*m+j});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll a; cin >> a;
            V[i*m+j] = a;
        }
        
    }
    

    sortx(adj);
    ll sol = 0;
    
    for (auto e : adj) {
        sol += add(e[1], e[2], e[0], t);
    }
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
