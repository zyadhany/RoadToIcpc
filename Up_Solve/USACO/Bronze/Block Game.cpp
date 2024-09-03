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
    ll n;
    
    cin >> n;

    vi X(26);

    for (int i = 0; i < n; i++)
    {
        vii Y(2, vi(26));
        for (int j = 0; j < 2; j++)
        {
            string s; cin >> s;
            for (auto c : s) Y[j][c - 'a']++;
        }

        for (int j = 0; j < 26; j++)
            X[j] += max(Y[0][j], Y[1][j]);
    }

    for (int i = 0; i < 26; i++)
        cout << X[i] << '\n';        
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
