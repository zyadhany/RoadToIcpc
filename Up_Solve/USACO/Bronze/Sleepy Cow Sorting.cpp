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
    ll n;

    cin >> n;

    vi X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    ll sol = n - 1;
    for (int i = n - 2; i >= 0; i--)
        if (X[i] < X[i + 1]) sol = i;
        else break;

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}