#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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
 
const int MODE = 1e9+7;

void solve(int tc) {
    ll n, d;

    cin >> n >> d;

    vp X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }
    
    map<ll, vp> mp;
    for (int i = 0; i < n; i++)
    {
        mp[X[i].first-X[i].second].push_back({X[i].first+X[i].second, i});
    }
    for (auto &v : mp) sortx(v.second);
    
    for (auto &[x, Y] : mp) {
        ll r = 0;
        for (int i = 0; i < Y.size(); i++)
        {
            while (r < Y.size() && Y[r].first - Y[i].first < d) r++;
            if (Y[r].first - Y[i].first == d) {
                // look  at  x - d, x + d
                if (mp.count(x-d)) {
                    auto Z = mp[x-d];
                    ll re = lower_bound(all(Z), pl(Y[i].first,0)) - Z.begin();
                    if (re < Z.size() && Z[re].first <= Y[i].first+d) {
                        cout << Y[i].second + 1 << ' ' << Y[r].second + 1 << ' ' << Z[re].second + 1;
                    }
                }
                if (mp.count(x+d)) {
                    auto Z = mp[x+d];
                    ll re = lower_bound(all(Z), pl(Y[i].first,0)) - Z.begin();
                    if (re < Z.size() && Z[re].first <= Y[i].first+d) {
                        cout << Y[i].second + 1 << ' ' << Y[r].second + 1 << ' ' << Z[re].second + 1;
                    }
                }
            }
        }
    }
    mp.clear();

    for (int i = 0; i < n; i++)
    {
        mp[X[i].first+X[i].second].push_back({X[i].first-X[i].second, i});
    }
    for (auto &v : mp) sortx(v.second);
    
    for (auto &[x, Y] : mp) {
        ll r = 0;
        for (int i = 0; i < Y.size(); i++)
        {
            while (r < Y.size() && Y[r].first - Y[i].first < d) r++;
            if (Y[r].first - Y[i].first == d) {
                // look  at  x - d, x + d
                if (mp.count(x-d)) {
                    auto Z = mp[x-d];
                    ll re = lower_bound(all(Z), pl(Y[i].first,0)) - Z.begin();
                    if (re < Z.size() && Z[re].first <= Y[i].first+d) {
                        cout << Y[i].second + 1 << ' ' << Y[r].second + 1 << ' ' << Z[re].second + 1;
                    }
                }
                if (mp.count(x+d)) {
                    auto Z = mp[x+d];
                    ll re = lower_bound(all(Z), pl(Y[i].first,0)) - Z.begin();
                    if (re < Z.size() && Z[re].first <= Y[i].first+d) {
                        cout << Y[i].second + 1 << ' ' << Y[r].second + 1 << ' ' << Z[re].second + 1;
                    }
                }
            }
        }
    }

    cout << "0 0 0\n";
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("262144.in", "r", stdin);
    // freopen("262144.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
