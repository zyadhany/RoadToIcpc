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
    ll n, q, a, l, r;

    cin >> n >> q;

    vi X(n), L(n + 10, n + 1), R(n + 10, n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        L[i + 1] = min(X[i], L[i]);
    }
    for (int i = n; i > 0; i--)
        R[i] = min(X[i - 1], R[i + 1]);

    while (q--)
    {
        cin >>l >> r;

        cout << min(R[r + 1], L[l - 1]) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}