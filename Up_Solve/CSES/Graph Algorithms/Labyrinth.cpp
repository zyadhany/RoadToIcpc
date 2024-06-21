#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void req(vii &vis, vector<string> &X, ll l, ll r) {
    if (l < 0 || r < 0 || l >= vis.size() || r >= vis[0].size()) return;
    if (X[l][r] == '#' || vis[l][r]) return;
    vis[l][r] = 1;
    for (int i = 0; i < dx.size(); i++)
        req(vis, X, dx[i] + l, dy[i] + r);
}

void solve(int tc) {
    ll n, m, summ;
    pl st, en;

    cin >> n >> m;

    summ = 0;
    vector<string> X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (X[i][j] == 'A') st = {i, j};
            if (X[i][j] == 'B') en = {i, j};                        
        }
    }
    
    queue<pl> que;
    vii vis(n, vi(m));
    vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));
    vis[st.first][st.second] = 1;
    que.push(st);

    while (!que.empty())
    {
        auto k = que.front();
        que.pop();
        if (k == en) break;
        for (int i = 0; i < dx.size(); i++)
        {
            ll l = k.first + dx[i];
            ll r = k.second + dy[i];
            if (l < 0 || r < 0 || l >= n || r >= m) continue;
            if (vis[l][r] || X[l][r] == '#') continue;
            vis[l][r] = 1;
            prev[l][r] = k;
            que.push({l, r});
        }
    }
    vc res; 
    pair<int, int> at = en;

    while (at != make_pair(-1, -1))
    {
        auto re = prev[at.first][at.second];
        if (re != make_pair(-1, -1)) {    
            if (re.first == at.first - 1) res.push_back('D');
            else if (re.first == at.first + 1) res.push_back('U');
            else if (re.second == at.second - 1) res.push_back('R');
            else res.push_back('L');
        }
        at = re;
    }

    reverse(all(res));
    if (res.empty()) NO;
    cout << "YES\n";
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << '\n';
}

int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;

		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}
