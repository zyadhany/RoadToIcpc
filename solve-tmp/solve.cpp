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

const int MXV = pow(4, 27);
vi PW27(5, 1);


class Graph {
public:
    int size;
    vi vis;
    vii adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool DFS(vi &X, int u) {
        if (vis[u] == 1) return 1;
        if (vis[u] == -1) return 0;
        vis[u] = -1;

        for (auto v : adj[u])
            if (!DFS(X, v)) return 0;

        X.push_back(u);
        vis[u] = 1;
        return 1;
    }

    vi TopologicalSort() {
        vi X;
        for (int i = 1; i <= size; i++) 
            if (!DFS(X, i)) return vi();
        reverse(all(X));
        return (X);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


ll geths(string &s) {
    ll re = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ll k;
        if (s[i] == '_') k = 0;
        else k = s[i] - 'a' + 1;
        re += k * PW27[i];
    }
    return re;
}

set<ll> getcomb(string &s) {
    set<ll> st;
    for (int j = 0; j < 1<<s.size(); j++)
    {
        string t = "";
        for (int h = 0; h < s.size(); h++)
        if (j & (1 << h)) t += s[h];
        else t += "_"; 
        ll re = geths(t);
        st.insert(re);
    }
    return st;
}

void solve(int tc) {
    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<string> X(n + 1);
    vi HS(n + 1); 
    Graph gr(n);
    vector<set<ll>> Z(MXV);
    
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        HS[i] = geths(X[i]);
        Z[HS[i]].insert(i);
    }

    vector<pair<ll, string>> Y(m);    
    for (int i = 0; i < m; i++)
        cin >> Y[i].second >> Y[i].first;
    
    sort(Y.rbegin(), Y.rend());
    for (pair<ll, string> pp : Y) {
        string s = pp.second;
        ll ind = pp.first;
        set<ll> st = getcomb(s);
    
        if (!st.count(HS[ind])) NO;
    
        for (int j = 1; j <= n; j++)
        {
            if (j == ind) continue;
            if (st.count(HS[j])) {
                gr.addEdge(ind, j);
            }
        }
    }

    auto tps = gr.TopologicalSort();

    if (tps.empty()) NO;
    cout << "YES\n";
    for (auto a : tps) cout << a << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    
    // freopen("milkorder.in", "r", stdin);
    // freopen("milkorder.out", "w", stdout);
    
    for (int i = 1; i < PW27.size(); i++)
    PW27[i] = PW27[i-1] * 27;
    
    // cin >> size;
    for (int i = 1; i <= size; i++)
    solve(i);
}
