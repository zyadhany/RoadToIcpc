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

const int MX = 1e5 + 1;

ll n;
vector<pair<ld, ld>> X(MX);
vi nx(MX), pre(MX);
multiset<pair<ld, ll>> dist;

ld distToSegment(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> p) {
    ld dx = b.first - a.first;
    ld dy = b.second - a.second;

    // Vector projection scalar t
    ld t = ((p.first - a.first) * dx + (p.second - a.second) * dy) / (dx * dx + dy * dy);

    // Clamp t to [0, 1] to restrict to the segment
    t = max(0.0L, min(1.0L, t));

    // Closest point on segment
    pair<ld, ld> closest = {a.first + t * dx, a.second + t * dy};

    // Distance from P to the closest point
    ld x = p.first - closest.first;
    ld y = p.second - closest.second;
    return sqrt(x * x + y * y);
}

ld distline(ll i) {
    return distToSegment(X[i], X[nx[i]], {0, 0});
}

ld getdouble() {
    string s; cin >> s;
    return stold(s);
}

void solve(int tc) {
    cin >> n;

    dist.clear();

    for (int i = 1; i <= n; i++)
    {
        X[i].first = getdouble();
        X[i].second = getdouble();
        nx[i] = i + 1;
        pre[i] = i - 1;
    }
    pre[1] = n;
    nx[n] = 1;

    ld sx, sy;
    sx = getdouble();
    sy = getdouble();

    for (int i = 1; i <= n; i++)
    {
        X[i].first -= sx;
        X[i].second -= sy;        
    }
    for (int i = 1; i <= n; i++)
        dist.insert({distline(i), i});
    
    cout << fixed << setprecision(6) << dist.begin()->first << '\n';
    
    ll q; cin >> q;
    while (q--)
    {
        ll a; cin >> a;
        dist.erase(dist.find({distline(a), a}));
        dist.erase(dist.find({distline(pre[a]), pre[a]}));
        
        pre[nx[a]] = pre[a];
        nx[pre[a]] = nx[a];
        dist.insert({distline(pre[a]), pre[a]});
        cout << fixed << setprecision(6) << dist.begin()->first << '\n';
    } 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
