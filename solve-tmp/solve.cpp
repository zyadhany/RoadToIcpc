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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

// macros to define set 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

void solve(int tc) {
    ll n;

    cin >> n;

    ordered_set ord;

    while (n--)
    {
        char c; ll k; cin >> c >> k;

        if (c == "I") ord.insert(k);
        else if (c == "D") {
            if (ord.count(k)) ord.erase(k);
        } else if (c == "K") cout << *ord.find_by_order(k-1) << '\n';
        else cout << ord.order_of_key(k) + 1 << '\n';
    }
    
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}