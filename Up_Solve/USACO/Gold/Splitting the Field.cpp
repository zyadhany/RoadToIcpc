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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}


const int MODE = 998244353;

using namespace std;    

ll req(vp &X) {
    ll n = X.size();

    vii L(n);
    vii R(n);

    L[0] = {X[0].first, X[0].first, X[0].second, X[0].second};
    R[n - 1] = {X[n - 1].first, X[n - 1].first, X[n - 1].second, X[n - 1].second};

    for (int i = 1; i < n; i++)
    {
        L[i] = L[i - 1];
        L[i][0] = min(L[i][0], X[i].first);
        L[i][1] = max(L[i][1], X[i].first);
        L[i][2] = min(L[i][2], X[i].second);
        L[i][3] = max(L[i][3], X[i].second);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        R[i] = R[i + 1];
        R[i][0] = min(R[i][0], X[i].first);
        R[i][1] = max(R[i][1], X[i].first);
        R[i][2] = min(R[i][2], X[i].second);
        R[i][3] = max(R[i][3], X[i].second);
    }
    
    ll mn = INT64_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        ll l = (L[i][1] - L[i][0]) * (L[i][3] - L[i][2]);
        ll r = (R[i + 1][1] - R[i + 1][0]) * (R[i + 1][3] - R[i + 1][2]);
        mn = min(mn, l + r);
    }
    
    return mn;
}

bool comp(pl &a, pl &b) {
    return a.second < b.second;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vp X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;
    
    if (n == 1) {
        cout << "1\n";
        return;
    }

    sort(X.begin(), X.end());    
    
    ll mn = req(X);

    sort(X.begin(), X.end(), comp);

    mn = min(mn, req(X));

    ll xl, xr, yl, yr;
    xr = yr = 0;
    xl = yl = INT32_MAX;

    for (auto p : X) {
        xl = min(xl, p.first);
        xr = max(xr, p.first);
        yl = min(yl, p.second);
        yr = max(yr, p.second);
    }
    
    ll summ = (xr - xl) * (yr - yl);

    cout << summ - mn << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
