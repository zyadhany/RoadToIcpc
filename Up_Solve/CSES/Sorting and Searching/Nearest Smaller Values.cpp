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

vi MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vi Z(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second] = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}

void solve(ll tc) {
    ll n;

    cin >> n;

    vi X(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> X[i];    
    
    vi Z = MonomaticStack(X);

    for (int i = 1; i <= n; i++)
        cout << Z[i] << ' ';
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
