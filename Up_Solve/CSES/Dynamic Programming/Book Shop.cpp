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
    ll n, k;

    cin >> n >> k;
    
    vp X(n);
    vi Z(k + 1, -1);

    for (int i = 0; i < n; i++)
        cin >> X[i].first;
    for (int i = 0; i < n; i++)
        cin >> X[i].second;
    
    Z[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = k - X[i].first; j >= 0; j--)
        {
            if (Z[j] != -1) {
                Z[j + X[i].first] = max(Z[j + X[i].first], Z[j] + X[i].second);
                Z[j + X[i].first] %= MODE;
            }
        }        
    }
    
    cout << *max_element(all(Z)) << '\n';
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
