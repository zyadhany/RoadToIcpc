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

vi dx = {0, 0, -1, -1};
vi dy = {-1, 0, -1, 0};

/**
 * start with CC or .. -> keep itraing col and find max
 * CC.C.
 * ..C.C
 * CC.C.
 * ..C..
 * CC.C.
 * 
 * we can itrate in row and find max.
 * C.C.
 * .C.C
 * .C.C
 * C.C
 * .C
 * .C
 * c
 * 
 */

void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n, vi(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];
    
    ll mx = 0;
    ll summRow = 0;
    ll summCol = 0;

    for (int i = 0; i < n; i++)
    {
        ll l = 0, r = 0;
        ll a = 0, b = 0;

        for (int j = 0; j < n; j++)
        {
            if (j % 2) l +=X[i][j];
            else r += X[i][j];
        
            if (j % 2) a +=X[j][i];
            else b += X[j][i];
        }
        
        summCol += max(l, r);
        summRow += max(a, b);
    }
    
    mx = max(summCol, summRow);
    cout << mx << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("citystate.in", "r", stdin);
    //freopen("citystate.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
