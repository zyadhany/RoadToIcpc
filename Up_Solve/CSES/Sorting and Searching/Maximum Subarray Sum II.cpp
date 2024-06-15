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

vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = max(table[i][j - 1],
               table[i + (1 << (j - 1))][j - 1]);

    return (table);
}

// optmization to get in O(1)
long long query(vii &table, int L, int R) 
{ 
    int j = (int)log2(R - L + 1); 
    return max(table[L][j], table[R - (1 << j) + 1][j]);
}

void solve(ll tc) {
    ll n, a, b, l, r, summ, mx;

    cin >> n >> a >> b;

    mx = INT64_MIN;
    vi X(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        X[i] += X[i - 1];
    }
    
    auto Z = buildSparseTable(X);

    for (int i = 1; i <= n - a + 1; i++)
    {
        ll re = query(Z, i + a - 1, min(n, i + b - 1));
        re -= X[i - 1];
        mx = max(mx, re);
    }
    
    cout << mx << '\n';
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
