#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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
 
const int MODE = 1e9+7;

const int N = 1e5+10;
ll PC[N]{}, lvl[N]{};
ll spt[N][18];

void add(ll n, ll p) {
    lvl[n] = lvl[p]+1;
    spt[n][0] = p;
    for (int j = 1; j < 18; j++)
        spt[n][j] = spt[spt[n][j-1]][j-1];     
}

ll kth(ll u, ll k) {
    for (int i = 0; i < 18; i++)
        if (k & (1<<i)) u = spt[u][i];    
    return u;
}

ll lca(ll u , ll v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    u = kth(u, lvl[u]-lvl[v]);
    if (u == v) return u;
    for (int i = 17; i >= 0; i--)
        if (spt[u][i] != spt[v][i]) u = spt[u][i], v = spt[v][i];        
    return spt[u][0];
}

ll dist(ll u, ll v) {
    return lvl[u] + lvl[v] - 2 * lvl[lca(u, v)];
}

void solve(int tc) {
    ll q;
    cin >> q;

    vp T;

    ll at = 0;
    while (q--) {
        ll x;
        char ty;
        cin >> ty >> x;

        if (ty == 'B') {
            at++;
            if (x == -1) {
                PC[at] = T.size();
                T.push_back({at, at});
            } else {
                add(at, x);
                ll c = PC[x];
                PC[at] = c;
                ll cd = dist(T[c].first, T[c].second);
                auto [a, b] = T[c];
                if (dist(at, a) > cd) T[c] = {at, a};
                else if (dist(at, b) > cd) T[c] = {at, b};
            }
        } else {
            ll c = PC[x];
            cout << max(dist(x, T[c].first), dist(x, T[c].second)) << '\n';
        }
    }
    
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}