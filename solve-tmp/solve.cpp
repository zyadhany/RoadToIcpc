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

void req(vp &adj, vector<set<pl>> &st, vi &at, vi &H, ll n, ll h) {
    if (!n) return;
    H[n] = h;
    if (h == st.size()) st.push_back(set<pl>({{0, n}})), at[n]=0;
    else at[n]=st[h].size(), st[h].insert({st[h].size(), n});
    
    req(adj, st, at, H, adj[n].first, h + 1);
    req(adj, st, at, H, adj[n].second, h + 1);
}


void rem(vp &adj, vi &vis, vi &at, set<ll> &sl, vector<set<pl>> &st, ll n, ll h) {
    if (vis[n]) return;
    vis[n] = 1;
    if (!n) return;
    
    sl.erase(prev(st[h].end())->second);
    // for (auto a : st[h]) cout << a.first << ' ' << a.second << "|\n";
    // cout << n << ' ' << at[n] << " ";
    st[h].erase({at[n], n});
    // cout << st[h].size() << "|\n";
    if (!st[h].empty()) sl.insert(prev(st[h].end())->second);    

    rem(adj, vis, at, sl, st, adj[n].first, h+1);
    rem(adj, vis, at, sl, st, adj[n].second, h+1);
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vp X(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }

    vector<set<pl>> st;
    vi at(n + 1);
    vi H(n + 1);
    req(X, st, at, H, 1, 0);

    vi vis(n + 1);
    set<ll> sl;
    for (auto a : st) sl.insert(prev(a.end())->second);
    while (q--)
    {
        ll x; cin >> x;
        rem(X, vis, at, sl, st, x, H[x]);
        cout << *prev(sl.end()) << '\n';
    }
     
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("248.in", "r", stdin);
    // freopen("248.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
