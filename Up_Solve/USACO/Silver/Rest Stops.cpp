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
    ll n, k, a, b;

    cin >> k >> n >> a >> b;

    vp X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i].second >> X[i].first;
    sort(X.rbegin(), X.rend());

    ll at = 0;
    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        if (at > X[i].second) continue;
        res += (a - b) * (X[i].second - at) * X[i].first;
        at = X[i].second;
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
