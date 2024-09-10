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
    string s, t;

    cin >> s >> t;

    ll at = 0;
    for (int i = 0; i < s.size() && at < t.size(); i++)
    {
        if (s[i] == '?') s[i] = t[at];
        if (s[i] == t[at]) at++;
    }
    
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?') s[i] = 'a';
    
    if (at == t.size()) cout << "YES\n" << s << '\n';
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("buckets.in", "r", stdin);
    //freopen("buckets.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
