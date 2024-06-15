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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

const int MODE = 1e9 + 7;

// this function checks weather the value (x) exists in the set or not.
bool Exist(ordered_set &s,int x) { 
    if ((s.upper_bound(x))==s.end()) return (0);
    return ((*s.upper_bound(x))==x);
}
 
// this function erases one occurrence of the value (x).
void Erase(ordered_set &s,int x) { 
     if (Exist(s,x)) s.erase(s.upper_bound(x));
}


void solve(ll tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n);
    ordered_set ord;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    for (int i = 0; i < n; i++)
    {
        ord.insert(X[i]);
        if (ord.size() == k) {
            cout << *ord.find_by_order((ord.size() - 1) / 2) << ' ';
            Erase(ord, X[i - k + 1]);
        }
    }
    
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
