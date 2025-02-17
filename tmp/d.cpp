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

ll fpow(ll x, ll y) {
    ll res = 1;
    x %= MODE;
    while (y > 0) {
        if (y & 1) res = (res * x) % MODE;
        x = (x * x) % MODE;
        y >>= 1;
    }
    return res;
}

ll modinv(ll x) {
    return fpow(x, MODE - 2);
}

void solve(int tc) {
    ll n, x, b;

    cin >> n >> x >> b;

    ll sol = 0;

    sol = 1 + b - (((n*n)%MODE+2*n+1)%MODE * fpow(b, n))%MODE + ((n*n + n)%MODE * fpow(b, n+1))%MODE;
    sol %= MODE;
    sol *= modinv(fpow((1-b+MODE)%MODE, 3));
    sol %= MODE;

    cout << sol << '\n';
    sol = (sol * x) % MODE;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("exercise.in", "r", stdin);
    // freopen("exercise.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
