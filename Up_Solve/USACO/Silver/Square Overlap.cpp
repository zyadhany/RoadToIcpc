#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>

#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
#define int ll


ll intersect(pair<pl, pl> p1, pair<pl, pl> p2) {
    auto [a1, a2] = p1;
    auto [b1, b2] = p2;
    ll x1 = max(a1.first, b1.first);
    ll y1 = max(a1.second, b1.second);
    ll x2 = min(a2.first, b2.first);
    ll y2 = min(a2.second, b2.second);
    
    if (x1 > x2 || y1 > y2) return 0;
    ll area = (x2 - x1) * (y2 - y1);
    return area;  
}


struct query
{
    ll x, ind, ty;
    query(ll xa, ll inda, ll tya) {
        x = xa, ind = inda, ty = tya;
    }
    bool operator<(const query &a) const {
        if (x != a.x) return x < a.x;
        if (ty != a.ty) return ty < a.ty;
        return ind < a.ind;
    }
};


void solve(ll tc) {
    ll n, k; cin >> n >> k;

    vector<pair<pl, pl>> X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first.first >> X[i].first.second;
        X[i].second = {X[i].first.first + k, X[i].first.second+k};
    }

    vector<query> Q;

    for (int i = 0; i < n; i++) {
        Q.push_back(query(X[i].first.first, i, 0));
        Q.push_back(query(X[i].second.first, i, 1));        
    }
    sortx(Q);

    ll sol = 0;
    set<pl> st;

    for (auto q : Q) {
        if (q.ty == 0) {
            st.insert({X[q.ind].first.second, q.ind});
        } else {
            auto it = st.find({X[q.ind].first.second, q.ind});
            auto tt = it; tt++;
            if (tt != st.end())
            {
                ll k = intersect(X[q.ind], X[tt->second]);
                if (k) {
                    if (sol) MUN;
                    sol = k;
                }
                tt++;
            }
            tt = it;
            if (tt != st.begin())
            {
                tt--;
                ll k = intersect(X[q.ind], X[tt->second]);
                if (k) {
                    if (sol) MUN;
                    sol = k;
                }
            }
            st.erase(it);
        }
    }

    cout << sol << '\n';
}
 
int32_t main()
{
    int size = 1;
 
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}   
