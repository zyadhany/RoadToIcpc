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

    vi X(n + 2);

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    X[0] = INT32_MIN; X.back() = INT64_MAX;
    sortx(X);

    bool rest = 1;
    vi Z(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll l = X[i] - X[i - 1];
        ll r = X[i + 1] - X[i];
        Z[i] = (l <= r);
    }
    
    vi Y = {1};

    for (int i = 2; i <= n; i++)
        if (Z[i] == Z[i - 1]) Y.back()++;
        else Y.push_back(1);

    ll cnt = Y.size();
    
    for (int i = Z[0] + 1; i < n; i += 2)
        if (Y[i] == 1 || Y[i - 1] == 1) cnt--;

    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
