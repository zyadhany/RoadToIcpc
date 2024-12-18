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
 
// get vector pair p.first^p.second
vp factorizationCnt(int n) {
    if (n == 1) return {};
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
    return faccnt;
}
 
const int MXN = 2e5 + 1;

void solve(int tc) {
    ll n;

    cin >> n;

    vii Z(MXN);

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        vp Y = factorizationCnt(a);
        for (auto p : Y) Z[p.first].push_back(p.second);
    }
    
    ll sol = 1;
    for (int i = 2; i < Z.size(); i++)
    {
        if (Z[i].size() < n) Z[i].push_back(0);
        if (Z[i].size() < n) Z[i].push_back(0);
        sortx(Z[i]);
        ll re = Z[i][1];
        while (re--) sol *= i;        
    }
    
    cout << sol << '\n';
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