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
    ll res = 0;
    string s;

    cin >> s;

    vp X(26, {-1, -1});

    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'A';
        if (X[ind].first == -1) X[ind].first = i;
        else X[ind].second = i;
    }
    
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            pl a = X[i];
            pl b = X[j];
            if (a > b) swap(a, b);
            if (b.first < a.second && b.second > a.second) res++;
        }
    }
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("circlecross.in", "r", stdin);
    //freopen("circlecross.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
