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

void req(vii &Y, vi &Z, set<ll> &st, ll n, ll p) {
    ll at = 1;
    for (auto neg : Y[n]) {
        if (neg == p) continue;
        while (at == Z[n] || at == Z[p]) at++;
        Z[neg] = at;
        st.insert(at);
        at++;
        req(Y, Z, st, neg, n);
    }
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi Z(n + 1, 0);
    vii Y(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }
    
    set<ll> st;

    Z[1] = 1;
    st.insert(1);
    req(Y, Z, st, 1, 0);

    cout << st.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
