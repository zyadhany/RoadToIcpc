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
    ll n, mx;

    cin >> n;

    mx = 0;
    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        mx += X[i];
    }
    
    vi Z(mx + 1, 0);
    Z[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = Z.size() - 1 - X[i]; j >= 0; j--)
            Z[j + X[i]] |= Z[j];

    ll res = 0;
    for (int i = 1; i < Z.size(); i++)
        res += Z[i];
    cout << res << '\n';
    for (int i = 1; i < Z.size(); i++)
        if (Z[i]) cout << i << ' ';
    cout << '\n';
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
