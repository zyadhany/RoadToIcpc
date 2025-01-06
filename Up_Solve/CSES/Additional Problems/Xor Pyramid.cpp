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

const int MODE = 1e9 + 7;

using namespace std;

ll cnt2fact(ll n) {
    ll cnt = 0;
    while (n)
    {
        n /= 2;
        cnt += n;
    }
    return cnt;
}

void solve(int tc) {
    ll n;

    cin >> n;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        ll a = cnt2fact(n - 1);
        ll b = cnt2fact(i);
        ll c = cnt2fact(n-1-i);
        if (a == b + c) res ^= x;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // INIT();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
