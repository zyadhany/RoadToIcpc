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

bool isplc(vector<string> &X, ll l1, ll r1, ll l2, ll r2) {
    vi freq(26);
    vii vis(X.size(), vi(X.size()));
    for (int i = l1; i <= l2; i++)
    {
        for (int j = r1; j <= r2; j++)
        {
            if (vis[i][j]) continue;
            // cout << i << ' ' << j << ' ' << vis[i][j] << "||\n";
            vis[i][j] = 1;
            freq[X[i][j] - 'A']++;
            stack<pl> st;
            st.push({i, j});
            while (!st.empty())
            {
                pl tp = st.top();
                st.pop();
                for (int mod = 0; mod < 4; mod++)
                {
                    ll a = tp.first + dx[mod];
                    ll b = tp.second + dy[mod];
                    if (a < l1 || a > l2 || b < r1 || b > r2 || vis[a][b] || X[a][b] != X[i][j]) continue;
                    vis[a][b] = 1;
                    st.push({a, b});
                }
            }
        }
    }
    
    ll col, onereg, morereg;
    col = onereg = morereg = 0;
    for (auto c : freq) {
        col += (c != 0);
        onereg += (c == 1);
        morereg += (c > 1);
    }

    return (col == 2 && onereg && morereg);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vector<string> X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    vector<pair<pl, pl>> Z;
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            for (int a = 0; a <= n - i; a++)
            {
                for (int b = 0; b <= n - j; b++)
                {
                    pl st = {a, b};
                    pl en = {a + i - 1, b + j - 1};
                    if (!isplc(X, st.first, st.second, en.first, en.second)) continue;
                    Z.push_back({st, en});
                }
            }
        }
    }
    
    ll sol = 0;
    for (auto [st, en] : Z) {
        bool isit = 1;
        for (auto [s, e] : Z) {
            if (s == st && e == en) continue;
            isit &= (s.first > st.first || s.second > st.second) 
            || (e.first < en.first || e.second < en.second);
        }
        sol += isit;
    }

    cout << sol << '\n';
}  

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
