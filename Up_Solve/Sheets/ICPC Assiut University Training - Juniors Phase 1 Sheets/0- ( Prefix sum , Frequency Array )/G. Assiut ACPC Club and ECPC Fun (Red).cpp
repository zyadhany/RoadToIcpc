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
    ll n, q, re, l;

    cin >> n;

    vi X(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    cin >> q;

    vp Y(q);

    for (int i = 0; i < q; i++)
        cin >> Y[i].first >> Y[i].second;
    sortx(Y);

    l = 1;
    for (int i = 0; i < q; i++)
    {
        l = max(l, Y[i].first);
        for (int j = l; j <= Y[i].second; j++)
            X[j] = 0;
        l = max(l, Y[i].second);
    }

    re = 0;
    for (int i = 1; i <= n; i++)
        if (X[i]) re++;
    cout << re << '\n';
    for (int i = 1; i <= n; i++)
        if (X[i]) cout << X[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}