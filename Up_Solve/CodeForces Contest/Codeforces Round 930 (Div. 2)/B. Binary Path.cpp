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

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, re, k = 0;
    string s = "";

    vector<string> X(2);

    cin >> n >> X[0] >> X[1];
    
    s += X[0][0];
    re = 1;

    for (int i = 1; i < n; i++)
    {
        if (X[0][i] < X[1][i - 1] && k == 0) re = 0;
        if (X[0][i] > X[1][i - 1]) k = 1;

        re += (k == 0);

        if (k) s += X[1][i - 1];
        else s += X[0][i];
    }

    s += X[1][n - 1];

    cout << s << '\n' << re << '\n';
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