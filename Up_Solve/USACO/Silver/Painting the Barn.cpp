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
#define mc map<char,int>
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

    vii X(1010, vi(1010));

    for (int i = 0; i < n; i++)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, x2++, y1++, y2++;
        
        X[x1][y1] += 1;
        X[x2][y2] += 1;
        X[x2][y1] -= 1;
        X[x1][y2] -= 1;
    }
    
    for (int i = 1; i < X.size(); i++)
        for (int j = 1; j < X.size(); j++)
            X[i][j] += X[i - 1][j] + X[i][j - 1] - X[i - 1][j - 1];

    ll cnt = 0;
    for (int i = 0; i < X.size(); i++)
        for (int j = 0; j < X[i].size(); j++)
            cnt += (X[i][j] == k);
    cout << cnt << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
