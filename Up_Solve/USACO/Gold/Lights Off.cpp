#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 998244353;

ll n, q;

ll cycleft(ll x) {
    ll re = (x & 1);
    x <<= 1;
    if (x & (1<<n)) x ^= (1 << n) ^ 1;
    return x;
}

void solve(ll tc) {
    cin >> q >> n;

    vi rep(1 << n, -1);
    for (int i = 0; i < (1<<n); i++)
    {
        ll j = i;
        while (rep[j]==-1) {
            rep[j]=i;
            j = cycleft(j);
        }
    }
    
    vector<vector<bool>> can(3*n+1, vector<bool>(1<<n));
    can[0][0] = 1;
    ll cur = 0;
    for (int i = 1; i < can.size(); i++)
    {
        cur ^= (1 << ((i-1)%n));
        for (int j = 0; j < (1 << n); j++)
        {
            if (can[i-1][rep[j]]) can[i][rep[j^cur]] = 1;
        }
    }
    
    while (q--)
    {
        string s, t;
        cin >> s >> t;

        ll a = 0, b = 0;
        for (int i = 0; i < n; i++) if (s[i]=='1') a |= (1 << i);
        for (int i = 0; i < n; i++) if (t[i]=='1') b |= (1 << i);
        
        for (int i = 0; i < can.size(); i++)
        {
            if (can[i][rep[a]]) {
                cout << i << '\n';
                break;
            }
            a ^= b;
            b = cycleft(b);
            // cout << i << ' ' << b << "|\n";
        }
    }
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
