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
#define all(X) (X.begin(),X.end());
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;


void solve(int tc) {
    ll m;
    string s;

    cin >> s >> m;

    pl at = {0, 0};
    vi sol(m), X;
    vector<vector<vp>> Z(m, vector<vp>(11, vp(11)));
    
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1') {
            Z[0][i + 1][i + 1] = {-1, 0};
            X.push_back(i + 1);
        }

    for (int pos = 0; pos < m - 1; pos++)
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++)
                if (Z[pos][i][j].first)
                    for (auto a : X)
                        if (a - j > 0 && a != i)
                            Z[pos + 1][a][a - j] = { i, j };

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (Z[m - 1][i][j].first)
                at = {i, j};
    if (!at.first) NO;

    for (int i = m - 1; i >= 0; i--)
    {
        sol[i] = at.first;
        at = Z[i][at.first][at.second];
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++)
        cout << sol[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}