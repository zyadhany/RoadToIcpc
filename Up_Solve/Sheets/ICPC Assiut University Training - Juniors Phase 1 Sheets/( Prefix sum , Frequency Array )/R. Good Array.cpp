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


void solve(int tc) {
    ll n, summ, re;

    cin >> n;

    summ = 0;
    vi X(n), Y;
    map<ll, vi> Z;

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        summ += X[i];
        Z[X[i]].push_back(i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        re = 0;
        for (auto m : Z[summ - 2 * X[i]]) {
            if (m == i + 1) re = 1;
            else Y.push_back(m);
        }
        Z[summ - 2 * X[i]].clear();
        if (re) Z[summ - 2 * X[i]].push_back(i + 1);
    }

    cout << Y.size() << '\n';
    for (int i = 0; i < Y.size(); i++)
        cout << Y[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}