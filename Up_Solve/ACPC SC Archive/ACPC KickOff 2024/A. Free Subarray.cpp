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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 
const int MODE = 1e9 + 7;
const int MAX = (1 << 30) - 1;

vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = (table[i][j - 1] &
               table[i + (1 << (j - 1))][j - 1]);

    return (table);
}
 

// optmization to get in O(1)
long long query(vii &table, int L, int R) 
{ 
    if (L > R) return (MAX);
    int j = (int)log2(R - L + 1); 
    return (table[L][j] & table[R - (1 << j) + 1][j]);
}

void solve(ll tc) {
    ll n, q;

    cin >> n;

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];

    auto Z = buildSparseTable(X);    

    cin >> q;
    while (q--)
    {
        ll L, R, l, r, at, a, b;
        cin >> L >> R;
        L--, R--;

        ll k = query(Z, L, R);

        l = L, r = R;
        while (l < r)
        {
            at = (l + r) / 2;
            ll re = query(Z, L, at);
            if (re == k) r = at;
            else l = at + 1;
        }
        b = l;
        
        l = L, r = b;
        while (l < r)
        {
            at = (l + r + 1) / 2;
            ll re = query(Z, at, b);
            if (re == k) l = at;
            else r = at - 1;
        }
        a = l;

        l = query(Z, 0, a - 1);
        r = query(Z, b + 1, n - 1);
        l &= r;
        if (l == MAX) l = 0;
        if (l == k) cout << "YES\n";
        else cout << "NO\n";
    }
    
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
