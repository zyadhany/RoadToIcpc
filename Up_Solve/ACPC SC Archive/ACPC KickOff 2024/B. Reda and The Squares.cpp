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
const int MAX = (1 << 30) - 1;

ll SQ[1000001];

void solve(ll tc) {
    ll n, l, r, mn;

    cin >> n; 

    mn = INT64_MAX;
    l = 0, r = sqrtl(n) + 1;
    while (l <= r)
    {
        ll re = SQ[l] + SQ[r];
        mn = min(mn, abs(re - n));
        if (re > n) r--;
        else l++;
    }
     
    cout << mn << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    for (ll i = 0; i <= 1e6; i++)
        SQ[i] = i * i;

    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
