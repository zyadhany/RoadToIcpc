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
    ll n, m, l, r, k;

    cin >> n >> m;

    vi X(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> k;
        X[l] -= k;
        X[r] += k;
    }

    for (int i = 1; i <= n; i++)
        if (X[i] < 0) NO;

    YES;
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