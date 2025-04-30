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

const int MODE = 1e9 + 7;

using namespace std;

const int INF = 1e6;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vcc X(n + 10, vc(m + 10, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i+1][j+1];
        }
    }

    vii Z(n + 10, vi(m + 10));
    ll at = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i][j] != 'X' || Z[i][j]) continue;
            at++;
            stack<pl> st;
            st.push({i, j});
            while (!st.empty())
            {
                auto [x, y] = st.top();
                st.pop();
                Z[x][y] = at;
                for (int md = 0; md < 4; md++)
                {
                    ll nx = dx[md] + x;
                    ll ny = dy[md] + y;
                    if (X[nx][ny] == 'X' && !Z[nx][ny]) {
                        Z[nx][ny] = at;
                        st.push({nx, ny});
                    }
                }
            }
        }
    }
    


    ll k = at;
    vii adj(k, vi(k, INF));
    for (int i = 0; i < k; i++)
    {
        vii dis(n+10, vi(m+10, INF));
        deque<pl> que;
        
        for (int j = 1; j <= n; j++)
        {
            for (int h = 1; h <= m; h++)
            {
                if (Z[j][h] == i + 1) {
                    que.push_back({j, h});
                    dis[j][h] = 0;
                }
            }
        }
        
        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop_front();
        
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (X[nx][ny] == '.') continue;
                bool sw = (X[nx][ny] == 'S');
                ll nw = dis[x][y] + sw;
                if (dis[nx][ny] <= nw) continue;
                
                if (sw) que.push_back({nx, ny});
                else que.push_front({nx, ny});
                dis[nx][ny] = nw;
            }
        }

        for (int j = 1; j <= n; j++)
        {
            for (int h = 1; h <= m; h++)
            {
                if (Z[j][h]) {
                    adj[i][Z[j][h]-1] = min(adj[i][Z[j][h]-1], dis[j][h]);
                }
            }
        }
    }
    
    vii dp(1<<k, vi(k, INF));
    for (int i = 0; i < k; i++)
    {
        dp[1<<i][i] = 0;
    }
    for (int i = 1; i < (1<<k); i++)
    {
        if (__builtin_popcount(i) == 1) continue;
        for (int j = 0; j < k; j++)
        {
            if (i & (1<<j)) {
                ll sub = (i ^ (1<<j));
                for (int h = 0; h < k; h++)
                {
                    if (sub & (1 << h)) {
                        dp[i][j] = min(dp[i][j], dp[sub][h] + adj[h][j]);
                    }
                }
            }
        }
    }    

    cout << *min_element(all(dp[(1<<k)-1])) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("island.in", "r", stdin);
    freopen("island.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}