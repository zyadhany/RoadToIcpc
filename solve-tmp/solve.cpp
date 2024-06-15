#include <vector>
#include <iostream>

 
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

vi prime(1e6 + 10, 0);
vi primes;

void INIT() {
    for (int i = 0; i < prime.size(); i++) prime[i] = i;
    for (int i = 2; i * i <= 1e6; ++i) if (prime[i] == i)
        for (int j = i; j <= 1e6; j += i) prime[j] = i;
    for (int i = 2; i <= 1e6; i++) if(prime[i] == i) primes.push_back(i);
}

ll BigMODE(string &s, ll k) {
    ll summ = 0;
    for (int i = 0; i < s.size(); i++)
        summ = ((summ * 10) + s[i] - '0') % k;    
    return (summ);
}

void solve(string s, ll n) {
    for (int i = 0; i < primes.size() && primes[i] < n; i++)
    {
        if (BigMODE(s, primes[i]) == 0) {
            cout << "BAD " << primes[i] << '\n';
            return;
        }
    }
    
    cout << "GOOD\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int size = 1;

    INIT();

    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        string s; ll n;
        while (cin >> s >> n)
        {
            if (s == "0" && !n) break;
            solve(s, n);
        }
        
        //solve(tc);
       // if (tc != size) cout << '\n';
    }
    return (0);
}
