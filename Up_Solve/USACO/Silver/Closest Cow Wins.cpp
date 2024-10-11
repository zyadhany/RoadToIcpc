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

ll getpos(vp &X, ll k) {
    pl tm = {k, 0};
    return lower_bound(all(X), tm) - X.begin();
}

void solve(int tc) {
    ll k, m, n;

    cin >> k >> m >> n;

    vp X(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> X[i].first >> X[i].second;
    sortx(X);
    for (int i = 1; i <= k; i++) X[i].second += X[i - 1].second;
    
    vi Y(m);
    for (int i = 0; i < m; i++)
        cin >> Y[i];
    sortx(Y);    

    vi res;

    ll ind;
    ind = getpos(X, Y[0]) - 1;
    res.push_back(X[ind].second);
    ind = getpos(X, Y.back());
    res.push_back(X.back().second - X[ind - 1].second);

    for (int i = 0; i < m - 1; i++)
    {
        ll a, b;
        pl tm;
        
        a = getpos(X, Y[i]);
        b = getpos(X, Y[i + 1]) - 1;
                
        if (a > b) continue;
    
        ll all, mx = 0;
        all = X[b].second - X[a - 1].second;

        for (int j = a; j <= b; j++)
        {
            ll at = 2 * X[j].first - Y[i];
            ll lst = at + (Y[i + 1] - at + 1) / 2;
            lst = min(lst, Y[i + 1]);
            ll re = getpos(X, lst) - 1;
            mx = max(mx, X[re].second - X[j - 1].second);
        }

        res.push_back(all - mx);
        res.push_back(mx);
    }
    
    sort(res.rbegin(), res.rend());
    ll sol = 0;
    for (int i = 0; i < res.size() && i < n; i++)
        sol += res[i];
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("berries.in", "r", stdin);
    //freopen("berries.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
