#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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

const int MODE = 998244353;

using namespace std;


void solve(int tc) {
    ll n, k, res;

    cin >> n >> k;

    res = 0;
    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    } sort(X.rbegin(), X.rend());
    
    mi Y;
    ll mxfreq = 0;
    for (int i = 0; i < 2 * k; i++)
    {
        Y[X[i]]++;        
        mxfreq = max(mxfreq, Y[X[i]]);
    }
    res += max(0ll, mxfreq - k);
    
    for (int i = 2 * k; i < n; i++)
        res += X[i];
    
    cout << res << '\n';    
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
