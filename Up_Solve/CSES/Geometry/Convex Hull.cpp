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

typedef pair<ll, ll> P;
ll CrossPrduct(pl a, pl b) {
    return a.first * b.second - a.second * b.first;
}
vp ConvexHull(vp X) {
    sortx(X);
    X.erase(unique(all(X)), X.end());
    int n = X.size();

    vp HL;

    if (n < 3) return X;

    // Lower hull
    for (int i = 0; i < n; i++) {
        while (HL.size() >= 2) {
            pl a = HL[HL.size() - 1], b = HL[HL.size() - 2];
            if (CrossPrduct({a.first - b.first, a.second - b.second}, {X[i].first - b.first, X[i].second - b.second}) >= 0) break;
            HL.pop_back();
        }
        HL.push_back(X[i]);
    }

    int t = HL.size();
    // Upper hull
    for (int i = n - 2; i >= 0; i--) {
        while (HL.size() > t) {
            pl a = HL[HL.size() - 1], b = HL[HL.size() - 2];
            if (CrossPrduct({a.first - b.first, a.second - b.second}, {X[i].first - b.first, X[i].second - b.second}) >= 0) break;
            HL.pop_back();
        }
        HL.push_back(X[i]);
    }
    
    HL.pop_back();

    return HL;
}

void solve(ll tc) {
    ll n; cin >> n;
    vp X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }
    
    auto H = ConvexHull(X);

    cout << H.size() << '\n';
    for (auto p : H) cout << p.first << ' ' << p.second << '\n';
}
 
int32_t main()
{
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
