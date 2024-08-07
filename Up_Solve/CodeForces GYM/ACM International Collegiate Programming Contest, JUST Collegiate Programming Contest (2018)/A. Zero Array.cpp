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
    ll n, q, summ;

    cin >> n >> q;

    summ = 0;
    vi X(n + 1);
    mi Y;

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        Y[X[i]]++;
    }
    summ = X.size();

    while (q--)
    {
        ll opp;
        cin >> opp;
        if (opp == 1) {
            ll l, r;
            cin >> l >> r;
            Y[X[l]]--;
            if (!Y[X[l]]) Y.erase(X[l]);
            X[l] = r;
            Y[X[l]]++;
        } else cout << Y.size() - Y.count(0) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("window.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
