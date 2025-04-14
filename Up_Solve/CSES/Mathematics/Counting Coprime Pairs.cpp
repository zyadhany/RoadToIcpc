#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 998244353;

const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
vi primes;
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
    for (int i = 2; i < MAXSZ; i++) if(prime[i] == i) primes.push_back(i);
}
vi PF(ll n) {
    vi X;

    while (n > 1)
    {
        if (X.empty() || X.back() != prime[n])
            X.push_back(prime[n]);
        n /= prime[n];
    }
    
    return (X);
}

ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}


void solve(ll tc) {
    ll n;

    cin >> n;

    ll sol = 0;
    vi freq(1e6+10);

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        auto P = PF(a);
        
        for (int j = 0; j < (1<<P.size()); j++)
        {
            ll pc = __builtin_popcount(j);
            ll re = 1;

            for (int h = 0; h < P.size(); h++) if (j & (1 << h)) {
                re *= P[h];
            } 
            
            if (pc % 2) sol -= freq[re];
            else sol += freq[re];
            freq[re]++;
        }
    }
    
    cout << sol << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   
    INIT();
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
