#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <random>

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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n, summ;

    cin >> n;

    summ = 0;
    vi X(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        summ += X[i];
    }
    
    ll res = 0;
    ld mean = summ * 1.0 / n;
    map<ld, int> Y;
    
    for (int i = 0; i < n; i++)
    {
        ld re = mean - X[i];
        res += Y[-re];
        Y[re]++;
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
