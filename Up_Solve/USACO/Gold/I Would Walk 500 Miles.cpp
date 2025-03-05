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

const ll INF = 1e16;

const int MXN = 1e6 + 1;
int PAR[MXN], RAN[MXN];
 
ll get(ll k) {
    if (k == PAR[k]) return k;
    return PAR[k] = get(PAR[k]);
}
 
bool add(ll u, ll v) {
    u = get(u), v = get(v);
    
    if (u == v) return 0;
    if (RAN[u] < RAN[v]) swap(u, v);
    RAN[u] += (RAN[u] == RAN[v]);

    PAR[v] = u;
    return 1;
}
 
void INIT(ll n) {
    for (int i = 0; i <= n; i++) {
        RAN[i] = 0;
        PAR[i] = i;
    } 
}


struct edge {
    ll u, v, w;
    edge(){}
    edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}
    bool operator<(edge &e) {
        return w < e.w;
    }
};

void solve(int tc) {
    ll n, k;
    cin >> n >> k;

    priority_queue<pl, vp, greater<>> pq;
    pq.push({0, 1});
    vi vis(n + 1);
    vi Z;

    set<ll> st;
    for (int i = 0; i < n; i++)
        st.insert(i + 1);
    
    vi dp(n + 1, INT32_MAX);
    while (!pq.empty())
    {
        auto [w, tp] = pq.top();
        pq.pop();
        if (vis[tp]) continue;
        Z.push_back(w);
        vis[tp] = 1;
        st.erase(tp);

        for (auto i : st) {
            ll w = (2019201913ll*min(i,tp)+2019201949ll*max(i,tp)) % 2019201997ll;
            if (dp[i] > w) {
                pq.push({w, i});
                dp[i] = w;
            }
        }
    }
    sortx(Z);

    cout << Z[n-k+1] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
