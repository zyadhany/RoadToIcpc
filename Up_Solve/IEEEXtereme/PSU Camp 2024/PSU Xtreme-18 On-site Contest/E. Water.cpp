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

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, c;

    cin >> n >> c;

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];    

    ll res = 1;
    ll got = c;

    for (int i = 0; i < n; i++)
    {
        if (got > X[i]) got -= X[i];
        else res++, got = c;
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("lemonade.in", "r", stdin);
    //freopen("lemonade.out", "w", stdout);
    
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
