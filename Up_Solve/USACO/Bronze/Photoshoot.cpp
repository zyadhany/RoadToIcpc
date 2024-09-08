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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;
    string s;

    cin >> n >> s;

    ll sol = 0;
    vi X;
    for (int i = 0; i < n; i+=2)
    {
        string t = s.substr(i, 2);
        ll re = -1;
        if (t == "GH") re = 0;
        if (t == "HG") re = 1;
        if (re == -1) continue;
        if (X.empty() || X.back() != re) X.push_back(re);
    }

    for (int i = 0; i < X.size(); i++)
        if (!X[i]) sol = i + 1;
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("outofplace.in", "r", stdin);
    //freopen("outofplace.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
