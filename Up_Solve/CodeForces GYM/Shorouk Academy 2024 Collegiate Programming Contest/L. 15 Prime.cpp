#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vi primeFactors(int n)
{
    vi X;

    while (n % 2 == 0)
    {
        X.push_back(2);
        n = n / 2;
    }
    
    for (int i = 3; i * i<= n; i = i + 2)
    {
        while (n % i == 0)
        {
            X.push_back(i);
            n = n / i;
        }
    }
    
    if (n != 1) X.push_back(n);

    return (X);
}

void solve(int tc) {
    ll n, summ;

    cin >> n;

    summ = 1;
    vi X(n);
    mi Y;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    for (int i = 0; i < n; i++)
    {
        auto Z = primeFactors(X[i]);
        for (auto m : Z) {
            if (!Y.count(m)) {
                Y[m]++;
                summ *= m;
            }
        }       
    }

    vi Z;
    for (auto m : Y) Z.push_back(m.first);

    for (int i = 0; i < (1 << Z.size()); i++)
    {
        ll re = 1;

        for (int j = 0; j < Z.size(); j++)
            if (i & (1 << j)) re *= Z[j];
        
        bool isit = 1;  
        for (int j = 0; j < n; j++)
        {
            if (__gcd(X[j], re) == 1) {
                isit = 0;
                break;
        }    
        }
        
        if (isit) summ = min(summ, re);
    }

    cout << summ << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
