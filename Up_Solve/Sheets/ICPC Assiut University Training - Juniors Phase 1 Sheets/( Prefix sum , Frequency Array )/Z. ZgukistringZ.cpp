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
    ll n, m, k, mx, summ, re, l, r;
    string s, a, b, c;
    bool get;

    cin >> a >> b >> c;

    mx = re = summ = 0;
    n = a.size(), m = b.size(), k = c.size();
    vi X(255), Y, L(255), R(255);

    for (int i = 0; i < n; i++)
        X[a[i]]++;
    for (int i = 0; i < m; i++)
        L[b[i]]++;
    for (int i = 0; i < k; i++)
        R[c[i]]++;

    for (int i = 0; i <= n; i++)
    {
        Y.assign(all(X));
        get = 1;
        re = INT32_MAX;

        for (int j = 'a'; j <= 'z'; j++)
        {
            Y[j] -= L[j] * i;
            
            if (R[j]) re = min(re, Y[j] / R[j]);
            if (Y[j] < 0) get = 0;
        }
        if (!get) continue;
        if (re == INT32_MAX) re = 0;
        if (re + i >= mx) {
            mx = re + i;
            l = i;
            r = re;
        }
    }

    for (int i = 0; i < l; i++)
        cout << b;
    for (int i = 0; i < r; i++)
        cout << c;
    for (char i = 'a'; i <= 'z'; i++)
    {
        X[i] -= L[i] * l + R[i] * r;
        for (int j = 0; j < X[i]; j++)
            cout << i;
    }
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