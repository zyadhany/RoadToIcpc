#define _CRT_SECURE_NO_WARNINGS
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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi prime(1e7 + 10, 0);
vi mxprime(5e6 + 10, 0);
vi cntlo(5e6 + 10, 0);
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

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    
    ll mn = INT32_MAX;
    ll ind = -1;

    for (int i = 0; i < n; i++)
        if ((cntlo[X[i]] + 1) / 2 < mn) mn = (cntlo[X[i]] + 1) / 2, ind = i;
    
    if (X[ind] % 4) cout << "Farmer John\n";
    else cout << "Farmer Nhoj\n";    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    vi MXR(4);
    for (int i = 0; i < cntlo.size(); i++)
    {
        if (i % 4 == 0) cntlo[i] = i / 2 + 1;
        else {
            if (prime[i] == i) MXR[i % 4] = i;
            cntlo[i] = 1 + cntlo[i - MXR[i  % 4]];
        }
    }

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
