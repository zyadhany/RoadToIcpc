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

<<<<<<< HEAD
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
     
=======
// Get all median for prefix of array
vector<ll> getMedian(vector<ll> &X)
{
    priority_queue<ll> L;
    priority_queue<ll, vector<ll>, greater<ll>> R;
    vector<ll> res;

    for (int i = 0; i < X.size(); i++)
    {
        if (!L.empty() && X[i] > L.top())
            R.push(X[i]);
        else
            L.push(X[i]);
    
        while (L.size() > R.size() + 1)
        {
            R.push(L.top());
            L.pop();
        }

        while (R.size() > L.size())
        {
            L.push(R.top());
            R.pop();
        }

        res.push_back(L.top());
    }

    return (res);
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    auto res = getMedian(X);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << ln;
>>>>>>> 7c98745ffc5c36ae65546af4db35cf289014e9db
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

<<<<<<< HEAD
    // freopen("248.in", "r", stdin);
    // freopen("248.out", "w", stdout);

=======
    // freopen("hayfeast.in", "r", stdin);
    // freopen("hayfeast.out", "w", stdout);
>>>>>>> 7c98745ffc5c36ae65546af4db35cf289014e9db
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
