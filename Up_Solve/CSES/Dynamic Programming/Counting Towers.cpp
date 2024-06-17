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
 
using namespace std;
 
const int MODE = 1e9 + 7;
 
void solve(ll tc) {
    ll n, q, summ, p, summpw;
 
    summpw = 0;
    p = 1, summ = 1;
    vi Z(1e6 + 1);
 
    Z[0] = 1;
    for (int i = 1; i < Z.size(); i++)
    {
        Z[i] = ((p * p) % MODE + summ) % MODE;
        p = (p * 2) % MODE;
        summpw = (summpw * 4 + Z[i - 1]) % MODE;
        summ = (summ + summpw + Z[i]) % MODE;
    }
    
    cin >> q;
    while (q--)
    {
        cin >> n;
        cout << Z[n] << '\n';
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
