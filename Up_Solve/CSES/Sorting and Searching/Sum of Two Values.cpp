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
    ll n, x;

    cin >> n >> x;

    vi X(n);
    mi Y;

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        Y[X[i]] = i + 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        int re = Y[x - X[i]];

        if (re && re != i + 1) {
            cout << i + 1 << ' ' << re << '\n';
            return;
        }
    }
    
    cout << "IMPOSSIBLE\n";
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