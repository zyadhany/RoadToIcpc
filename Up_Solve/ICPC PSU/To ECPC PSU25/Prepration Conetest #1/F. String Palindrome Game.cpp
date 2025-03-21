#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    string s;

    cin >> s;

    vii Z(n);

    // get all odd plandrom
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= min(i, n - i - 1); j++)
        {
            if (s[i-j]!=s[i+j]) break;
            Z[i-j].push_back(j*2+1);
        }
    }
    
    // get all even plandrom
    for (ll i = 0; i < n-1; i++)
    {
        for (ll j = 0; j <= min(i, n - i - 1); j++)
        {
            if (s[i-j]!=s[i+j+1]) break;
            Z[i-j].push_back((j+1)*2);
        }
    }

    for (int i = 0; i < n; i++)
    {
        sortx(Z[i]);
    }
    
    while (q--)
    {
        ll l, r; cin >> l >> r;
        l--, r--;

        ll mx = 0;
        for (int i = l; i <= r; i++)
        {
            ll nd = r - i + 1;
            ll re = upper_bound(all(Z[i]), nd) - Z[i].begin();
            if (re) mx = max(mx, Z[i][re-1]);
        }
        
        cout << mx << '\n';
    }
}   
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
