#include <bits/stdc++.h>
#include <unordered_map>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 
const int MODE = 1e9 + 7;

#define INF 1e16


class Graph {
public:
    int size;
    vi vis;
    vector<vector<ll>> adj;

    void addEdge(int u, ll v) {
        adj[u].push_back(v);
    }

    ll DiemeterOfTree(vii &Z, int n, int p) {
        ll &res = Z[n][1];
        if (res) return (res);
        Z[n][0] = 1;
        res = 1;
        
        vi X(2, 0);
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            DiemeterOfTree(Z, neg, n);
            Z[n][0] = max(Z[n][0], Z[neg][0] + 1);
            X.push_back(Z[neg][0]);
            res = max(res, Z[neg][1]);
        }

        sort(X.rbegin(), X.rend());
        res = max(res, X[0] + X[1] + 1);
        return (res);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


void solve(ll tc) {

}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;1
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
