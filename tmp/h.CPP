
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

ll fp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MODE;
        a = (a * a) % MODE;
        b >>= 1;
    }
    return res;
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vi X(n*2);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    vector<vp> adj(2*n);
    for (int i = 0; i < n; i++)
    {
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w});
    }
    
    vii dist(n*2);
    for (int i = 0; i < n*2; i++)
    {
        vi D(2*n, INT64_MAX);
        D[i] = 0;
        priority_queue<pl, vp, greater<>> pq;
        pq.push({0, i});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (D[u] != d) continue;
            for (auto [v, w] : adj[u]) {
                if (d+w < D[v]) {
                    D[v] = d+w;
                    pq.push({D[v], v});
                }
            }
        }
        dist[i] = D;
    }
    

    ll q; cin >> q;
    while (q--)
    {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--, c--;
        if (dist[a][c] + dist[c][b] == dist[a][b]) {
            // link a, b
            ll w = (4 * n - a - b) * X[a];
        }
    }
}

int main()  
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // INIT();
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
