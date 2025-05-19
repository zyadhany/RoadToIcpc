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
 
const int MODE = 998244353;

ll nor(ll a, ll b, ll k) {
    ll re = 0;
    for (int i = 0; i < k; i++)
    {
        ll l = (a >> i) & 1;
        ll r = (b >> i) & 1;
        if (!l && !r) re |= (1<<i);
    }
    return re;
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n);
    vii IND(k);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        for (int j = 0; j < k; j++)
        {
            if (X[i] & (1<<j)) IND[j].push_back(i);
        }
    }

    vp Y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ll re = upper_bound(all(IND[j]), i) - IND[j].begin() - 1;
            if (re != -1) {
                Y.push_back({IND[j][re], i});
                Y.push_back({IND[j][re]+1, i});
            }
        }
        Y.push_back({i, i});
        Y.push_back({0, i});
    }

}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
  
    // INIT();
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}
