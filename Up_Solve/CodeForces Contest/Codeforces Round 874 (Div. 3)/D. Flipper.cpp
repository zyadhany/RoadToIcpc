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

const int MODE = 998244353;

using namespace std;


void req(vi& X, ll k) {
    ll n, l, r;

    n = X.size();

    if (n == 1) {
        cout << X[0] << '\n';
        return;
    }

    if (X[0] == k) {
        req(X, n - 1);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (X[i] == k) {
            r = i;
            break;
        }
    }

    r -= (r != n - 1);

    for (int i = r + 1; i < n; i++)
        cout << X[i] << ' ';
    cout << X[r] << ' ';
    while (r)
    {
        if (X[0] > X[r - 1]) break;
        r--;
        cout << X[r] << ' ';
    }
    
    for (int i = 0; i < r; i++)
        cout << X[i] << ' ';
    cout << '\n';
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];

    req(X, n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}