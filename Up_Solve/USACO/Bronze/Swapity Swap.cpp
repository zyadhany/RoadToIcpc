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
    ll n, k;

    cin >> n >> k;

    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    vi X(n + 1);

    for (int i = 0; i <= n; i++)
        X[i] = i;

    ll cnt = 0, at;
    map<vi, int> Y;
    vii Z;

    while (true)
    {
        Z.push_back(X);
        if (cnt == k) {
            for (int i = 1; i <= n; i++)
                cout << X[i] << '\n';
            return;
        }
        Y[X] = cnt;
        reverse(X.begin() + l1, X.begin() + r1 + 1);
        reverse(X.begin() + l2, X.begin() + r2 + 1);
        cnt++;

        if (Y.count(X)) {
            at = Y[X];
            break;
        }
    }

    k -= at;
    ll sz = Z.size() - at;
    vi res = Z[at + k % sz];
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
