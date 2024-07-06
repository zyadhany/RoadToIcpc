#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <random>

#define ll int
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
    ll n, q, summ;
    string s;

    cin >> n >> q;
    cin >> s;

    summ = 0;
    for (int i = 0; i < n - 2; i++)
        if (s.substr(i, 3) == "abc") summ++;
    
    while (q--)
    {
        ll pos;
        char c;

        cin >> pos >> c;

        pos--;
        ll at = pos - (c == 'b') - 2 * (c == 'c');

        for (int i = pos - 2; i <= pos; i++)
            if (i >= 0 && i < n - 2 && s.substr(i, 3) == "abc") summ--;
        s[pos] = c;
        if (at >= 0 && at < n - 2 && s.substr(at, 3) == "abc") summ++;

        cout << summ << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
