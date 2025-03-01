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
#define mi map<ll,ll

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
    string s;
    
    cin >> s;
    
    ll n = 0;
    mc Y;
    for (auto c : s) if (!Y.count(c))
        Y[c] = n++;

    vii adj(n, vi(n));
    for (int i = 1; i < s.size(); i++)
        adj[Y[s[i-1]]][Y[s[i]]]++;
    
    vi perm(n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }
    
    ll ans = INT32_MAX;
    do {
        ll sol = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                sol += adj[i][j];
        ans = min(ans, sol);        
    } while (next_permutation(all(perm)));
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("movie.in", "r", stdin);
    // freopen("movie.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
