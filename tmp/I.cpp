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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll a, b;
    cin >> a >> b;

    ll ans = 0;
    for (int x = 1; x <= 1000; x++)
    {
        for (int y = 1; y <= 1000; y++)
        {
            if (x * y - x*a + b *y == 0) {
                cout << x << ' ' << y << " --- IGNORE ---\n";
                ans++;
            }
        }
    }
    cout << ans << "|\n";

    set<pl> res;
    vi divsb;
    for (ll i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            divsb.push_back(i);
            if (i * i != b) {
                divsb.push_back(b / i);
            }
        }
    }
    vi divsa;
    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            divsa.push_back(i);
            if (i * i != a) {
                divsa.push_back(a / i);
            }
        }
    }

    for (auto d : divsb) {
        if (a % (d + 1) == 0) {
            res.insert({a/(d + 1), b/d});
            // cout << a/(d + 1) << ' ' << b/d << " --- IGNORE ---\n";
        }
    }
    // for (auto d : divsa) {
    //     if (d>1 && b % (d - 1) == 0) {
    //         res.insert({a/d, b/(d - 1)});
    //         // cout << a/d << ' ' << b/(d - 1) << " --- IGNORE ---\n";
    //     }
    // }
    cout << res.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("mars.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
