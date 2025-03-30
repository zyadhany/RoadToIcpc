#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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

ll CrossPrduct(pl a, pl b) {
    return a.first * b.second - a.second * b.first;
}

// 1(LEFT), 0(TOUCH), -1(RIGHT)
int PointLocation(pl a, pl b, pl c) {
    ll res = CrossPrduct({c.first-a.first, c.second-a.second}, {c.first-b.first, c.second-b.second});
    if (res > 0) return 1; // LEFT
    else if (res < 0) return -1; // RIGHT
    return 0; // TOUCH
}

void solve(ll tc) {
    pl a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

    ll pos = PointLocation(a, b, c);
    if (pos == 0) cout << "TOUCH\n";
    else if (pos > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
