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

const int MODE = 1e9 + 7;

using namespace std;

ll F(vi &pref, vi &X, ll k, ll a, ll b) {
    ll ind = upper_bound(all(X), k) - X.begin()-1;
    
    ll res = a * (ind*k - pref[ind]);
    res += b * (pref.back() - pref[ind] - (X.size()-ind-1)*k);
    return res;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n+1, INT32_MIN);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    sortx(X);
    vi pref(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i-1] + X[i];
    }
    
    ll q; cin >> q;
    while (q--)
    {
        ll a, b; cin >> a >> b;

        ll l = -10;
        ll r = 1e7;
        while (l < r)
        {
            ll mid = (l + r + 1) / 2;
            ll v1 = F(pref, X, mid-1, a, b);
            ll v2 = F(pref, X, mid, a, b);
            
            if (v1 < v2) r = mid-1;
            else l = mid;
        }
        
        cout << F(pref, X, l, a, b) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("dirtraverse.in", "r", stdin);
    // freopen("dirtraverse.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}