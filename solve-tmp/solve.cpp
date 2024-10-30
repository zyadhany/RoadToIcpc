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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void req(vector<vp> &Y, vp &X, vi &visy, vi &visx, vi &res, pl k) {
    if (visy[k.second] || visx[k.first]) return;
    visy[k.second] = 1;
    visx[k.first] = 1;
    res.push_back(k.first);
    for (auto neg : Y[k.second]) {
        req(Y, X, visy, visx, res, neg);
    }
}

vi getres(vector<vp> &Y, vp &X){
    ll n = X.size() - 1;
    ll m = Y.size() - 1;
    vi res;
    vi visy(m + 1);
    vi visx(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (visy[X[i].first] || visx[i]) continue;
        if (Y[X[i].second].size() == 1 &&  Y[X[i].first].size() != 1) continue;
        req(Y, X, visy, visx, res, {i, X[i].first});
    }
    for (int i = 1; i <= n; i++)
        req(Y, X, visy, visx, res, {i, X[i].first});
    for (int i = 1; i <= n; i++)
        req(Y, X, visy, visx, res, {i, X[i].second});

    return {res};
}

void solve(int tc) {
    ll n, m;
    
    cin >> n >> m;

    vp X(n + 1);
    vector<vp> Y(m + 1);

    for (int i = 1; i <= n; i++)
    {
        ll u, v; cin >> u >> v;
        X[i] = {u, v};
        Y[u].push_back({i, v});
        Y[v].push_back({i, u});
    }
    
    vi L = getres(Y, X);
    for (int i = 1; i <= n; i++)
        swap(X[i].first, X[i].second);
    vi R = getres(Y, X);
    reverse(all(R));

    vi res;
    if (L.size() >= R.size()) res = L;
    else res = R;

    set<ll> st(all(res));
    ll cnt = n - st.size();
    for (int i = 1; i <= n; i++)
        if (!st.count(i)) res.push_back(i);

    cout << cnt << '\n';
    for (auto x : res) cout << x << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
