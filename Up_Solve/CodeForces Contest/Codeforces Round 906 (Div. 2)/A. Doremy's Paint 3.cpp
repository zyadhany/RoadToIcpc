#define _CRT_SECURE_NO_WARNINGS
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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll pos;

class Graph {
public:
    vi vis;
    vii adj;
    deque<ll> X;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void DFS(int n)
    {
        if (vis[n] == -1) {
            pos = 0;
            return;
        }
        else if (vis[n]) return;
        

        vis[n] = -1;
        for (int i = 0; i < adj[n].size(); i++)
            DFS(adj[n][i]);
        vis[n] = 1;

        X.push_front(n);
    }

    void print() {
        for (int i = 0; i < X.size(); i++)
        {
            cout << X[i] << '\n';
        }
    }

    Graph(ll n) {
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, a;

    cin >> n;

    mi X;

    for (int i = 0; i < n; i++) {
        cin >> a;
        X[a]++;
    }

    if (X.size() > 2) NO;

    if (abs(X.begin()->second - X.rbegin()->second) > 1) NO;
    YES;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}