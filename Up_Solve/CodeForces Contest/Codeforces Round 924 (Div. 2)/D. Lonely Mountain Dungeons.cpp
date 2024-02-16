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
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 998244353;

using namespace std;



ll summtion(ll n) {
    if (n <= 0) return (0);
    return n * (n + 1) / 2;
}

void solve(int tc) {
    ll n, b, x,mx, summ, re, mxc;

    cin >> n >> b >> x;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    mxc = *max_element(all(X));
    
    vi Z(mxc + 10), Y(mxc + 10);

    for (int i = 0; i < n; i++) {
        summ = 0;
        for (int j = 1; j <= X[i]; j++) {
            re = (X[i] / j) * (X[i] / j) * summtion(j - 1);
            re += (j - 1) * (X[i] / j) * (X[i] % j);
            re += summtion(X[i] % j - 1);
            summ = max(summ, re);
            Y[j] += summ;
        }
        Z[X[i]] += summ;
    }

    mx = summ = 0;

    for (int i = 1; i <= mxc + 5; i++)
    {
        re = (Y[i] + summ) * b;
        mx = max(mx, re - x * (i - 1));
        summ += Z[i];
    }

    cout << mx << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}