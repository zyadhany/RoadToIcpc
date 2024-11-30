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

const int MODE = 1e9;

using namespace std;

void solve(int tc) {
    ll n, m;

    cin >> m >> n;

    vi X(n);
    vi Z(1 << m, INT32_MAX);

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        ll re = 0;
        for (int j = 0; j < m; j++)
        {
            re *= 2;
            re += (s[j] == 'G');
        }
        X[i] = re;
        Z[re] = 0;
    }
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < (1<<m); j++)
            if (Z[j] != INT32_MAX) 
                Z[j ^ (1 << i)] = min(Z[j ^ (1 << i)], Z[j] + 1);
    
    for (int i = 0; i < n; i++) 
        cout << m - Z[X[i] ^ ((1 << m) - 1)] << '\n'; 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cruise.in", "r", stdin);
    // freopen("cruise.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
