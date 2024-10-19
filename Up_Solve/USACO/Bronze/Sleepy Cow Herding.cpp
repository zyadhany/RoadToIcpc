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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    vi X(3);
    for (int i = 0; i < 3; i++) cin >> X[i];
    sortx(X);

    ll mn, mx;

    if (X[2] - X[0] == 2) mn = 0;
    else if (X[2] - X[1] == 2 || X[1] - X[0] == 2) mn = 1;
    else mn = 2;

    mx = max({X[2] - X[1] - 1, X[1] - X[0] - 1, 0ll});

    cout << mn << '\n' << mx;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
