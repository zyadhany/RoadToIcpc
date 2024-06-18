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
    ll n, q;

    cin >> n >> q;

    vcc X(n + 1, vc(n + 1));
    vii Z(n + 1, vi(n + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> X[i][j];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Z[i][j] = (X[i][j] == '*');
            Z[i][j] += Z[i - 1][j] + Z[i][j - 1];
            Z[i][j] -= Z[i - 1][j - 1];            
        }
    }
    
    while (q--)
    {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        if (lx > rx) swap(lx, rx);
        if (ly > ry) swap(ly, ry);

        cout << Z[rx][ry] - Z[rx][ly - 1]
                -Z[lx - 1][ry] + Z[lx - 1][ly - 1] << '\n';
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
