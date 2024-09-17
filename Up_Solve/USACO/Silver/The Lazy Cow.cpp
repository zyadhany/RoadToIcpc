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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vii ConverDiamondToMatix(vii &X) {
    ll n = X.size();
    vii Z(n * 2 + 1, vi(2 * n + 1));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Z[i + j][n - i + j - 1] = X[i][j];
    return Z;    
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vii X(n + 1, vi(n + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> X[i][j];

    vii Z = ConverDiamondToMatix(X);

    for (int i = 1; i < Z.size(); i++)
        for (int j = 1; j < Z[i].size(); j++)
            Z[i][j] += Z[i - 1][j] + Z[i][j - 1] - Z[i - 1][j - 1];

    ll mx = 0;
    ll sz = Z.size() - 1;
    k = min(sz, k * 2 + 1);
    for (int i = k; i < Z.size(); i++)
    {
        for (int j = k; j < Z[i].size(); j++)
        {
            ll summ = Z[i][j] - Z[i - k][j] - Z[i][j - k] + Z[i - k][j - k];
            mx = max(mx, summ);            
        }
    }

    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
