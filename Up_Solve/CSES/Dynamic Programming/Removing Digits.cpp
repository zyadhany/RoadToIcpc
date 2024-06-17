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
    ll n;

    cin >> n;
    
    vi X(n + 1, INT32_MAX);

    X[n] = 0;
    for (int i = n; i > 0; i--)
    {
        ll re = i;
        while (re)
        {
            X[i - re % 10] = min(X[i - re % 10], X[i] + 1);
            re /= 10;
        }
        
    }
    
    cout << X[0] << '\n';
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
