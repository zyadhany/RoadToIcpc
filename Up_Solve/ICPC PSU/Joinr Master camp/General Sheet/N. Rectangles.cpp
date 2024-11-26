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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii X(n, vi(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> X[i][j];

    vi pw2(51, 1);
    for (int i = 1; i < pw2.size(); i++)
        pw2[i] = pw2[i - 1] * 2;
        
    ll sol = 0;

    for (int i = 0; i < n; i++)
    {
        ll l = 0;
        for (int j = 0; j < m; j++)
            l += X[i][j];
        ll r = m - l;
        sol += pw2[l] - 1;
        sol += pw2[r] - 1;
    }

    
    for (int i = 0; i < m; i++)
    {
        ll l = 0;
        for (int j = 0; j < n; j++)
            l += X[j][i];
        ll r = n - l;
        sol += pw2[l] - 1;
        sol += pw2[r] - 1;
    }
    
    sol -= n * m;

    cout << sol << '\n';
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
