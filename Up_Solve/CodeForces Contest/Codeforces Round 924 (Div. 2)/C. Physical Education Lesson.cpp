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

vi div(ll n) {
    vi X;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            X.push_back(i);
            if (n / i != i)X.push_back(n / i);
        }

    return (X);
}

void solve(int tc) {
    ll n, k, summ = 0;

    cin >> n >> k;

    vi X = div(n - k);
    vi Y = div(n + k - 2);
    mi M;

    for (int i = 0; i < X.size(); i++) {
        M[X[i]] = 1;
        summ += (X[i] >= 2 * k - 2 && X[i] % 2 == 0);
    }

    for (int i = 0; i < Y.size(); i++) {
        if (M[Y[i]]) continue;
        summ += (Y[i] > 2 * k - 2 && Y[i] % 2 == 0);
    }

    cout << summ << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}