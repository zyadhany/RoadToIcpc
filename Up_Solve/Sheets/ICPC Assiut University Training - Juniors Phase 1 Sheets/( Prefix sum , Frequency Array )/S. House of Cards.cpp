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
    ll n, l, r, summ, re;
    string s;

    cin >> s;


    mc X;
    vii Y(3, vi(s.size() + 10));
    X['/'] = 0;
    X['\\'] = 1;
    X['_'] = 2;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            Y[j][i + 1] = Y[j][i];
        Y[X[s[i]]][i + 1]++;
    }

    cin >> n;

    while (n--)
    {
        cin >> l >> r;
        
        summ = INT32_MAX;

        for (int i = 0; i < 3; i++)
        {
            re = Y[i][r] - Y[i][l - 1];
            re = getsummm(re) + (i == 2);
            summ = min(summ, re);
        }

        cout << summ << "\n";
    }
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