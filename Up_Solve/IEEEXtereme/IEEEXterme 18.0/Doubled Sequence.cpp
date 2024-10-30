#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
#include <algorithm>

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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n * 2);
    for (int i = 0; i < n; i++)
        X[i * 2] = X[i * 2 + 1] = i + 1;

    do
    {
        bool ok = true;
        mi Y;
        for (int i = 0; i < 2 * n; i++)
        {
            if (!Y.count(X[i]))
                Y[X[i]] = i;
            else
                if (i - Y[X[i]] != X[i]) {
                ok = 0;
                break;
                }
        }
        
        if (!ok) continue;
        for (int i = 0; i < X.size(); i++)
            cout << X[i] << ' ';
        cout << '\n';
        break;
    } while (next_permutation(all(X)));
        
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
