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
    ll n, m, k, summ;

    cin >> n >> m >> k;

    summ = 0;
    vi X(n), Y(m);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 0; i < m; i++)
        cin >> Y[i];
    sortx(X); sortx(Y);

    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (Y[j] < X[i] - k) {
            j++;
            continue;
        }

        if (Y[j] > X[i] + k) {
            i++;
            continue;
        }

        summ++;
        i++; j++;
    }
    
    cout << summ << '\n';
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
