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
#define YES {cout << "Alice\n"; return;}
#define NO {cout << "Bob\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

const ll INF = 1e16;

#define INF 1e16

class Graph {
public:
    int size;
    vector<vector<pl>> adj;

    void addEdge(int u, ll v, ll w) {
        adj[u].push_back({v, w});
    }

    bool spfa(int s, vi &dist) {  /// Shortest Path Faster Algorithm
        vi cnt(size+1);
        vi inq(size+1);
        for(int i=0; i<size; i++) {
            dist[i] = INF;
            cnt[i] = 0; inq[i] = 0;
        }
        queue<int> q;

        dist[s] = 0;
        q.push(s); inq[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop(); inq[v] = 0;

            for(auto e : adj[v]) {
                int u = e.first, w = e.second;
                if(dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    if(dist[u] < 0 ) return false; /// optimization for TLE.
                    if(!inq[u]) {
                        q.push(u); inq[u] = 1;
                        cnt[u]++;
                        if(cnt[u]>size) return false;
                    }
                }
            }
        }

        return true;
    }

    Graph(ll n) {
        size = n;
        adj.resize(n + 1);
    }
};

void solve(int tc) {
    ll n, m;
    cin >> n >> m;

    Graph gr(n+1);
    for (int i = 1; i <= n; i++)
    {
        gr.addEdge(0, i, i);
        gr.addEdge(i, i-1, 0);    
        gr.addEdge(i-1, i, 1);    
    }
    
    for (int i = 0; i < m; i++)
    {
        ll l, r, k, v;
        cin >> l >> r >> k >> v;
        l++, r++;
        ll len = r - l + 1;
        if (v == 0) {
            gr.addEdge(l-1, r, len - k);
        } else {
            gr.addEdge(r, l-1, k-len-1);
        }
    }
    
    vi P(n+1);
    auto cyc = gr.spfa(0, P);
    if (!cyc) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << P[i]-P[i-1] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
