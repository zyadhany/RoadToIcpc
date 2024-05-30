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


const int MODE = 1e9 + 7;

using namespace std;

 

void solve(int tc) {
    ll n, mn;
    string s;

    cin >> s;

    n = s.size();

    vii X(n + 1, vi(n + 1, INT32_MAX));

    X[0][n - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (s[i] == s[j]) X[i + 1][j - 1] = min(X[i + 1][j - 1], X[i][j]);
            else
            {
                X[i + 1][j] = min(X[i + 1][j], X[i][j] + 1);
                X[i][j - 1] = min(X[i][j - 1], X[i][j] + 1);
            }
            
        }
    }
    
    mn = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j) mn = min(mn, X[i][j]);
        }
        
    }
    
    cout << mn << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}