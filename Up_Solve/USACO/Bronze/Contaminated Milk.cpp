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

void solve(int tc) {
    ll n, m, d, s;

    cin >> n >> m >> d >> s;

    set<ll> st;
    vector<vp> X(n + 1);

    for (int i = 1; i <= m; i++)
        st.insert(i);
    

    while (d--)
    {
        ll p, k, t; cin >> p >> k >> t;
        X[p].push_back({t, k});
    }
    
    for (int i = 1; i <= n; i++)
        sortx(X[i]);
    
    while (s--)
    {
        ll p, t; cin >> p >> t;
        set<ll> tm;
        for (int i = 0; i < X[p].size() && X[p][i].first < t; i++)
            if (st.count(X[p][i].second)) tm.insert(X[p][i].second);         
        st = tm;
    }
    
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        bool isit = 0;
        for (int j = 0; j < X[i].size(); j++)
            if (st.count(X[i][j].second)) isit = 1;
        res += isit;
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
