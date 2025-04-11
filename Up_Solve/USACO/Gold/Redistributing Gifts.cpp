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

void solve(ll tc) {
    ll n;

    cin >> n;

    vi adj(n);

    for (int i = 0; i < n; i++)
    {
        vi X(n);
        for (int j = 0; j < n; j++)
        {
            cin >> X[j]; X[j]--;
        }
        
        for (int j = 0; j < n; j++)
        {
            adj[i] |= (1 << X[j]);
            if (X[j] == i) break;
        }
    }

    vi ans(1 << n);
    vii dp(1 << n, vi(n));

    ans[0] = 1;
    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;  
    
    for (int i = 0; i < n; i++)
    {
        for (int mask = 1<<i; mask < (1 << i+1); mask++)
        {
            for (int ls = 0; ls <= i; ls++)
                if (mask & (1 << ls)) { 
                    ll v = dp[mask][ls];
                    for (int k = 0; k < i; k++)
                        if(!(mask & (1 << k)) && (adj[ls] & (1 << k))) {
                            dp[mask ^ (1 << k)][k] += v;
                        }
                    
                    if (adj[ls] & (1 << i)) ans[mask] += v; 
                }      

            // new cycle
            for (int j = i + 1; j < n; j++)
                dp[mask^(1<<j)][j] += ans[mask];
        }
        
    }
    
    ll q; cin >> q;
    while (q--)
    {
        string s; cin >> s;
        ll l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'H') l ^= (1 << i);
            else r ^= (1 << i);
        }

        cout << ans[l] * ans[r] << '\n';
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
