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
    ll n, k;

    cin >> n >> k;

    mi X;
    vii Y(n, vi(3));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> Y[i][j];
    sortx(Y);

    multiset<ll> st;
    for (int i = 0; i < n; i++)
        st.insert(0);
    
    ll res = 0;
    for (auto &Q : Y) {
        ll ind = Q[1];
        ll val = Q[2];
        
        ll mx = *prev(st.end());
        ll cnt = st.count(mx);
        ll prevx = X[ind];
        st.erase(st.find(X[ind]));
    
        X[ind] += val;
        st.insert(X[ind]);
        ll nmx = *prev(st.end());
        ll ncnt = st.count(nmx);

        if (prevx == mx && cnt == 1) res += (nmx != X[ind] || ncnt != 1);        
        else res += (nmx != mx || ncnt != cnt);
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
