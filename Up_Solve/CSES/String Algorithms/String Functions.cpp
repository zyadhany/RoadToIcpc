// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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


vi PrefixFunction(string &s) {
    ll n = s.size();
    vi Z(n);
    ll l, r; l = r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r) {
            Z[i] = min(r-i, Z[i-l]);
        } else l = r = i;
        while (i + Z[i] < n && s[Z[i]] == s[i+Z[i]]) Z[i]++;
        if (r < i + Z[i]) l = i, r = i + Z[i];
    }
    
    return Z;
}

vi KMP(string &s) {
    ll n = s.size();
    vi P(n);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j]) j = P[j-1];
        P[i] = (j += (s[i] == s[j]));
    }
    
    return P;
}


void solve(int tc) {
    string s;
    cin >> s;

    auto pref = PrefixFunction(s);
    auto suff = KMP(s);
    for (auto a : pref) cout << a << ' ';
    cout << '\n';
    for (auto a : suff) cout << a << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
