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

ll MXN = 1e6+1;

void solve(int tc) {
    ll n, a, b;

    cin >> a >> b >> n;

    ll l = 0, r = 2e18;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        ll cnt = mid / b + 1;
        cnt += max(0ll, (mid - a) / b);
        if (cnt >= n) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}   
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
