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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

// macros to define set 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


void solve(int tc) {
    ll n;

    cin >> n;

    ordered_set L, R;
    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        R.insert(X[i]);
    }
    
    ll sol = 0;
    for (int i = 0; i < n; i++)
    {
        R.erase(X[i]);
        ll l = L.size() - L.order_of_key(X[i]);
        ll r = R.size() - R.order_of_key(X[i]);
        L.insert(X[i]);
        
        if (max(l, r) > 2 * min(l, r)) sol++;
    }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
