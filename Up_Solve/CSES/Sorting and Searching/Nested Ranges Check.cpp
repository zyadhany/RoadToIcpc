#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
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
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
 
// macros to define set 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
 
void solve(ll tc) {
    ll n, mx, mn;

    cin >> n;

    mx = 0;
    mn = INT32_MAX;
    vector<pair<pl, ll>> X(n);
    priority_queue<pl> pq;
    vi L(n), R(n);
    
    for (int i = 0; i < n; i++){
        cin >> X[i].first.first >> X[i].first.second;
        X[i].first.second *= -1;
        X[i].second = i;
    }
    sortx(X);

    for (int i = n - 1; i >= 0; i--)
    {
        X[i].first.second *= -1;
        if (X[i].first.second >= mn) L[X[i].second] = 1;
        mn = min(mn, X[i].first.second);
    }

    for (int i = 0; i < n; i++)
    {
        if (X[i].first.second <= mx) R[X[i].second] = 1;
        mx = max(mx, X[i].first.second);
    }

    for (int i = 0; i < n; i++)
        cout << L[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << R[i] << ' ';
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
