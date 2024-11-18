#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    vi X(n);
    vi Y(m);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 0; i < m; i++)
        cin >> Y[i];
    sortx(X); sortx(Y);

    ll cnt = 0;
    ll at = 0;
    for (int i = 0; i < n; i++)
    {
        while (at < m && Y[at] < X[i] - k) at++;
        if (at < m && X[i] <= Y[at] + k) cnt++, at++;
    }

    cout << cnt << '\n';
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
