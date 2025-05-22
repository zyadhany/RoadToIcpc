#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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
using namespace std;
 
const int MODE = 1e9+7;

vi suffixarray(string &s) {
    s += '$';
    ll n = s.size();
    vi suff(n), P(n);
    vp V(n);
    for (int i = 0; i < n; i++) suff[i]=i, V[i] = {s[i]-'a', s[i]-'a'};
    
    auto comp = [&](int i, int j) {
        if (V[i].first != V[j].first) return V[i].first < V[j].first;
        return V[i].second < V[j].second;
    };
    sort(all(suff), comp);
    
    vi tmp(n), frq(n), C(n);
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

void solve(int tc) {
    string s; cin >> s;

    auto X = suffixarray(s);

    ll q; cin >> q;
    while (q--)
    {
        string t; cin >> t;
        ll l = 0, r = X.size()-1;
        ll st = 0;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            int comp;

            ll ls = 0;
            while (ls < t.size() && s[X[mid]+ls]==t[ls])ls++;

            
            if (ls == t.size()) comp = 0;
            else if (t[ls] < s[X[mid]+ls]) comp = -1;
            else comp = 1;

            if (comp == 0) st = mid;
            if (comp > 0) l = mid + 1;
            else r = mid - 1;
        }
        
        l = 0, r = X.size()-1;
        ll en = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            int comp;

            ll ls = 0;
            while (ls < t.size() && s[X[mid]+ls]==t[ls])ls++;
            
            if (ls == t.size()) comp = 0;
            else if (t[ls] < s[X[mid]+ls]) comp = -1;
            else comp = 1;

            if (comp == 0) en = mid;
            if (comp >= 0) l = mid + 1;
            else r = mid - 1;
        }

        cout << en - st + 1 << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
  
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
