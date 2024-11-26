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

const int SZ = 4e3 + 10;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
mc dir = {
    {'E', 0},
    {'W', 1},
    {'N', 2},
    {'S', 3}
};

pl st, en;
void req(vector<vector<bool>> &vis, vector<vector<bool>> &fan, ll l, ll r) {
    if (l < st.first || r < st.second || l > en.first || r > en.second) return;
    for (int i = 0; i < 4; i++)
    {
        ll a = l + dx[i];
        ll b = r + dy[i];
        if (vis[a][b] || fan[a][b]) continue;
        vis[a][b] = 1;
        req(vis, fan, a, b);
    }
}

void solve(int tc) {
    ll n;
    string s;

    cin >> n;
    cin >> s;

    st = en = {2000, 2000};

    ll cnt = 0;
    vector<vector<bool>> vis(SZ, vector<bool>(SZ));
    vector<vector<bool>> fan(SZ, vector<bool>(SZ));

    pl at = st;
    for (int i = 0; i < n; i++)
    {
        int mod = dir[s[i]];
        fan[at.first][at.second] = 1;
        at.first += dx[mod];
        at.second += dy[mod];
        fan[at.first][at.second] = 1;
        at.first += dx[mod];
        at.second += dy[mod];

        st.first = min(st.first, at.first);
        st.second = min(st.second, at.second);
        en.first = max(en.first, at.first);
        en.second = max(en.second, at.second);
    }

    st.first--; st.second--;
    en.first++; en.second++; 
    for (int i = st.first; i <= en.first; i++)
    {
        for (int j = st.second; j <= en.second; j++)
        {
            if (vis[i][j] || fan[i][j]) continue;
            cnt++;
            req(vis, fan, i, j);
        }
    }

    cout << cnt - 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
