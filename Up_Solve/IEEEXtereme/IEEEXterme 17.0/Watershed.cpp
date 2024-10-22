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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii X(n + 2, vi(m + 2, INT32_MAX));
    priority_queue<pair<ll, pl>> pq;
    vector<vector<ld>> Z(n + 2, vector<ld>(m + 2, 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> X[i][j];
            pq.push({X[i][j], {i, j}});
        }
    }

    ld sol = 0;
    while (!pq.empty())
    {
        ll k = pq.top().first;
        ll l = pq.top().second.first;
        ll r = pq.top().second.second;
        pq.pop();

        vp P;
        for (int i = 0; i < 4; i++)
        {
            ll a = l + dx[i];
            ll b = r + dy[i];
            if (X[a][b] < k) P.push_back({a, b});
        }
        
        if (P.empty()) {
            sol = max(sol, Z[l][r]);
            continue;
        }

        ld amount = Z[l][r] / P.size();
        for (auto re : P) Z[re.first][re.second] += amount;
    }
    
    cout << fixed << setprecision(5) << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("fenceplan.in", "r", stdin);
    //freopen("fenceplan.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
