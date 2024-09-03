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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<string> X(2 * n);

    for (int i = 0; i < 2 * n; i++)
        cin >> X[i];

    ll res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                unordered_map<ll, ll> Y;
                Y.reserve(n);
                for (int t = 0; t < n; t++) {
                    ll re = X[t][i] * 1000000 + X[t][j] * 1000 + X[t][k];
                    Y[re] = 1;
                }

                bool isit = 1;  
                for (int t = n; t < 2 * n; t++) {
                    ll re = X[t][i] * 1000000 + X[t][j] * 1000 + X[t][k];
                    if (Y.count(re)) isit = 0;
                }

                res += isit;

            }
        }
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
