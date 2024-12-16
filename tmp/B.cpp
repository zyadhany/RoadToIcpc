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

const int MODE = 1e9 + 7;

using namespace std;

pl getch(vii &adj, vp &CH, vi &X, ll n, ll p) {
    if (X[n]) CH[n] = {1, 0};
    for (auto neg : adj[n]) {
        if (neg == p) continue;
        pl re = getch(adj, CH, X, neg, n);
        re.second += re.first;
        CH[n].first += re.first;
        CH[n].second += re.second;
    }
    return CH[n];
}

ll res;

ll req(vii &adj, vp &CH, vi &X,ll n, ll p, ll h, ll prev) {

    vp Z;
    if (X[n]) Z.push_back({1, 0});
    for (auto neg : adj[n]) if (neg != p) {
        Z.push_back(CH[neg]);
    }

    sortx(Z);
    ll summ = 0;

    for (int i = 0; i < Z.size() - 1; i++)
    {
        summ += Z[i].first; 
    }
    
    if (summ >= Z.back().first - prev) {
        for (auto p : Z) res+=p.second;
        return h;
    }

    for (int i = 0; i < Z.size() - 1; i++)
        res += Z[i].second;
    // cout << n << ' ' << CH[adj[n][0]].second << ' ' << ' ' << g << "|" << endl;
    ll x = summ;

    cout << n << " " << x << "|\n"; 
    ll g = -1;
    for (auto neg : adj[n]) if (neg != p && CH[neg] == Z.back())
        g = neg;
    
    ll nexthei = req(adj, CH, X, g, n, h + 1, prev + x);
    res += (nexthei - h) * x;

    return nexthei;
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n + 1);
    for (int i = 0; i < k * 2; i++) {
        ll a; cin >> a;
        X[a] = 1;
    }

    vii adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        

    vp CH(n + 1);
    getch(adj, CH, X, 1, 0);

    res = 0;
    req(adj, CH, X, 1, 0, 0, 0);

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("sabotage.in", "r", stdin);
    // freopen("sabotage.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
