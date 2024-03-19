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


void solve(int tc) {
    ll n, summ = 0, at;

    cin >> n;

    vi X(n + 10, INT32_MAX);

    at = 1;
    for (int i = 1; i <= n; i++) {
        cin >> X[at];
        if (X[at] != X[at - 1]) at++;
    }

    X[at] = INT32_MAX;
    for (int i = 1; i < at; i++)
        if (X[i - 1] > X[i] && X[i + 1] > X[i])
            summ++;

    if (summ == 1) YES;
    NO;
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}