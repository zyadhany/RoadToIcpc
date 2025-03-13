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


class Graph {
public:
    int size;
    vii adj;
    vi Indeg, Outdeg, lvl;
    int Timer;

    // each element from [Indeg[n], Outdeg[n]] is a subtree of node n
    void dfs(int n, int p=0, ll d=0) {
        Indeg[n] = Timer++;
        lvl[n] = d;
        for (auto neg : adj[n])
            if (neg != p) dfs(neg, n, d+1);
        Outdeg[n] = Timer - 1;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Graph(ll n) {
        Timer = 1;
        size = n;
        Indeg.assign(n + 1, 0);
        Outdeg.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        adj.resize(n + 1);
    }

};

void solve(int tc) {

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("promote.in", "r", stdin);
    // freopen("promote.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}