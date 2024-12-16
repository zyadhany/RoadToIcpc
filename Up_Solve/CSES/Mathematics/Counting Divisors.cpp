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

const int MODE = 1e9 + 9;

using namespace std;

vi prime(1e7 + 10, 0);
vi primes;

void INIT() {
    for (int i = 0; i < prime.size(); i++) prime[i] = i;
    for (int i = 2; i * i <= 1e7; ++i) if (prime[i] == i)
        for (int j = i; j <= 1e7; j += i) prime[j] = i;
    for (int i = 2; i <= 1e7; i++) if(prime[i] == i) primes.push_back(i);
}

void solve(int tc) {
    ll n;

    cin >> n;

    mi X;
    while (n > 1)
    {
        X[prime[n]]++;
        n /= prime[n];
    }

    ll cnt = 1;
    for (auto p : X) cnt *= p.second + 1;  

    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    // freopen("sabotage.in", "r", stdin);
    // freopen("sabotage.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
