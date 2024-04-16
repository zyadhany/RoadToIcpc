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
#define YES {cout << "Valid\n"; return;}
#define NO {cout << "Invalid\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, k, re;

    cin >> n >> k;
    
    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }

    sortx(X);
    
    if (k == 0 && X[0] != 1) {
        cout << "1\n";
        return;
    }

    re = 0;
    X.push_back(INT32_MAX);
    for (int i = 0; i < n; i++)
    {
        re++;
        if (X[i] == X[i + 1]) continue;
        if (re == k) {
            cout << X[i] << '\n';
            return;
        }
    }
    
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
