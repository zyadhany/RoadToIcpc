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
vi dy = {0, 0 , 1, -1};

void solve(int tc) {
    ll n, m, k;

    cin >> n >> k >> m;

    vi Z;
    vii vis(n + 1, vi(n + 1));
    vii X(n + 1, vi(n + 1));    
    vector<vii> R(n + 1, vii(n + 1, vi(4)));
    
    for (int i = 0; i < m; i++)
    {
        ll lu, lv, ru, rv;
        cin >> lu >> lv >> ru >> rv;
        ll a = ru - lu;
        ll b = rv - lv;

        ll mod;
        for (int i = 0; i < 4; i++)
            if (a == dx[i] && b == dy[i]) mod = i;
        R[lu][lv][mod] = 1;
        R[ru][rv][mod ^ 1] = 1;
    }
    
    for (int i = 0; i < k; i++)
    {
        ll u, v;
        cin >> u >> v;
        X[u][v] += 1;
    }
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j]) continue;
            
            vis[i][j] = 1;
            stack<pl> st;
            st.push({i, j});
            ll cnt = X[i][j];
            while (!st.empty())
            {
                pl tp = st.top();
                st.pop();
                for (int mod = 0; mod < 4; mod++)
                {
                    ll a = tp.first + dx[mod];
                    ll b = tp.second + dy[mod];
                    if (a <= 0 || b <= 0 || a > n || b > n || vis[a][b]) continue;
                    if (R[tp.first][tp.second][mod]) continue;
                    vis[a][b] = 1;
                    cnt += X[a][b];
                    st.push({a, b});
                }
            }

          Z.push_back(cnt);
        }
    }
    
    ll res = 0;
    for (int i = 0; i < Z.size(); i++)
        for (int j = i + 1; j < Z.size(); j++)
            res += Z[i] * Z[j];    
    cout << res << '\n';
}  

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
