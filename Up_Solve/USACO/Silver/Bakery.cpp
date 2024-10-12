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
    ll n, Tc, Tm;

    cin >> n >> Tc >> Tm;

    vii X(n, vi(3));

    for (int i = 0; i < n; i++)
        cin >> X[i][0] >> X[i][1] >> X[i][2];

    ll lw = 0, hi = Tc + Tm - 2;
    while (lw < hi)
    {
        ll mid = (lw + hi) / 2;
        bool isit = 1;

        ll mn = max(1ll, Tc - mid);
        ll mx = min(Tc, Tc + Tm - mid - 1);

        for (int i = 0; i < n; i++)
        {
            ll a, b, c;
            a = X[i][0], b = X[i][1], c = X[i][2];

            // a * x + b * y <= c
            // x + y == tc + tm - mid
            // y = -x + tc + tm - mid
            // x (a - b) <= c - b * (tc + tm - mid)

            ll d = Tc + Tm - mid;
            if (a > b) mx = min(mx, (c - b * d) / (a - b));
            else if (b > a) mn = max(mn, (-c + b * d + b - a - 1) / (b - a));
            else if (b * d > c) isit = 0;
        }
        
        if (mx < mn) isit = 0;

        if (isit) hi = mid;
        else lw = mid + 1;
    }
    
    cout << lw << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("socdist.in", "r", stdin);
    //freopen("socdist.out", "w", stdout);
    
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
