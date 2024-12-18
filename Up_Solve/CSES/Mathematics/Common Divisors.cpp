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
 
const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
}
 
void divsorFactors(vp &faccnt, vi &div, int at, int d) {
    if (at == faccnt.size()) {div.push_back(d); return;}
    divsorFactors(faccnt, div, at + 1, d);
    for (int i = 0; i < faccnt[at].second; i++)
    {
        d *= faccnt[at].first;
        divsorFactors(faccnt, div, at + 1, d);
    }
}
 
vi divsors(int n) {
    if (n == 1) return {1};
    vi fac;
    while(n > 1) fac.push_back(prime[n]), n /= prime[n];
    vp faccnt;
    pl re = {fac[0], 1};
    for (int i = 1; i < fac.size(); i++)
    {
        if (fac[i] == re.first) re.second++;
        else faccnt.push_back(re), re = {fac[i], 1};
    }
    faccnt.push_back(re);
    vi div;
    divsorFactors(faccnt, div, 0, 1);
    return div;
}
 
const int MXN = 1e6 + 1;
int vis[MXN] = {0};

void solve(int tc) {
    ll n;
 
    cin >> n;
  
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        vi div = divsors(a);
        for (int d : div) vis[d]++;
    }
 
    for (int i = MXN - 1; i >= 0; i--)
        if (vis[i] >= 2) {
            cout << i << '\n';
            return;
        }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    INIT();
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}