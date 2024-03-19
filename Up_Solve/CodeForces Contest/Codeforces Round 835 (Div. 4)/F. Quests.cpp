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
    ll n, c, d, summ, l, r, at;

    cin >> n >> c >> d;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    sortx(X);
    reverse(all(X));

    if (d * X[0] < c) {
        cout << "Impossible\n";
        return;
    }

    summ = 0;

    for (int i = 0; i < min(n, d); i++)
        summ += X[i];

    if (summ >= c) {
        cout << "Infinity\n";
        return;
    }


    l = 0, r = d;

    while (l < r)
    {
        at = (l + r + 1) / 2;
        summ = 0;

        for (int i = 0, re = 0; i < d; i++, re++)
        {
            if (re > at) {
                re = 0;
            }
            if (re >= n) continue;
            summ += X[re];
        }

        if (summ >= c) l = at;
        else r = at - 1;
    }

    cout << l << "\n";
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