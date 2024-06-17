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
    ll n, m;
    string s, t;

    cin >> s >> t;

    n = s.size(), m = t.size();
    vii Z(n + 1, vi(m + 1, INT32_MAX));

    for (int i = 0; i <= m; i++)
        Z[0][i] = i;        

    for (int i = 1; i <= n; i++)
    {
        Z[i][0] = i;
        for (int j = 1; j <= m; j++)
            Z[i][j] = min(Z[i - 1][j - 1] + (s[i - 1] != t[j - 1]),
                        min(Z[i - 1][j], Z[i][j - 1]) + 1);
    }
    
    cout << Z[n][m] << '\n';
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
