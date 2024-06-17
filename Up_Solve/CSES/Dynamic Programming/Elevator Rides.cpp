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
 
ll req(vi &Z, vi &X, ll n, ll w) {
    if (n == (1 << X.size()) - 1) return (0);
    ll &ans = Z[n];
    if (~ans) return ans;
    ans = INT32_MAX;
 
    vi Y;
    for (int i = 0; i < X.size(); i++)
        if((n & (1 << i)) == 0) Y.push_back(i);

    //cout <<Y.size() << "|";
    for (int i = 1; i < (1 << Y.size()); i++)
    {
        ll summ = 0;
        ll re = 0;
        for (int j = 0; j < Y.size(); j++)
        {
            if (i & (1 << j)) {
                summ += X[Y[j]];
                re |= (1 << Y[j]);
            }
        }
        if (summ > w) continue;
        ans = min(ans, req(Z, X, n | re, w) + 1);        
    }
    return ans;
}
 
void solve(ll tc) {
    ll n, x;
 
    cin >> n >> x;
 
    vi X(n);
    vector<pair<int, int>> Z(1 << n, {INT32_MAX, INT32_MAX});
    queue<ll> que;
    Z[0] = {1, 0};
    que.push(0);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    while (!que.empty())
    {
        ll m = que.front();
        que.pop();

        for (int i = 0; i < n; i++)
        {
            if (m & (1 << i)) continue;
            ll re = (m | (1 << i));
            pl k = Z[m];
            if (k.second + X[i] <= x) k.second += X[i];
            else k = {k.first + 1, X[i]};
            if (Z[re] == make_pair(INT32_MAX, INT32_MAX)) que.push(re);
            if (Z[re].first > k.first) Z[re] = k;
            else if (Z[re].first == k.first && Z[re].second > k.second) Z[re] = k;
        }
        
    }

    cout << Z[(1 << n) - 1].first << '\n';
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
