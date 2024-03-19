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

ll a, b;
vector<vector<pl>> Y;

void req(ll n, ll p, ll k, mi& X) {
    if (p) X[k]++;

    for (int i = 0; i < Y[n].size(); i++)
    {
        if (Y[n][i].first == p || Y[n][i].first == b) continue;
        req(Y[n][i].first, n, k ^ Y[n][i].second, X);
    }
}

void solve(int tc) {
    ll n, l, r, k;

    cin >> n >> a >> b;

    Y.clear();
    Y.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> l >> r >> k;
        Y[l].push_back({ r, k });
        Y[r].push_back({ l, k });
    }

    mi L, R;

    req(a, -1, 0, L);
    req(b, 0, 0, R);

    for (auto m : L)
        if (R[m.first]) YES;
    NO;
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