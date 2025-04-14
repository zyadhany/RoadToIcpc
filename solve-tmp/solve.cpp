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

const int MODE = 1e9+7;

ll CrossPrduct(pl a, pl b) {
    return a.first * b.second - a.second * b.first;
}

int PointLocation(pl a, pl b, pl c) {
    ll res = CrossPrduct({c.first-a.first, c.second-a.second}, {c.first-b.first, c.second-b.second});
    if (res > 0) return 1; // LEFT
    else return 0;// right
}

void solve(ll tc) {
    ll n;

    cin >> n;

    vector<bitset<3000>> bt(n);

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
        {
            bt[i][j] = (s[j] == '1');
        }
    }

    ll cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            cnt += (bt[i]&bt[j]).count();
        }
    }

    cout << cnt / 4<< '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    // freopen("triangles.in", "r", stdin   );
    // freopen("triangles.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
