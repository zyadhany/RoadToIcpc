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


ll getsummm(ll n) {
    ll l, r, at;

    l = 0, r = 1e6;
    while (l < r)
    {
        at = (l + r + 1) / 2;
        if (at * (at + 1) / 2 <= n) l = at;
        else r = at - 1;
    }
    return (l);
}

void solve(int tc) {
    ll n, summ = 0, l, r, mn, a, re;
    string s;

    cin >> s;

    n = s.size();
    vi X(255), Z(n + 1);

    for (int i = 0; i < 26; i++) {
        cin >> a;
        X[i + 'a'] = a;
    }

    for (int i = n - 1; i >= 0; i--)
        if (s[i] != '?') Z[i] = s[i];
        else Z[i] = Z[i + 1];

    if (s[0] == '?') {
        if (!Z[0]) s[0] = 'a';
        else {
            s[0] = 'z';
            for (char i = 'a'; i <= 'z'; i++)
                if (X[i] == X[Z[0]]) s[0] = min(s[0], i);
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] != '?') continue;
        if (!Z[i]) {
            s[i] = s[i - 1];
            continue;
        }

        mn = 'a';
        re = INT32_MAX;

        for (ll j = 'a'; j <= 'z'; j++)
        {
            a = abs(X[j] - X[s[i - 1]]) + abs(X[j] - X[Z[i]]);
            if (a <= re) {
                if (a == re) mn = min(mn, j);
                else mn = j;
                re = a;
            }
        }

        s[i] = mn;
    }
    

    for (int i = 1; i < n; i++)
        summ += abs(X[s[i]] - X[s[i - 1]]);
    cout << summ << '\n' << s << '\n';
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