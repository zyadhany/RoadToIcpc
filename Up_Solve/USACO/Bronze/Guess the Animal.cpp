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
    ll n;

    cin >> n;

    vector<pair<string, unordered_set<string>>> X(n);

    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> X[i].first >> m;

        for (int j = 0; j < m; j++)
        {
            string t; cin >> t;
            X[i].second.insert(t);
        }
    }

    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll re = 1;
            if (i == j) continue;
            for (auto a : X[i].second) re += X[j].second.count(a);
            mx = max(re, mx);
        }
    }
    
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
