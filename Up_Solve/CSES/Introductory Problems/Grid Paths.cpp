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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;

ll req(vii &vis, string &s, ll at, ll l, ll r) {
    if (vis[l][r]) return (0);
    if (l == 7 && r == 1) return (at == 48);
    if (vis[l - 1][r] && vis[l + 1][r] && !vis[l][r - 1] && !vis[l][r + 1]) return (0);
    if (!vis[l - 1][r] && !vis[l + 1][r] && vis[l][r - 1] && vis[l][r + 1]) return (0);
    if (vis[l - 1][r + 1] && !vis[l - 1][r] && !vis[l][r + 1]) return (0);
    if (vis[l + 1][r + 1] && !vis[l + 1][r] && !vis[l][r + 1]) return (0);
    if (vis[l + 1][r - 1] && !vis[l + 1][r] && !vis[l][r - 1]) return (0);
    if (vis[l - 1][r - 1] && !vis[l - 1][r] && !vis[l][r - 1]) return (0);
    vis[l][r] = 1;

    ll summ = 0;

    if (s[at] == '?') {
        summ += req(vis, s, at + 1, l + 1, r);
        summ += req(vis, s, at + 1, l - 1, r);
        summ += req(vis, s, at + 1, l, r + 1);
        summ += req(vis, s, at + 1, l, r - 1);
    }else if (s[at] == 'U') {
        summ += req(vis, s, at + 1, l - 1, r);
    } else if (s[at] == 'D') {
        summ += req(vis, s, at + 1, l + 1, r);
    } else if (s[at] == 'R') {
        summ += req(vis, s, at + 1, l, r + 1);
    } else if (s[at] == 'L'){
        summ += req(vis, s, at + 1, l, r - 1);
    }

    vis[l][r] = 0;
    return (summ);
}

void solve(ll tc) {
    string s;

    cin >> s;

    vii vis(10, vi(10));
    for (int i = 0; i <= 8; i++)
        vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = 1;
    
    cout << req(vis, s, 0, 1, 1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
