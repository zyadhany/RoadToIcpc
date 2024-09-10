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

ll req(set<pl> &X, set<pl> &Y, ll cnt) {
    if (cnt == 0) {
        ll x1, x2, y1, y2;
        
        x1 = X.begin()->first;
        y1 = Y.begin()->first;

        auto it = X.end();
        it--;
        x2 = it->first;

        it = Y.end();
        it--;
        y2 = it->first;

        return (x2 - x1) * (y2 - y1);
    }

    ll mn = INT32_MAX;
    pl l, r;

    l = *X.begin();
    r = {l.second, l.first};
    X.erase(l);
    Y.erase(r);
    mn = req(X, Y, cnt - 1);
    X.insert(l);
    Y.insert(r);

    r = *Y.begin();
    l = {r.second, r.first};
    X.erase(l);
    Y.erase(r);
    mn = min(mn, req(X, Y, cnt - 1));
    X.insert(l);
    Y.insert(r);

    auto it = X.end();
    it --;
    l = *it;
    r = {l.second, l.first};
    X.erase(l);
    Y.erase(r);
    mn = min(mn, req(X, Y, cnt - 1));
    X.insert(l);
    Y.insert(r);

    it = Y.end();
    it--;
    r = *it;
    l = {r.second, r.first};
    X.erase(l);
    Y.erase(r);
    mn = min(mn, req(X, Y, cnt - 1));
    X.insert(l);
    Y.insert(r);

    return mn;
}

void solve(int tc) {
    ll n;

    cin >> n;

    set<pl> X, Y;    

    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        X.insert({a, b});
        Y.insert({b, a});
    }

    cout << req(X, Y, 3);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
