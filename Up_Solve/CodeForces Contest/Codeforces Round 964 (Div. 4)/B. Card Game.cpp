#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll req(ll a, ll b, ll c, ll d, ll l, ll r) {
    if (a + b + c + d == 0) {
        return (l > r);
    }

    ll res = 0;

    if (a) {
        if (c) res += req(0, b, 0, d, l + (a > c), r + (a < c));
        if (d) res += req(0, b, c, 0, l + (a > d), r + (a < d));
    }

    if (b) {
        if (c) res += req(a, 0, 0, d, l + (b > c), r + (b < c));
        if (d) res += req(a, 0, c, 0, l + (b > d), r + (b < d));
    }
    
    return (res);
}

void solve(int tc) {
    ll a, b, c, d;

    cin >> a >> b >> c >> d;
    
    cout << req(a, b, c, d, 0, 0) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("buckets.in", "r", stdin);
    //freopen("buckets.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
