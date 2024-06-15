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

void solve(ll tc) {
    ll n, k, summ;

    cin >> n >> k;

    summ = 0;
    vp X(n);

    multiset<ll> st;

    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;
    sortx(X);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && *st.begin() <= X[i].first)
            st.erase(st.begin());

        if (st.size() < k) {
            summ++;
            st.insert(X[i].second);
            continue;
        }

        if (*st.rbegin() > X[i].second) {
            st.insert(X[i].second);
            st.erase(--st.end());
        }
    }
        
    cout << summ << '\n';
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
