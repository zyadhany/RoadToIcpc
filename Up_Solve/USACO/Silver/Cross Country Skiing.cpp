#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<int, int>
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

const int MODE = 1e9;

using namespace std;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii X(n + 10, vi(m + 10, 1e12));
    vii Z(n + 10, vi(m + 10));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i + 1][j + 1];
        }
    }

    pl st = {n, m};
    ll num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Z[i + 1][j + 1];
            num += Z[i + 1][j + 1];
            if (Z[i + 1][j + 1]) st = {i + 1, j + 1};
        }
    }
    
    ll l = 0, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 1;

        vii vis(n + 10, vi(m + 10));
        vis[st.first][st.second] = 1;
        stack<pl> stak;
        stak.push(st);
        while(!stak.empty()) {
            pl p = stak.top();
            stak.pop();

            for (int i = 0; i < 4; i++)
            {
                ll a = p.first + dx[i];
                ll b = p.second + dy[i];
                if (vis[a][b] || abs(X[a][b] - X[p.first][p.second]) > mid) continue;
                vis[a][b] = 1;
                stak.push({a, b});
                cnt += Z[a][b];
            }
        }

        if (cnt >= num) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("ccski.in", "r", stdin);
    // freopen("ccski.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
