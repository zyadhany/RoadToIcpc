#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <random>

#define ll int
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

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];
    ll l, r, at;
    at = 1;
    while (at <= n && X[at - 1] == at)
        at++;


    if (at != n + 1) {
        ll st = at;
        for (at; at < n && X[at] != st; at++);
        reverse(X.begin() + st - 1, X.begin() + at + 1);
    }
    
    for (int i = 0; i < n; i++)
        cout << X[i] << ' ';
    cout << '\n';                
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
