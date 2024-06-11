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
    ll q, n, at, k;

    cin >> q;

    k = 1;
    at = 1;
    vi X(1);
    vp Z(1);

    X.push_back(1);
    Z.push_back({1, 9});

    for (int i = 1; i <= 18; i++)
    {
        at += (k * 9) * i;
        k *= 10;
        X.push_back(at);
        Z.push_back({k, k * 10 - 1});
    }
    
    while (q--)
    {
        cin >> n;
        int re = upper_bound(all(X), n) - X.begin() - 1;
        n -= X[re];
        
        ll l, r;
        l = n / re;
        r = n % re;

        ll res = Z[re].first + l;
        string s = to_string(res);
        cout << s[r] << '\n';
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
