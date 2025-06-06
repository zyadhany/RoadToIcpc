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
using namespace std;

const int MODE = 998244353;




const int MXN = 5e3+10;
const int MAXSZ = MXN;
int prime[MAXSZ] = {0};
vi primes;
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
    for (int i = 2; i < MAXSZ; i++) if(prime[i] == i) primes.push_back(i);
}

vp conv(ll n) {
    vp res;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] != i) continue;
        ll cnt = 0;
        ll p = i;
        while (p <= n) {
            cnt += n / p;
            p *= i;
        }
        if (cnt) res.push_back({i, cnt});
    }
    reverse(all(res));
    return res;
}

vp merge(vp &a, vp &b) {
    if (a.empty() || b.empty()) return vp();
    if (a[0].first != b[0].first) return vp();
    vp res;
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        if (a[i] == b[i]) {
            res.push_back(a[i]);
            continue;
        }
        res.push_back({a[i].first, min(a[i].second, b[i].second)});
        break;
    }
    
    return res;
}

ll dist(vp &a, vp &b) {
    ll res = 0;
    ll d = min(a.size(), b.size());

    for (int i = 0; i < d; i++)
    {
        if (a[i] != b[i]) {
            d = i;
            break;
        }
    }
    
    if (d < a.size() && d < b.size()) {
        if (a[d].first == b[d].first) res = abs(a[d].second - b[d].second), d++;
    }
    for (int i = d; i < a.size(); i++)
    {
        res += a[i].second;
    }
    for (int i = d; i < b.size(); i++)
    {
        res += b[i].second;
    }
    
    return res;
}

pl dfs1(vector<vp> &adj, vector<pl> &dp, vi &V, ll n) {
    pl &res = dp[n]; 
    res = {0, V[n]};
    
    for (auto [neg, w] : adj[n]) {
        auto re = dfs1(adj, dp, V, neg);
        res.second += re.second;
        res.first += (re.first + w * re.second);
    }
    
    return res;
}

void dfs2(vector<vp> &adj, vi &V, vp &dp1, vi &dp2, ll n, pl tp) {
    dp2[n] = dp1[n].first + tp.first;
    for (auto [neg, w] : adj[n]) {
        ll wt = dp2[n] - (dp1[neg].first + w * dp1[neg].second);
        ll cnt = tp.second + dp1[n].second - dp1[neg].second;
        dfs2(adj, V, dp1, dp2, neg, {wt+cnt*w, cnt});
    }
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(MXN);

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        if (a == 0) a = 1;
        X[a]++;
    }

    vector<pair<vp, ll>> nodes;
    for (int i = 0; i < MXN; i++)
    {
        if (!X[i]) continue;
        nodes.push_back({conv(i), X[i]});
    }

    sortx(nodes);

    n = nodes.size();
    for (int i = 0; i < n-1; i++)
    {
        nodes.push_back({merge(nodes[i].first, nodes[i+1].first), 0});
    }

    sortx(nodes);
    vector<pair<vp, ll>> tm(1, nodes[0]);
    for (int i = 1; i < nodes.size(); i++)
    {
        if (tm.back().first == nodes[i].first) tm.pop_back();
        tm.push_back(nodes[i]);
    }
    swap(nodes, tm);
    n = nodes.size();

    vector<vp> adj(n);
    stack<ll> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (merge(nodes[st.top()].first, nodes[i].first) != nodes[st.top()].first) st.pop();
        adj[st.top()].push_back({i, dist(nodes[st.top()].first, nodes[i].first)});
        st.push(i);
    }
    
    vi V(n);
    for (int i = 0; i < n; i++) V[i] = nodes[i].second;
    
    vp dp1(n);
    vi dp2(n);
    
    dfs1(adj, dp1, V, 0);
    dfs2(adj, V, dp1, dp2, 0, {0, 0});

    ll res = INT64_MAX;
    for (auto a : dp2) res = min(res, a);
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    INIT();
    // freopen("cownav.in", "r", stdin);
    // freopen("cownav.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}