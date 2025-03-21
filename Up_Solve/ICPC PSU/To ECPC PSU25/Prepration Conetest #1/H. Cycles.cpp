#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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

ll MXN = 1e6+1;

void solve(int tc) {
    ll n, k;
    n = 100;
    cin >> k;
    
    vii X(n,vi(n));

    for (int i = 1; i < n; i++)
    {
        ll len = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (len > k) break;
            X[i][j] = X[j][i] = 1;
            k-=len;
            len++;
        }
    }


    cout << n << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << X[i][j];
        }
        cout << '\n';
    }
    
}   
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
