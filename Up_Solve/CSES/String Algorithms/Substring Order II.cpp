#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<int>
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
 
vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1],
               table[i + (1 << (j - 1))][j - 1]);
 
    return (table);
}
 
// optmization to get in O(1)
long long query(vii &table, int L, int R) 
{ 
    if (L > R) return INT32_MAX;
    int j = (int)log2(R - L + 1); 
    return min (table[L][j], table[R - (1 << j) + 1][j]);
}
 
void solve(int tc) {
    ll n;
    string s;
    
    cin >> s;
    n = s.size();
 
    auto suff = suffixarray(s);
    auto lcp = LCP(suff, s).first;
    auto spt = buildSparseTable(lcp);
    ll k; cin >> k;
    string res = "";
     
    auto get = [&](ll x) {
        if (!x) return 0ll;
        ll summ = 0;
        for (int i = 0; i < x; i++)
        {
            summ += n - suff[i];
        }

        int j;
        ll r = n;
        for (j = 1;  ; j++)
        {
            if (lcp[x] < j) break;
            ll l = x+1;
            while (l<r)
            {
                ll mid = (l+r+1)>>1;
                if (query(spt, x, mid-1) >= j) l = mid;
                else r = mid-1;
            }
            summ += l - x + 1;
        }
        summ += n - suff[x] - (j-1);       
        return summ;
    };

    ll l = 0, r = n-1;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        ll f = get(mid);
        if (f >= k) r = mid - 1;
        else l = mid;
    }
    k -= get(l);

    ll x = l+1;
    int j;
    for (j = lcp[x-1]+1;  ; j++)
    {
        if (x==n || lcp[x] < j) break;
        l = x+1, r = n;
        while (l<r)
        {
            ll mid = (l+r+1)>>1;
            if (query(spt, x, mid-1) >= j) l = mid;
            else r = mid-1;
        }
        ll cnt = l - x + 1;
        k -= cnt;
        if (k <= 0) {
            res = s.substr(suff[l], j);
            break;
        }    
    }
    if (res.empty()) res = s.substr(suff[x], k+j-1);

    cout << res << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}