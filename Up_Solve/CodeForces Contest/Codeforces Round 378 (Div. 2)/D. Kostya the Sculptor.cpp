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

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, a, b, c, mx, re;

    cin >> n;

    mx = 0;
    vi Z, Y(3);
    map<pair<ll, ll>, pair<ll, ll>> X;

    for (ll i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> Y[j];
        sortx(Y);

        if (min(Y[0], min(Y[1], Y[2])) >= mx) {
            mx = min(Y[0], min(Y[1], Y[2]));
            Z = { i };
        }

        if (min(min(Y[0], Y[1]), X[{Y[0], Y[1]}].first + Y[2]) > mx) {
            mx = min(min(Y[0], Y[1]), X[{Y[0], Y[1]}].first + Y[2]);
            Z = { i, X[{Y[0], Y[1]}].second };
        }

        if (min(min(Y[0], Y[2]), X[{Y[0], Y[2]}].first + Y[1]) > mx) {
            mx = min(min(Y[0], Y[2]), X[{Y[0], Y[2]}].first + Y[1]);
            Z = { i, X[{Y[0], Y[2]}].second };
        }

        if (min(min(Y[1], Y[2]), X[{Y[1], Y[2]}].first + Y[0]) > mx) {
            mx = min(min(Y[1], Y[2]), X[{Y[1], Y[2]}].first + Y[0]);
            Z = { i, X[{Y[1], Y[2]}].second };
        }

        if (Y[2] > X[{Y[0], Y[1]}].first)
        {
            X[{Y[0], Y[1]}].first = Y[2];
            X[{Y[0], Y[1]}].second = i;
        }
        if (Y[0] > X[{Y[1], Y[2]}].first)
        {
            X[{Y[1], Y[2]}].first = Y[0];
            X[{Y[1], Y[2]}].second = i;
        }
        if (Y[1] > X[{Y[0], Y[2]}].first)
        {
            X[{Y[0], Y[2]}].first = Y[2];
            X[{Y[0], Y[2]}].second = i;
        }
    }

    cout << Z.size() << '\n';
    for (int i = 0; i < Z.size(); i++)
        cout << Z[i] << ' ';
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