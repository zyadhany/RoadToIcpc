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

const int MXN = 1e5+1;
int P[MXN], V[MXN], R[MXN];
set<int> adj[MXN];

int get(ll u) {
    if (u == P[u]) return u;
    return P[u] = get(P[u]);
}

void add(ll u, ll v) {
    u = get(u), v = get(v);
    if (u == v) return;

    if (R[v] > R[u]) swap(u, v);
    else if (R[u] == R[v]) R[u]++;
    P[v] = u;
    V[u] += V[v];
}

void INIT() {
    for (int i = 0; i < MXN; i++)
    {
        P[i]=i;
        V[i]=1;
        R[i] = 0;
    }
}

void solve(int tc) {
    ll n, m;
    
    cin >> n >> m;
    

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    set<pl> st;
    vi deg(n);
    for (int i = 0; i < n; i++)
    {
        st.insert({adj[i].size(), i});
        deg[i] = adj[i].size();
    }
    
    vp Q;
    vi vis(n), rem(n);
    while (!st.empty()) {
        ll u = st.begin()->second;
        Q.push_back(*st.begin());
        st.erase(st.begin());
        rem[u] = 1;
        for (auto v : adj[u]) {
            if (rem[v]) continue;
            st.erase({deg[v], v});
            deg[v]--;
            st.insert({deg[v], v});
        }
    }

    ll sol = 0;
    INIT();
    reverse(all(Q));
    for (auto [w, u] : Q) {
        for (auto neg:adj[u]) if (vis[neg]) {
            add(u, neg);
        }
        vis[u] = 1;
        sol = max(sol, w * V[get(u)]);
    }
    cout << sol << '\n';
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