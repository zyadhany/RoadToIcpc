#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
using namespace std;
 
const int MODE = 998244353;
const int MXN = 2e5+10, MXL = 20; 

 
void solve(ll tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        X.push_back(X[i]);
    }
    
    for (int i = 1; i < X.size(); i++)
    {
        X[i] += X[i-1];
    }
    
    ll pw = log2(n) + 1;
    vector<vp> SPT(n, vp(pw+1));
    for (int i = 0; i < n; i++)
    {
        ll v = k; if (i) v += X[i-1];
        ll re = upper_bound(all(X), v) - X.begin();
        SPT[i][0] = {re % n, re - i};
    }
    
    for (int j = 1; j <= pw; j++)
        for (int i = 0; i < n; i++) {
            SPT[i][j].first = SPT[SPT[i][j-1].first][j-1].first;
            SPT[i][j].second = SPT[SPT[i][j-1].first][j-1].second + SPT[i][j-1].second;
        }

    ll mn = n;
    
    for (int i = 0; i < n; i++)
    {
        ll st = 0;
        ll len = 0;
        ll at = i;
        for (int j = pw; j >= 0; j--)
        {
            if (SPT[at][j].second +len  >= n) mn = min(mn, st + (1 << j));
            else  st += (1 << j), len += SPT[at][j].second, at = SPT[at][j].first;
        }
    }
    
    cout << mn << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
