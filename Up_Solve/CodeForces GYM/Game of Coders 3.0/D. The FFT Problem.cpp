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


void solve(int tc) {
    ll n, mx, sol;

    cin >> n;

    if (n < 9) {
        cout << "-1\n";
        return;
    }

    mx = 1;
    sol = n - 4;

    if (n > 20 && n % 4 == 0) {
        sol = n / 4 - 1;
        mx = 2;
    }

    for (ll i = 5; i * i <= n; i++)
    {
        ll k = n;
        ll re = 0;

        while (k)
        {
            re += (k % i == 4);
            k /= i;
        }
        
        //cout << re << ' ' << i << '\n';
        if (re > mx || (re == mx && i > sol)) mx = re, sol = i;
    }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
