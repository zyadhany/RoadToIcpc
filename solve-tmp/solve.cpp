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
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
 
const int MODE = 1e9+7;


void solve(int tc) {
    ll n;

    cin >> n;
    
    vi X(n), Y(n);
    for (int i = 0; i < n; i++) cin >> X[i];
    for (int i = 0; i < n; i++) cin >> Y[i];
    

    vector<vp> adj(2*n+1);
    for (int i = 0; i < n; i++)
    {
        adj[X[i]].push_back({Y[i], i});
        adj[Y[i]].push_back({X[i], i});
    }
    
    vi vis(2*n+1);
    vi edvis(2*n+1);
    vi L(n), R(n);

    function<void(ll, ll, ll)> dfs = [&](ll u, ll p, ll rev=0) -> void {
        bool dn = 0;
        vis[u] = 1;
        for (auto [neg, ind] : adj[u]) if (ind != p && !edvis[ind]) {
            edvis[ind] = 1;
            if (!dn && p==-1) rev^=1;
            L[ind] = u, R[ind] = neg;
            if (rev) swap(L[ind], R[ind]);
            if (!vis[neg]) dfs(neg, ind,rev);

            if (!dn && p==-1) rev^=1, dn = 1;
        }
    };

    for (int i = 1; i <= 2*n; i++)
    {
        if (!vis[i] && !adj[i].empty()) {
            dfs(i, -1, 0);
        }
    }
    

    ll res = set<ll>(all(L)).size() + set<ll>(all(R)).size();
    cout << res << '\n';
    for (auto a : L) cout << a << ' ';
    cout << '\n';
    for (auto a : R) cout << a << ' ';
    cout << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("kangaroo.in", "r", stdin);
    // freopen("kangaroo.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}