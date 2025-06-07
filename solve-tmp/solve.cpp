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
using namespace std;

const int MODE = 998244353;

// a_1 * x + b_1 = a_2 * x + b_2
ll intersect(pl a, pl b) {
    ll a1 = a.first, b1 = a.second;
    ll a2 = b.first, b2 = b.second;
    if (a1 == a2) throw runtime_error("Parallel lines");
    ld x = (ld)(b2 - b1) / (a1 - a2);
    return ceil(x);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n, vi(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> X[i][j];
        }
    }
    sortx(X);
    
    deque<pair<ll, pl>> dq;
    dq.push_back({-1, {0, 0}});
    vi dp(n);

    for (int i = 0; i < n; i++)
    {        
        ll x = X[i][0], y = X[i][1], a = X[i][2];
        while (y < dq.back().first) dq.pop_back();
        dp[i] =x*y-a + dq.back().second.first * y + dq.back().second.second;
        pl line = {-x ,dp[i]};
        while (true)
        {
            ll inter = intersect(line, dq.front().second);
            if (inter <= -1) break;
            if (dq.size() == 1) {
                dq.front().first = inter;
                dq.push_front({-1, line});
                break;
            }
            ll nx = dq[1].first;
            if (nx <= inter) {
                dq.pop_front();
                continue;
            }
            dq.front().first = inter;
            dq.push_front({-1, line});
            break;
        }        
     }
    
    cout << *max_element(all(dp)) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("cownav.in", "r", stdin);
    // freopen("cownav.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}