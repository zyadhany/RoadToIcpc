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

ll CrossPrduct(pl a, pl b) {
    return a.first * b.second - a.second * b.first;
}

int PointLocation(pl a, pl b, pl c) {
    ll res = CrossPrduct({c.first-a.first, c.second-a.second}, {c.first-b.first, c.second-b.second});
    if (res > 0) return 1; // LEFT
    else if (res < 0) return -1; // RIGHT
    return 0; // TOUCH
}

bool intersect(pair<pl, pl> p1, pair<pl, pl> p2) {
    auto [a1, a2] = p1;
    auto [b1, b2] = p2;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = min(a1.first, a2.first), x2 = max(a1.first, a2.first);
	y1 = min(a1.second, a2.second), y2 = max(a1.second, a2.second);
	x3 = min(b1.first, b2.first), x4 = max(b1.first, b2.first);
	y3 = min(b1.second, b2.second), y4 = max(b1.second, b2.second);
	if ((x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1)) return 0;

    int d1 = PointLocation(a1, a2, b1);
    int d2 = PointLocation(a1, a2, b2);
    int d3 = PointLocation(b1, b2, a1);
    int d4 = PointLocation(b1, b2, a2);

    return (d1 * d2 <= 0 && d3 * d4 <= 0);
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
    ll n; cin >> n;

    vector<pair<pl, pl>> X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first.first >> X[i].first.second >> X[i].second.first >> X[i].second.second;
        if (X[i].first.first > X[i].second.first) swap(X[i].first, X[i].second);
    }

    vector<query> Q;

    for (int i = 0; i < n; i++) {
        Q.push_back(query(X[i].first.first, i, 0));
        Q.push_back(query(X[i].second.first, i, 1));        
    }
    sortx(Q);

    set<pl> st;
    vi dp(n);

    for (auto q : Q) {
        if (q.ty == 0) {
            st.insert({X[q.ind].first.second, q.ind});
        } else {
            auto it = st.find({X[q.ind].first.second, q.ind});
            auto tt = it; tt++;
            while (tt != st.end())
            {
                if (intersect(X[q.ind], X[tt->second])) {
                    dp[q.ind]++, dp[tt->second]++;
                } else break;
                tt++;
            }
            tt = it;
            while (tt != st.begin())
            {
                tt--;
                if (intersect(X[q.ind], X[tt->second])) {
                    dp[q.ind]++, dp[tt->second]++;
                }else break;
            }
            st.erase(it);
        }
    }

    ll cnt, sol;
    cnt = 0, sol = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > cnt) sol = i, cnt = dp[i];
    }
    cout << sol + 1 << '\n';
}
 
int32_t main()
{
    int size = 1;
 
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
