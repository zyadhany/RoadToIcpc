#define _CRT_SECURE_NO_WARNINGS
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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
 
using namespace std;

const ll INF = 1e16;

void solve(int tc) {
    ll n, z;

    cin >> n >> z;

    vi X(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
    }
    
    ll q; cin >> q;

    vector<vp> Q(n+1);
    vi res(q);

    for (int i = 0; i < q; i++)
    {
        ll l, r; cin >> l >> r;
        Q[l].push_back({r, i});
    }

    vi dp(n+1, -INF);

    auto get = [&](ll l, ll r) -> ll {
        if (r < l) return 0;
        ll cnt = 1;
        ll ls = X[l];
        for (int i = i+1; i <= r; i++)
        {
            if 
        }
        
    };

    for (int l = n; l >= 1; l--) {
        ll nx = upper_bound(all(X), X[l] + z) - X.begin();
        if (nx <= n) {
            ll v = 2;
            if (nx > l + 1) v++;
            dp[nx] = max(dp[nx], v-nx);
            cout << nx << ' ' << v-nx << ln;
        }

        for (auto [r, idx] : Q[l]) {
            ll mx = 2;
            if (r == l) {
                res[idx] = 1;
                continue;
            }
            for (int i = l+1; i <= r; i++)
            {
                mx = max(mx, dp[i]+r);
            }

            res[idx] = mx;
        }
    }

    for (auto a :res) cout << a << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}