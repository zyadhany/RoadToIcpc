#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll int
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
 
const int MODE = 998244353;
 
using namespace std;
 
unordered_map<int, int> MC;
int ST(vi &X) {
    int re = 0;
    for (auto a : X) {
        re *= 10;
        re += a;
    }
 
    auto it = MC.find(re);
    if (it == MC.end()) {
        MC[re] = MC.size();
        return MC.size()-1;
    }
    return it->second;
}
 
const int SZ = 362990;
 
vp dd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
void solve(int tc) {
    vi X(9);
    MC.reserve(SZ);
    for (int i = 0; i < 9; i++) cin >> X[i];   
 
    vi Z(9);
    for (int i = 0; i < 9; i++)
        Z[i] = i + 1;
 
    ll en = ST(Z);
    
    vii adj(SZ + 1);
 
    do
    {
        ll v = ST(Z);
        for (int k = 0; k < 9; k++)
        {
            ll i = k / 3, j = k % 3;
            for (auto [x, y] : dd) {
                ll a = x + i;
                ll b = y + j;
                if (a < 0 || b < 0 || a >= 3 || b >= 3) continue;
                ll p = a * 3 + b;
                swap(Z[k], Z[p]);
                ll re = ST(Z);
                adj[v].push_back(re);
                swap(Z[k], Z[p]);
            }
        }
    } while (next_permutation(all(Z)));
    
    vi dp(SZ, INT32_MAX);
    queue<ll> q;
    ll st = ST(X);
    q.push(st);
    dp[st] = 0;
    while (!q.empty())
    {
        ll tp = q.front();
        q.pop();
 
        for (auto neg : adj[tp]) {
            if (dp[neg] > dp[tp] + 1) {
                dp[neg] = dp[tp] + 1;
                q.push(neg);
            }
        }
    }
    
    cout << dp[en] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("atlarge.in", "r", stdin);
    // freopen("atlarge.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
