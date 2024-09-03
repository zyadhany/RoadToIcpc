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

struct cow
{
    ll x;
    ll y;
    ll ind;
};

void solve(int tc) {
    ll n;

    cin >> n;

    vector<cow> N, E;
    vi Z(n, INT32_MAX);

    for (int i = 0; i < n; i++) {
        char c; ll l, r;
        cin >> c >> l >> r;
        if (c == 'N') N.push_back({l, r, i});
        else E.push_back({l, r, i});
    }
    sort(N.begin(), N.end(),
	     [&](const cow &c1, const cow &c2) { return c1.x < c2.x; });
    sort(E.begin(), E.end(),
	     [&](const cow &c1, const cow &c2) { return c1.y < c2.y; });


    for (auto l : N) for (auto r : E) {
        if (l.y >= r.y || r.x >= l.x || Z[r.ind] != INT32_MAX) continue;
        ll a = r.y - l.y;
        ll b = l.x - r.x;

        if (a < b) {
            Z[r.ind] = b;
        }

        if (a > b) {
            Z[l.ind] = a;
            break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (Z[i] == INT32_MAX) cout << "Infinity\n";
        else cout << Z[i] << '\n';
    } 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
