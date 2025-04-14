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
    vp X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }
    
    vector<vector<bitset<300>>> bt(n, vector<bitset<300>>(n, bitset<300>()));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && i != k && j != k)
                bt[i][j][k] = PointLocation(X[i], X[j], X[k]);
            }
        }
    }

    vi res(n-2);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                vector<int> t = {i, j, k};
                if (!PointLocation(X[t[0]], X[t[1]], X[t[2]])) swap(t[1], t[2]);
				auto z = bt[t[0]][t[1]] & bt[t[1]][t[2]] & bt[t[2]][t[0]];
				res[z.count()]++;
            }
        }
    }

    for (int i = 0; i < n-2; i++)
    {
        cout << res[i] << '\n';
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    freopen("triangles.in", "r", stdin   );
    freopen("triangles.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
