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

const int MX = 1e5 + 1;

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    ll sz = n - 2;
    mi Y;
    for (int i = 0; i < n; i++)
    {
        
        if (sz % X[i]) continue;
        if (Y[sz / X[i]]) {
            cout << sz / X[i] << ' ' << X[i] << '\n';
            return;
        }
        Y[X[i]] = i + 1;
    }
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