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

bool isin(ll n, ld a, ll b) {
    return (a * a + b * b <= n * n);
}

void solve(int tc) {
    ll n, k, l, r, at;

    cin >> n >> k;

    l = 0, r = 1e6;

    while (l < r)
    {
        at = (l + r + 1) / 2;

        if (isin(n, at * k, at * k)) l = at;
        else r = at - 1;
    }

    cout << (isin(n, l * k, (l + 1) * k) ? "Ashish" : "Utkarsh") << '\n';
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