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
    ll n, l, r, summ, re, x;
    
    cin >> n >> x;
 
    summ = 0;
    l = n / 2; r = l + n % 2;
    vi X(n);
    unordered_map<ll, int> Y;
    Y.reserve(1<<(l));
 
    for (int i = 0; i < n; i++)
        cin >> X[i];
 
    for (int i = 0; i < (1 << l); i++)
    {
        re = 0;
        for (int j = 0; j < l; j++)
            if (i & (1 << j)) re += X[j];
        Y[re]++; 
    }
    
    for (int i = 0; i < (1 << r); i++)
    {
        re = 0;
        for (int j = l; j < n; j++)
            if (i & (1 << (j - l))) re += X[j];
        if(re <= x && Y.find(x - re) != Y.end())
            summ += Y[x - re];
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
