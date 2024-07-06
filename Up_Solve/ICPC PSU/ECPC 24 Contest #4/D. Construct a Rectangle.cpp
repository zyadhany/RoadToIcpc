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
    vi X(3);

    cin >> X[0] >> X[1] >> X[2];
    sortx(X);

    if (X[0] + X[1] == X[2]) YES;
    if (X[0] == X[1] && X[2] % 2 == 0) YES;
    if (X[1] == X[2] && X[0] % 2 == 0) YES;
    if (X[0] == X[2] && X[1] % 2 == 0) YES;
    NO;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
