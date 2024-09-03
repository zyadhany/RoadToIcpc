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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, m;
    string s, t;

    cin >> s >> t;

    n = s.size(), m = t.size();

    for (int i = 0; i <= n - m; i++)
    {
        bool isit = 1;
        for (int j = 0; j < m && isit; j++)
            if (s[i + j] != t[j]) isit = 0;
        
        if (isit) {
            s.erase(s.begin() + i, s.begin() + i + m);
            i = max(0ll, i - m - 3);
            n -= m;
        }
    }
    
    cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
