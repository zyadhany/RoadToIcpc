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
    ll n, q, at, k, re, m;

    cin >> n >> q;

    pl a, b;
    deque<pl> X(n);
    map<pl, ll> Y;
    vp Z;

    for (int i = 0; i < n; i++) {
        cin >> X[i].first;
        X[i].second = i;
    }

    for (int i = 1; i <= n * 2; i++)
    {
        a = X.front();
        X.pop_front();
        b = X.front();
        X.pop_front();
        Y[{a.second, b.second}];
        X.push_front(max(a, b));
        X.push_back(min(a, b));
        Z.push_back({ a.first, b.first });
    }

    at = 2 * n + 1;
    while (true)
    {
        a = X.front();
        X.pop_front();
        b = X.front();
        X.pop_front();
        X.push_front(max(a, b));
        X.push_back(min(a, b));
        if (Y[{a.second, b.second}]) {
            at = Y[{a.second, b.second}] - 1;
            break;
        }
        else {
            Z.push_back({ a.first, b.first });
            Y[{a.second, b.second}] = at;
            at++;
        }
    }
    
    n = Z.size();
    m = n - at;
    while (q--)
    {
        cin >> k;
        k--;

        if (k >= n) {
            k -= at;
            k %= m;
            k += at;
        }
        re = k;
        cout << Z[re].first << ' ' << Z[re].second << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        //cout << Z[i].first << ' ' << Z[i].second << "|||\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}