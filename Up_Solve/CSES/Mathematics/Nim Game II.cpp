#include "bits/stdc++.h"

#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define ld long double
#define pl pair<ll, ll>
#define vp vector<pl>
#define NO {cout << "NO\n"; return;}
#define YES {cout << "YES\n"; return;}
#define all(X) X.begin(), X.end()

using namespace std;

const int MODE = 1e9+7;


void solve() {
    ll n;

    cin >> n;

    ll v = 0;
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        a %= 4;
        v ^= a;
    }
    
    if (v) cout << "first\n";
    else cout << "second\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
