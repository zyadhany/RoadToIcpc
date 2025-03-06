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

using namespace std;

vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

void solve(int tc) {
    ll n, xl, yl, xe, ye;
    cin >> n >> xl >> yl >> xe >> ye;

    n++;
    vp X(n + 1);

    X[0] = {xl, yl};
    X[n] = {xe, ye};
    for (int i = 1; i < n; i++)
        cin >> X[i].first >> X[i].second;

    vector<map<ll, vp>> Z(2);
    for (int i = 0; i <= n; i++)
    {
        Z[0][X[i].first].push_back({X[i].second, i});
        Z[1][X[i].second].push_back({X[i].first, i});
    }
    
    for (int i = 0; i < 2; i++)
        for (auto &[a, b] : Z[i]) sortx(b);    

    deque<pl> q;
    q.push_back({0, 0});
    q.push_back({0, 1});
    vii dp(n + 1, vi(2, INT32_MAX));
    dp[0][0] = dp[0][1] = 0;

    while (!q.empty())
    {
        auto [tp, d] = q.front();
        q.pop_front();

        for (int i = 0; i < 2; i++)
        {
            ll a = X[tp].first;
            ll b = X[tp].second;
            if (i) swap(a, b);

            ll w = (i ^ d);
            ll nw = w + dp[tp][d];

            vp &Y = Z[i][a];
            ll re = lower_bound(all(Y), pl(b, tp)) - Y.begin();
            if (re) {
                ll v = Y[re-1].second;
                if (dp[v][i] > nw) {
                    dp[v][i] = nw;
                    if (w) q.push_back({v, i});
                    else q.push_front({v, i});
                }
            }

            if (re < Y.size() - 1) {
                ll v = Y[re+1].second;
                
                if (dp[v][i] > nw) {
                    dp[v][i] = nw;
                    if (w) q.push_back({v, i});
                    else q.push_front({v, i});
                }
            }
        }
    }
    

    ll sol = min(dp[n][0], dp[n][1]);
    if (sol == INT32_MAX) cout << "-1\n";
    else cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
