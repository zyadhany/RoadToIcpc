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
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, d, h;

    cin >> n >> d >> h;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    sort(X.rbegin(), X.rend());

    ld area = 0.5 * d * h;
    ld res = area;

    for (int i = 1; i < n; i++)
    {
        res += area;
        ld k = X[i] + h - X[i - 1];

        if (k > 0) {
            ld base = (k / h) * d;
            res -= k * base * 0.5;
        }
    }
    
    cout << fixed << setprecision(9) << res << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
