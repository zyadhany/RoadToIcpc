#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <random>

#define ll int
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
    ll n;

    cin >> n;

    vi X(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    for (int i = 1; i <= n; i++) {
        bool isit = 0;
        for (int j = i + 1; j >= 2; j--)
            if (X[i] % j) {
                isit = 1;
                break;
            }
        if (!isit) NO;
    }

    YES;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
