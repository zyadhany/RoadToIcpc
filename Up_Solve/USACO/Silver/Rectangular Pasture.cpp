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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

// macros to define set 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


const int MODE = 1e9 + 7;

using namespace std;    

void solve(int tc) {
    ll n;
    
    cin >> n;

    vp X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;
    sortx(X);

    ll sol = 1;

    for (int i = 0; i < n; i++)
    {
        ordered_set ord;
        for (int j = 0; j <= i; j++)
            ord.insert(X[j].second);
        
        for (int j = 0; j <= i; j++) {
            ll l, r;

            l = X[i].second;
            r = X[j].second;

            if (l > r) swap(l, r);

            ll a, b;
            a = ord.order_of_key(l) + 1;
            b = i - j - ord.order_of_key(r) + 1;
            sol += a * b;

            ord.erase(X[j].second);
        }
    }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
