#include "bits/stdc++.h"
#define ll long long
#define vi vector<ll>
#define pl pair<ll, ll>
#define vp vector<pl>
#define vii vector<vi>
using namespace std;
#define ln "\n"

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

/*
By adding a '#' between each character we can find all palindromes of even length and odd length.

d[2*i] = 2*d[i] + 1 (even length)
d[2*i+1] = 2*d[i] (odd length)
*/
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    for (auto &a : res) a--;
    return vector<int>(begin(res) + 1, end(res));
}

void solve() {
    ll n;
    string s;
    cin >> s;

    n = s.size();
    auto man = manacher(s);

    vi res(n);
    vi prf(n);
    for (int i = 0; i < n; i++)
    {
        ll len = man[i*2]/2;
        prf[i+len] = max(len, prf[i+len]);
    }
    
    ll mx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        mx = max(mx, prf[i]);
        res[i] = mx*2 + 1;
        mx--;
    }

    prf.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        ll len = man[i*2+1]/2;
        prf[i+len] = max(len, prf[i+len]);
    }
    
    mx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        mx = max(mx, prf[i]);
        res[i] = max(res[i], mx*2);
        mx--;
    }

    for (auto a : res) cout << a << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // freopen("puzzle.in", "r", stdin);
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
