// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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
#define int long long

const int MODE = 1e9+7;

using namespace std;

ld sq3 = 1.732050807568877193176604123437;

void solve(int tc) {
    ll n, k;
    cin >> n >> k;
    
    n /= k;
    n *= k;
    
    ll b = n % 2;
    n /= 2;
    ld v = n;
    if (b) v += 0.5;



    ld an1 = v * sqrt(3);
    ld an2 = v * sqrtl(3);
    ld an3 = v * sq3;
    cout << fixed << setprecision(12) << an1 << '\n';
    // cout << fixed << setprecision(12) << an2 << '\n';
    // cout << fixed << setprecision(12) << an3 << '\n';

}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
