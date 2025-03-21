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
 
const int MODE = 1e9 + 7;
  
using namespace std;

struct hsh {
    size_t operator()(const pl &p) const {
        return p.first * 239 + p.second;
    }
 }; 

void solve(int tc) {
    ll n, x, y;

    cin >> n >> x >> y;

    vp X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }
    
    vector<unordered_map<pl, ll, hsh>> F(n + 1);

    ll md = (n / 2);
    for (int i = 0; i < (1<<md); i++)
    {
        ll cnt = 0, dx = 0, dy = 0;
        for (int j = 0; j < md; j++)
        {
            if (i & (1 << j)) cnt++, dx += X[j].first, dy += X[j].second;
        }
        F[cnt][{dx, dy}]++;
    }
    
    vi res(n + 1);

    for (int i = 0; i < (1 << (n - md)); i++)
    {
        ll cnt, dx, dy;
        cnt = dx = dy = 0;
        for (int j = 0; j < (n - md); j++)
        {
            if (i & (1 << j)) cnt++, dx += X[j + md].first, dy += X[j + md].second;
        }
        
        ll nx = x-dx, ny = y-dy;
        for (int i = 0; i <= md; i++)
        {
            auto it = F[i].find({nx, ny});
            if (it != F[i].end()) res[i+cnt] += it->second;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}   
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
