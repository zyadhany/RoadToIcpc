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

vi X, res, dub;
vii Y;

pair<pl, set<ll>> req(ll n, ll p) {
    ll mx = X[n];
    ll sz = 1;

    set<ll> st;
    st.insert(X[n]);

    for (auto neg : Y[n]) {
        if (neg == p) continue;
        auto k = req(neg, n);
        
        if (k.second.size() > st.size()) swap(st, k.second);

        dub[n] |= dub[neg];
        for (auto a : k.second) {
            if (st.count(a)) dub[n] = 1;
            st.insert(a);
        }

        pl re = k.first;
        sz += re.first;
        mx = max(mx, re.second);
    }

    if (dub[n]) res[n] = 0;
    if (mx != sz) res[n] = 0;
    return {{sz, mx}, st};
}

void solve(int tc) {
    ll n;

    cin >> n;

    X.resize(n + 1);
    res.assign(n + 1, 1);
    dub.assign(n + 1, 0);
    Y.resize(n + 1);

    for (int i = 0; i < n; i++)
        cin >> X[i + 1];

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }

    req(1, 0);

    for (int i = 1; i <= n; i++)
        if (res[i]) cout << "YES\n";
        else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("meetings.in", "r", stdin);
    //freopen("meetings.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
