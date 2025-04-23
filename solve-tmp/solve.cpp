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

const int MXN = 1e6+10;

void solve(int tc) {
    ll n, m;
    cin >> n >> m;
    vii X(n, vi(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string s; cin >> s;
            pl at = {i, j};
            for (auto c : s) {
                if (c == 'N') at.first--;
                else if (c == 'S') at.first++;
                else if (c == 'E') at.second++;
                else if (c == 'W') at.second--;  
            }
            X[i][j] = at.first * m + at.second;
        }
    }
    
    vii SPT(n*m, vi(30));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            SPT[i*m + j][0] = X[i][j];
        }
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 0; i < n*m; i++)
        {
            SPT[i][j] = SPT[SPT[i][j-1]][j-1];
        }
    }

    ll q; cin >> q;
    while (q--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        x--; y--;
        ll at = x * m + y;
        for (int j = 0; j < 32; j++)
        {
            if (k & (1 << j)) {
                at = SPT[at][j];
            }
        }
        ll ans_x = at / m;
        ll ans_y = at % m;
        cout << ans_x + 1 << " " << ans_y + 1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}