#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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
 
const int MODE = 1e9+7;
const ll inf = 1e16; 

using namespace std;

ll fpow(ll x, ll y) {
    ll res = 1;
    x %= MODE;
    while (y > 0) {
        if (y & 1) res = (res * x) % MODE;
        x = (x * x) % MODE;
        y >>= 1;
    }
    return res;
}

void solve(int tc) {
    ll n;

    cin >> n;

    ll cnt, summ, prod, pcnt;
    cnt = summ = prod = pcnt = 1;

    while (n--)
    {
        ll x, k; cin >> x >> k;
        
        ll p = (((k * (k + 1) / 2) % (MODE - 1)) * pcnt) % (MODE - 1);
        prod = fpow(prod, k + 1);
        prod = (prod * fpow(x, p)) % MODE; 
        
        cnt = (cnt * (k + 1)) % MODE;
        pcnt = (pcnt * (k + 1)) % (MODE - 1);

        ll tp = ((fpow(x, k + 1) - 1)%MODE+MODE)%MODE;
        tp *= fpow(x - 1, MODE - 2);
        tp %= MODE;
        
        summ = (summ * tp) % MODE;
    }
    
    cout << cnt << ' ' << summ << ' ' << prod << '\n';
} 

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    // freopen("sumdiv.in", "r", stdin);
    // freopen("sumdiv.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
