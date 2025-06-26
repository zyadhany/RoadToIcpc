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
 
const int MODE = 998244353;

struct centroid
{
    ll sz, root;
    vi cnt, P;
    ll ans;
    vector<set<pl>> adj;

    ll dfs(ll u, ll p) {
        cnt[u] = 1;
        for (auto [neg, w] : adj[u]) if (neg != p) cnt[u] += dfs(neg, u);
        return cnt[u];
    }
    ll dfs(ll u, ll p, ll n) {
        for (auto [neg, w] : adj[u])
            if (neg != p && cnt[neg] > n/2) return dfs(neg, u, n); 
        return u;
    }

    void dfs2(mi &mp, mi &mpz, mi &tmp, ll u, ll p, ll w) {
        if (tmp[w]) mpz[w]++;
        else mp[w]++;
        P[u] = w;
        tmp[w]++;
        for (auto [neg, nw] : adj[u]) if (neg != p) {
            dfs2(mp, mpz, tmp, neg, u, w + nw);
        }
        tmp[w]--;
    }

    void decomp(ll u, ll p) {
        ll n = dfs(u, p);
        ll cen = dfs(u, p, n);

        mi mp, mpz;
        for (auto [neg, w] : adj[cen]) {
            mi tmp, tmpz, st;
            dfs2(tmp, tmpz, st, neg, cen, w);

            for (auto [a,b] : tmp)
                if (a) ans += mpz[-a] * b;
            for (auto [a,b] : tmpz)
                if (a) ans += (mp[-a] + mpz[-a]) * b;
            ans += (tmp[0]+tmpz[0]) * (mp[0]+mpz[0]);
            for (auto [a,b] : tmp) mp[a]+=b;
            for (auto [a,b] : tmpz) mpz[a]+=b;
        }
        ans += mpz[0];
        for (auto [neg, w] : adj[cen]) {
            adj[neg].erase({cen, w});
            decomp(neg, cen);
        }
    }

    centroid(vector<vp> adjtm, ll n) {
        sz = n;
        ans = 0;
        adj.resize(n+1);
        P.assign(n + 1, 0);
        cnt.assign(n+1, 0);
        for (int i = 0; i <= n; i++)
            adj[i].insert(all(adjtm[i]));
        decomp(1, -1);
    }
};


void solve(int tc) {
    ll n;

    cin >> n;

    vector<vp> adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        if (!w) w = -1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    centroid cd(adj, n);

    cout << cd.ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

	freopen("yinyang.in", "r", stdin);
    freopen("yinyang.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
