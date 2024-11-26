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

pl req(vcc &X, vii &vis, ll l, ll r) {
    if (X[l][r] == '.') return {0, 1};
    if (vis[l][r]) return {0, 0};
    vis[l][r] = 1;

    pl sol = {1, 0};
    for (int i = 0; i < dx.size(); i++)
    {
        pl re = req(X, vis, l + dx[i], r + dy[i]);
        sol.first += re.first;
        sol.second += re.second;
    }

    return sol;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vcc X(n + 10, vc(n + 10, '.'));
    vii vis(n + 10, vi(n + 10));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i + 1][j + 1];
    
    pl sol;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j] || X[i][j] == '.') continue;
            pl re = req(X, vis, i, j);
            if (re.first > sol.first) sol = re;
            else if (re.first == sol.first && re.second < sol.second) sol = re;
        }        
    }
    
    cout << sol.first << ' ' << sol.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
