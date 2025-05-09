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

ll inver(vi &X) {
    ll sol = 0;
    ordered_set ord;
    for (auto a : X) {
        sol += ord.size() - ord.order_of_key(a);
        ord.insert(a);
    }
    return sol;
}

void solve(int tc) {
    ll n;

    cin >> n;
    vi X(n), Y(n), Z(n);

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a; a--;
        Y[a] = i;
    }
    
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a; a--;
        X[Y[a]] = i;
        Z[i] = Y[a];
    }
    
    ll st = inver(X);
    ll inv = st;
    ll mn = st;

    for (int i = n-1; i >= 0; i--)
    {
        inv += X[i];
        inv -= n - 1 - X[i];
        mn = min(mn, inv);
    }
    inv = st;
    for (int i = 0; i < n; i++)
    {
        inv -= Z[i];
        inv += n - 1 - Z[i];
        mn = min(mn, inv);
    }
    
    cout << mn << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
