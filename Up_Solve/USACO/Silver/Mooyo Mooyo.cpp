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
    ll n, k;

    cin >> n >> k;

    vector<string> X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    bool ischange;
    do
    {
        ischange = 0;
        vii vis(n, vi(10));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (vis[i][j] || X[i][j] == '0') continue;
                vis[i][j] = 1;
                stack<pl> st;
                vp Z;
                st.push({i, j});
                Z.push_back({i, j});

                while (!st.empty())
                {
                    pl tp = st.top();
                    st.pop();
                    for (int mod = 0; mod < 4; mod++)
                    {
                        ll a = tp.first + dx[mod];
                        ll b = tp.second + dy[mod];

                        if (a < 0 || b < 0 || a >= n || b >= 10) continue;
                        if (vis[a][b] || X[a][b] != X[i][j]) continue;
                        vis[a][b] = 1;
                        st.push({a, b});
                        Z.push_back({a, b});
                    }
                }
                

                if (Z.size() >= k) {
                    ischange = 1;
                    for (auto p : Z)
                        X[p.first][p.second] = '0';
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            vc Y;
            for (int j = n - 1; j >= 0; j--)
            {
                if (X[j][i] != '0') Y.push_back(X[j][i]);
                X[j][i] = '0';
            }
            for (int j = n - 1; n - 1 - j < Y.size(); j--)
                X[j][i] = Y[n - 1 - j];
        }
    } while (ischange);
        
    for (int i = 0; i < n; i++)
        cout << X[i] << '\n';
}  

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
