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
 
const int MODE = 998244353;
 
const ll INF = 1e16;

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
    ll n, s; cin >> n >> s;

    vcc X(n + 10, vc(n + 10, 'T'));
    vii ds2(n + 10, vi(n + 10, INF));
    queue<pl> q2;

    pl en, st;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> X[i][j];
            if (X[i][j] == 'M') {
                st = {i, j};
            }
            if (X[i][j] == 'H') {
                ds2[i][j] = 0;
                q2.push({i, j});
            }
            if (X[i][j] == 'D') en = {i, j};
        }
    
    while (!q2.empty()) {
        pl tp = q2.front();
        q2.pop();
        
        for (auto [x,y] : dd) {
            ll a = x + tp.first;
            ll b = y + tp.second;
            ll w = s + ds2[tp.first][tp.second];
            if (ds2[a][b] > w && (X[a][b] == 'G' || X[a][b] == 'M')) {
                ds2[a][b]=w;
                q2.push({a, b});
            }
        }
    }
    
    ll sol = -1;
    ll l = 0, r = n * n;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        
        
        vii dp(n + 10, vi(n + 1, INF));
        if (mid*s < ds2[st.first][st.second]) {
            dp[st.first][st.second] = mid*s;
            queue<pl> q;
            q.push(st);
            while (!q.empty())
            {
                pl tp = q.front();
                q.pop();
                ll v = dp[tp.first][tp.second];
                for (auto [x,y] : dd) {
                    ll a = x + tp.first;
                    ll b = y + tp.second;
                    ll w = v + 1;
                    if (ds2[a][b] > w && dp[a][b] > w && (X[a][b] == 'G' || X[a][b] == 'D')) {
                        dp[a][b] = w;
                        q.push({a, b});
                    }
                }
            }
        }
        
        if (dp[en.first][en.second] != INF) sol = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << sol << '\n';
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