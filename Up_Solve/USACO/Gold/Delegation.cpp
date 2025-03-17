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

ll req(vii &adj, vi &dp, ll n, ll p, ll k) {
    mi Y;
    ll re = 0;
    for (auto neg : adj[n]) if (neg != p) {
        ll a = req(adj, dp, neg, n, k);
        if (!a) return 0;
        if (dp[neg]+1==k) continue;
        Y[dp[neg]+1]++;
    }
    
    for (auto &p : Y) {
        while (p.second && Y[k-p.first])
        {
            if (p.first == k-p.first) {
                p.second %= 2;
                break;
            }
            Y[k-p.first]--;
            p.second--;
        }
        
        if (p.second) {
            if (re || p.second > 1) return 0;
            re = p.first;
        }
    }
    dp[n] = re;
    return 1;
}

void solve(int tc) {
    ll n;

    cin >> n;
    
    vii adj(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi res(n + 1);
    for (int i = 1; i < n; i++)
    {
        if ((n - 1) % i) continue;
        vi dp(n + 1);
        ll re = req(adj, dp, 1, 0, i);
        res[i] = (re && dp[1] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        cout << res[i];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}