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
 
// Return Twice the area of polygon, make sure to divide by 2
ll AreaOfPolygon(vp &X) {
    ll area = 0;
    for (int i = 0; i < X.size(); i++) {
        area += X[i].first * X[(i + 1) % X.size()].second - X[i].second * X[(i + 1) % X.size()].first;
    }
    return abs(area); // 2 * area;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pl cntLatticePoints(vp &X) {
    ll area = AreaOfPolygon(X);
    ll B = 0;
    for (int i = 0; i < X.size(); i++)
    {
        B += gcd(abs(X[i].first - X[(i + 1) % X.size()].first), abs(X[i].second - X[(i + 1) % X.size()].second));   
    }
    ll I = (area - B + 2) / 2;
    return {I, B};
}

void solve(ll tc) {
    ll n;
    cin >> n;

    vp X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }
    
    pl re = cntLatticePoints(X);
    cout << re.first << ' ' << re.second << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
