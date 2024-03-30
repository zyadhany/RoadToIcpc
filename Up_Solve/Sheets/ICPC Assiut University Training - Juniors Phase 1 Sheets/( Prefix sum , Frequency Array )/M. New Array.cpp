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

vii Z(3e5 + 1);

void solve(int tc) {
    ll n, q, a;

    cin >> n >> q;

    vi X(n + 1), Y(n + 1);


    while (q--)
    {
        cin >> a;
        Y[a] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < Z[i].size(); j++)
            X[i] = max(X[i], Y[Z[i][j]]);

    for (int i = 1; i <= n; i++)
        cout << X[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    for (int i = 1; i < Z.size(); i++)
        for (int j = 1; j * j <= i; j++)
            if (i % j == 0) Z[i].push_back(j), Z[i].push_back(i / j);

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}