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

ll req(ll l, ll r) {
    if (l == r) return l;

    if (r - l == 1) {
        cout << "? " << 1 << ' ' << l << endl;
        ll a; cin >> a;
        if (a == l) return r;
        else return l;
    }

    if (r - l == 2) {
        cout << "? " << l << ' ' << l + 1 << endl;
        ll a; cin >> a;
        if (a == l * (l + 1)) return l + 2;
        if (a == (l + 1) * (l + 2)) return l;
        if (a == l * (l + 2)) return l + 1;
        while(1);
    }

    ll step = (r - l + 1) / 3;

    ll a = step + l;
    ll b = 2 * step + l;

    cout << "? " << a << ' ' << b << endl;

    ll k; cin >> k;

    if (k == a * b) return (req(b + 1, r));
    if (k == (a * (b + 1))) return req(a + 1, b);
    return req(l, a);
}

void solve(int tc) {
    ll res = req(2, 999);
    cout << "! " << res << endl;
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
