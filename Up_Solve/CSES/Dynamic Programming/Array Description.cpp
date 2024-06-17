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

void solve(ll tc) {
    ll n, m, summ;

    cin >> n >> m;

    summ = 0;
    vi X(n);
    vii Z(n, vi(m + 10));

    for (int i = 0; i < n; i++)
        cin >> X[i];

    if (X[0]) Z[0][X[0]] = 1;
    else Z[0] = vi(m + 10, 1);
    Z[0][0] = Z[0][m + 1] = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (X[i])
            Z[i][X[i]] = (Z[i - 1][X[i]] + Z[i - 1][X[i] - 1] + Z[i - 1][X[i] + 1]) % MODE;
        else for (int j = 1; j <= m; j++)
            Z[i][j] = (Z[i - 1][j] + Z[i - 1][j - 1] + Z[i - 1][j + 1]) % MODE;
    }
    
    for (int i = 1; i <= m; i++)
        summ = (summ + Z[n - 1][i]) % MODE;

    cout << summ << '\n';
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
