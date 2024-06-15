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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;


void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    set<int> interval;
    multiset<int> len;
    
    interval.insert(0);
    interval.insert(n);
    len.insert(n);
    
    while (q--)
    {
        int a; cin >> a;
        int l, r;

        auto it = interval.upper_bound(a);
        
        r = *it;
        it--; l = *it;
        interval.insert(a);

        len.erase(len.find(r - l));
        len.insert(a - l);
        len.insert(r - a);

        auto tt = len.end(); tt--;
        cout << *tt << ' ';
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
