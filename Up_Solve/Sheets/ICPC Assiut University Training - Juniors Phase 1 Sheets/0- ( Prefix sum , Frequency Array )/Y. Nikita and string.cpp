#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, mx, summ, re, l, r;
    string s;

    cin >> s;

    n = s.size();
    mx = summ = re = 0;
    vp X(n + 10);

    for (int i = 1; i <= n; i++)
    {
        re += (s[i - 1] == 'a');
        X[i].first = re;
    }

    X[n + 2].second = INT32_MAX;
    for (int i = n + 1; i >= 1; i--)
    {
        r = (n + 1 - i) - (X[n].first - X[i - 1].first);
        l = X[i - 1].first - X[0].first;
        summ = l + r;
        X[i].second = min(X[i + 1].second, summ);
    }

    for (int i = 0; i <= n; i++)
    {
        l = i - X[i].first;
        r = X[i + 1].second - X[i].first;
        summ = l + r;
        mx = max(mx, n - summ);
    }

    cout << mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}