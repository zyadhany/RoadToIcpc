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

    vi X(n + 1);
    unordered_map<int, vi> Y;
    Y.reserve(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        Y[X[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ll re = x - X[i] - X[j];
            if (re < 0 || Y.find(re) == Y.end()) continue;
            for (auto &m : Y[re]) {
                if (m != i && m != j) {
                    cout << i << ' ' << j << ' ' << m << '\n';
                    return;
                }
            }
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
