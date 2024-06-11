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
    ll n, mn, l, r;

    cin >> n;

    vi X(n);
    bitset<20> bt;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    mn = INT64_MAX;

    for (int i = 0; i < (1 << n); i++)
    {
        bt = i;
        l = r = 0;
        for (int j = 0; j < n; j++)
        {
            if (bt[j]) l += X[j];
            else r += X[j];
        }
        mn = min(mn, abs(l - r));
    }
    
    cout << mn << '\n';
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
