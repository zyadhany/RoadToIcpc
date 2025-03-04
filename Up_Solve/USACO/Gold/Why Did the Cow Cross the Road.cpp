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
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vii X(n, vi(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];

    vector<vii> dp(n, vii(n, vi(3, INT64_MAX)));
    dp[0][0][0] = 0;
    priority_queue<pair<pl, pl>, vector<pair<pl, pl>>, greater<>> pq;
    pq.push({{0,0}, {0,0}});

    while (!pq.empty())
    {
        ll c = pq.top().first.first;
        ll md = pq.top().first.second;
        auto [l, r] = pq.top().second;
        pq.pop();
        if (c != dp[l][r][md]) continue;

        for (int i = 0; i < 4; i++)
        {
            ll x = l + dx[i];
            ll y = r + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            ll nm = (md+1)%3;
            ll nc = X[x][y] * (nm == 0) + k + c;
            if (nc < dp[x][y][nm]) {
                dp[x][y][nm] = nc;
                pq.push({{nc, nm}, {x, y}});
            }
        }        
    }
    

    cout << *min_element(all(dp[n-1][n-1])) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}