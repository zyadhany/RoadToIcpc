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


const int MODE = 1e9 + 7;

using namespace std;    


void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n + 1, vi(n + 1));
    vii Y(n * n + 1, {INT32_MAX, INT32_MAX, 0, 0});
    set<ll> vis;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll a; cin >> a;
            X[i][j] = a;
            
            if (a) vis.insert(a);

            Y[a][0] = min(Y[a][0], i);
            Y[a][1] = min(Y[a][1], j);
            Y[a][2] = max(Y[a][2], i);
            Y[a][3] = max(Y[a][3], j);
        }
    }
    
    if (vis.size() == 1) {
        cout << n * n - 1 << '\n';
        return;
    }

    vii pref(n + 10, vi(n + 10));    
    for (int i = 1; i <= n * n; i++)
    {
        ll x1, x2, y1, y2;
        x1 = Y[i][0];
        y1 = Y[i][1];
        x2 = Y[i][2];
        y2 = Y[i][3];
        
        if (x1 == INT32_MAX) continue;
        pref[x1][y1] += 1;
        pref[x2 + 1][y2 + 1] += 1;
        pref[x2 + 1][y1] -= 1;
        pref[x1][y2 + 1] -= 1;
    }

    set<ll> st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (pref[i][j] > 1) st.insert(X[i][j]);
        }
    }
    
    ll sol = n * n - st.size();
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
