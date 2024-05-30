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

typedef ll item;


item Spmarge(item a, item b) {
    if (b == 0) return (a);
    return (Spmarge(b, a % b));
}

vector<vector<item>> buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vector<vector<item>> table(n, vector<item>(m + 1));
    for (int i = 0; i < n; i++){
        table[i][0] = X[i];
    }
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = Spmarge(table[i][j - 1], 
                        table[i + (1 << (j - 1))][j - 1]);

    return (table);
}
 
// Returns the sum of range L and R, 0-index.
item query(vector<vector<item>> &table, int L, int R)
{
    // int j = (int)log2(R - L + 1); 
    // return Spmarge(table[L][j], table[R - (1 << j) + 1][j]);

    int m = table[0].size() - 1;
    item answer = item();
    for (int j = m; j >= 0; j--) {
        if (L + (1 << j) - 1 <= R) {
            answer = Spmarge(answer, table[L][j]);
            L += 1 << j;
        }
    }
    return answer;
}

void req(vii &Z, mi &Y, ll a, ll b){
    ll g, l, r, at;

    l = b, r = Z.size() - 1;
    if (b > r) return;
    g = query(Z, a, b);
    while (l < r)
    {
        at = (l + r + 1) / 2;
        if (query(Z, a, at) == g) l = at;
        else r = at - 1;
    }

    Y[g] += l - b + 1;
    req(Z, Y, a, l + 1);
}

void solve(int tc) {
<<<<<<< HEAD
    ll n, q;
=======
    ll n, mn;
    string s;
>>>>>>> 9e4143b8634f4fabb3d6049a61eba0c5f9335767

    cin >> s;

<<<<<<< HEAD
    vi X(n);
    mi Y;
=======
    n = s.size();

    vii X(n + 1, vi(n + 1, INT32_MAX));

    X[0][n - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (s[i] == s[j]) X[i + 1][j - 1] = min(X[i + 1][j - 1], X[i][j]);
            else
            {
                X[i + 1][j] = min(X[i + 1][j], X[i][j] + 1);
                X[i][j - 1] = min(X[i][j - 1], X[i][j] + 1);
            }
            
        }
    }
    
    mn = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j) mn = min(mn, X[i][j]);
        }
        
    }
    
    cout << mn << '\n';
}
>>>>>>> 9e4143b8634f4fabb3d6049a61eba0c5f9335767

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    vii Z = buildSparseTable(X);
    for (int i = 0; i < n; i++)
        req(Z, Y, i, i);
    

    cin >> q;
    while (q--)
    {   ll l;
        cin >> l;
        cout << Y[l] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

<<<<<<< HEAD
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
=======
    cin >> size;
>>>>>>> 9e4143b8634f4fabb3d6049a61eba0c5f9335767
    for (int i = 1; i <= size; i++)
        solve(i);
}
