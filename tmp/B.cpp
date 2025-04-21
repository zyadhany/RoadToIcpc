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

const int MXN = 2e6 +10;
int P[MXN], R[MXN];
ll get(ll n) {
    if (n == P[n]) return n;
    return P[n] = get(P[n]);
}
void add(ll u, ll v) {
    u = get(u), v = get(v);
    if (u == v) return;
    if (R[v] > R[u]) swap(u, v);
    R[u] += (R[v] == R[u]);
    P[v] = u;
}
void INIT() {
    for (int i = 0; i < MXN; i++)
    {
        P[i] = i;
        R[i] = 0;
    }
}

struct tree {
    ll x, y, r;
};
ld dist(tree &a, tree & b) {
    ld x = a.x - b.x;
    ld y = a.y - b.y;
    return sqrtl(x*x+y*y);
}

void solve(int tc) {
    ll n,m, w, h;

    cin >> n >> m;
    cin >> w >> h;

    vector<tree> X(n);
    vii Y(m, vi(3));
    
    for (int i = 0; i < n; i++) cin >> X[i].x >> X[i].y >> X[i].r;
    for (int i = 0; i < m; i++)
    {
        cin >> Y[i][0] >> Y[i][1];
        Y[i][1]--;
        Y[i][2] = i;
    }
    
    set<pl> edg;
    for (auto t : X) {
        edg.insert({0, t.y});
        edg.insert({w, t.y});
        edg.insert({t.x, 0});
        edg.insert({t.x, h});
    }
    X.push_back({0, 0, 0});
    X.push_back({0, h, 0});
    X.push_back({w, 0, 0});
    X.push_back({w, h, 0});
    for (auto p : edg) X.push_back({p.first, p.second, 0});
    
    ll at = 0;
    
    vector<vector<pair<pair<ld, ld>, ll>>> adjedg(n + 4);
    vii adjnd(n + 4);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < X.size(); j++)
        {
            ld d = dist(X[i], X[j]) - X[i].r - X[j].r;
            ll dx = X[j].x - X[i].x;
            ll dy = X[j].y - X[i].y;
            
            adjedg[i].push_back({{atan2l(dy, dx), d}, at});
            adjnd[i].push_back(at);
            if (j < n + 4) {
                adjedg[j].push_back({{atan2l(-dy, -dx), d}, at});
                adjnd[j].push_back(at);
            }
            at+=2;
        }
        sort(adjedg[i].begin(), adjedg[i].end());
    }
    set<pair<ld, pl>> edgset;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adjnd[i].size(); j++)
        {
            ll cur = adjnd[i][j];
            edgset.insert({adjedg[i][j].first.second, {cur, cur+1}});
            
            ll nx = adjnd[i][(j+1)%adjnd[i].size()];
            edgset.insert({adjedg[i][j].first.second, {min(cur,nx), max(nx, cur)}});
            edgset.insert({adjedg[i][j].first.second, {cur+1, nx+1}}); 
        }
    }
    
    vi ndpar(4);
    for (int i = 0; i < X.size(); i++)
    {
        if (X[i].x == 0 && X[i].y == 0) ndpar[0] = adjnd[i][0];
        if (X[i].x == 0 && X[i].y == h) ndpar[1] = adjnd[i][0];
        if (X[i].x == w && X[i].y == 0) ndpar[2] = adjnd[i][0];
        if (X[i].x == w && X[i].y == h) ndpar[3] = adjnd[i][0];
    }
    
    sort(Y.rbegin(), Y.rend());
    
    vii res(m);
    for (auto p : Y) {
        while (!edgset.empty() && prev(edgset.end())->first >= 2*p[0]) {
            pair<ld, pl> e = *prev(edgset.end());
            edgset.erase(prev(edgset.end()));
            ll u = get(e.second.first), v = get(e.second.second);
            add(u, v);
        }
        for (int i = 0; i < 4; i++)
            if (get(ndpar[i]) == get(ndpar[p[1]])) {
                res[p[2]].push_back(i);
            }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (auto a : res[i]) cout << a+1;
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    
    INIT();
    // freopen("skilevel.in", "r", stdin);
    // freopen("skilevel.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
