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
    string s, t;

    cin >> s >> t;

    sortx(s);
    if (t == "abc") {
        ll l = s.size() - 1, r = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'b' || s[i] == 'c') l = min(l, i), r = i;
        if (l < r && s[0] == 'a') reverse(s.begin() + l, s.begin() + r + 1);
    }
    cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}