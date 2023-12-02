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
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

bool isGood(string& s) {
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1]) return (0);
    return (1);
}

void solve(int tc) {
    ll n, m;
    string s, t;
    
    cin >> n >> m >> s >> t;

    if (isGood(s)) YES;
    if (!isGood(t)) NO;

    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1] && (s[i - 1] == t.front() || s[i] == t.back()))
            NO;
    YES;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
