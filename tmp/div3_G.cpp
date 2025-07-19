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

vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] +
               table[i + (1 << (j - 1))][j - 1];

    return (table);
}

// optmization to get in O(1)
long long query(vii &table, int L, int R) 
{ 
    int j = (int)log2(R - L + 1); 
    return min (table[L][j], table[R - (1 << j) + 1][j]);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    ll mnv = *min_element(all(X));
    ll mxv = *max_element(all(X));
    auto spt = buildSparseTable(X);

    for (int med = 1; med <= n; med++)
    {
        vi Y(X);
        Y[0] = (Y[0] >= med);
        for (int i = 1; i < n; i++)
            Y[i] = (Y[i] >= med) + Y[i-1]; 
        set<pl> st;
        
        st.insert({0, 0});
        for (int i = 0; i < n; i++)
        {
            /* code */
        }
        
    }
    
    

    cout << sol << '\n';
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
