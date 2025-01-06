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

    cin >> n;

    m = 5;
    vii X(n, vi(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> X[i][j];
        sortx(X[i]);        
    }
    
    unordered_map<string, ll> mp;
    mp.reserve(n * (1 << m));

    for (auto &Y : X) {
        for (int i = 1; i < (1 << m); i++)
        {
            string s = "";
            for (int j = 0; j < m; j++)
                if (i & (1 << j)) s += to_string(Y[j]) + "|";
            mp[s]++;            
        }
    }

    ll res = 0;

    for (auto &Y : X) {
        for (int i = 1; i < (1 << m); i++)
        {
            string s = "";
            ll pr = -1;
            for (int j = 0; j < m; j++)
                if (i & (1 << j)) s += to_string(Y[j]) + "|", pr *= -1;
            res += pr * (n - mp[s]);
        }
    }

    cout << res / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
