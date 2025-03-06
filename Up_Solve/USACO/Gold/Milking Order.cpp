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


struct graph {
    ll n;
    vector<vi>adj;
    vi vis;

    void addedge(ll u, ll v) {
        adj[u].push_back(v);
    }
    
    vi TopologicalSort() {
        vi X, vis(n + 1);
        vi indeg(n + 1);
        
        for (int i = 1; i <= n; i++)
            for (auto neg : adj[i]) indeg[neg]++;
        
        priority_queue<ll, vi, greater<>> q;
        for (int i = 1; i <= n; i++) if (!indeg[i]) q.push(i);

        while (!q.empty())
        {
            ll tp = q.top();
            q.pop();
            X.push_back(tp);
            for (auto neg : adj[tp]) {
                indeg[neg]--;
                if (!indeg[neg]) q.push(neg);
            }
        }

        if (X.size() != n) return vi();
        return (X);
    }

    graph(ll n) {
        this->n = n;
        adj.assign(n + 1, vi());
        vis.assign(n + 1, 0);
    }
};


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii Z(m);
    for (int i = 0; i < m; i++)
    {
        ll k; cin >> k; Z[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> Z[i][j];
    }
    
    vi sol;
    ll l = 1, r = m;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        bool isit = 0;
        graph gr(n);
        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < Z[i].size() - 1; j++)
                gr.addedge(Z[i][j], Z[i][j+1]);
        }

        vi tps = gr.TopologicalSort();
        if (!tps.empty()) l = mid + 1, sol = tps;
        else r = mid - 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << sol[i];
        if (i != n-1) cout << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
