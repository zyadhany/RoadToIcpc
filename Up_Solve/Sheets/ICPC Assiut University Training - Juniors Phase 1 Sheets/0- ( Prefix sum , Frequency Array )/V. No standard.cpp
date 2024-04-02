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
    ll n, q, l, r, summ, re;

    cin >> n >> q;

    vi X(n + 10);
    vp Z(n + 10);

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    while (q--)
    {
        cin >> l >> r;
        Z[l].first++;
        Z[r + 1].first--;
        Z[r + 1].second -= r - l + 1;
    }

    summ = re = 0;

    for (int i = 1; i <= n; i++)
    {
        re += Z[i].first;
        summ += re;
        summ += Z[i].second;
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