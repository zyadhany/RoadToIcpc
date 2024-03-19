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

void solve(int tc) {
    ll n, q, re;

    cin >> n >> q;

    vi X(n + 1), M(q), Z(n + 2);

    for (int i = 0; i < n; i++)
        cin >> X[i + 1];
    for (int i = 0; i < q; i++)
        cin >> M[i];

    for (int i = 1; i <= n; i++)
    {
        Z[i] = max(Z[i - 1], X[i]);
        X[i] += X[i - 1];
    }
    Z[n + 1] = INT32_MAX;
    for (int i = 0; i < q; i++)
    {
        re = upper_bound(all(Z), M[i]) - Z.begin() - 1;
        cout << X[re] << ' ';
    }cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}