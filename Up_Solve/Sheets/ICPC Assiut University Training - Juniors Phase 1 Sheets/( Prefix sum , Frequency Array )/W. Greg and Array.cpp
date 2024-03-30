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
    ll n, q, m, l, r, summ, re;

    cin >> n >> m >> q;

    vi X(n + 10), L(m + 10), R(n + 10);
    vii Y(m + 1, vi(3));

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 3; j++)
            cin >> Y[i][j];

    while (q--)
    {
        cin >> l >> r;
        L[l]++;
        L[r + 1]--;
    }

    summ = 0;
    for (int i = 1; i <= m; i++)
    {
        summ += L[i];
        R[Y[i][0]] += summ * Y[i][2];
        R[Y[i][1] + 1] -= summ * Y[i][2];
    }

    summ = 0;
    for (int i = 1; i <= n; i++)
    {
        summ += R[i];
        X[i] += summ;
    }

    for (int i = 1; i <= n; i++)
        cout << X[i] << ' ';
    cout << '\n';
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