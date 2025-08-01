#include "bits/stdc++.h"
#define ll long long
#define vi vector<ll>
#define pl pair<ll, ll>
#define vp vector<pl>
#define vii vector<vi>
#define all(X) X.begin(), X.end()
using namespace std;
#define ln "\n"

vector<int> suffixarray(string &s) {
    s += '$';
    int n = s.size();
    vector<int> suff(n), P(n);
    vector<pair<int, int>> V(n);
    for (int i = 0; i < n; i++) suff[i]=i, V[i] = {s[i], s[i]};
    
    auto comp = [&](int i, int j) {
        if (V[i].first != V[j].first) return V[i].first < V[j].first;
        return V[i].second < V[j].second;
    };
    sort(all(suff), comp);
    
    vector<int> tmp(n), frq(n), C(n);
    for (int k = 1; k < n; k*=2)
    {
        C[0] = frq[0] = P[suff[0]] = 0;
        for (int i = 1; i < n; i++) P[suff[i]] = P[suff[i-1]] + (V[suff[i]] != V[suff[i-1]]), frq[i] = 0;
        for (int i = 0; i < n; i++) V[i] = {P[i], P[(i+k)%n]}, suff[i] = (suff[i] - k + n) % n, frq[P[i]]++;
        for (int i = 1; i < n; i++) C[i] = C[i-1] + frq[i-1];
        for (int i = 0; i < n; i++) tmp[C[V[suff[i]].first]] = suff[i], C[V[suff[i]].first]++;
        swap(suff, tmp);
    }

    return suff;
}

pair<vi, vi> LCP(vector<int> &suff, string &s) {
    ll n = s.size();
    vi ind(n), lcp(n-1); // -1 for $ char
    for (int i = 0; i < n; i++) ind[suff[i]] = i;
    
    int ls = 0;
    for (int i = 0; i < n-1; i++)
    {
        int prv = suff[ind[i]-1];
        while (s[i+ls]==s[prv+ls])ls++;
        lcp[ind[i]-1] = ls, ls = max(0, ls-1);
    }
    
    return {lcp, ind};
}

void solve() {
    ll n;
    string s;
    cin >> s;

    n = s.size();
    ll sol = n * (n + 1) / 2;
    auto suff = suffixarray(s);
    auto P = LCP(suff, s).first;
    for (auto a : P) sol -= a;
    cout << sol << '\n';
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
