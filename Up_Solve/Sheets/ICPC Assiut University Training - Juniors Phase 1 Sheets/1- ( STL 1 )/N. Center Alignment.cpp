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

ll getInd(vp& X, ll k) {
    ll re;
    pl m = { k, INT32_MAX };
    re = upper_bound(all(X), m) - X.begin() - 1;
    if (re < 0 || k > X[re].second) return (-1);
    return (re);
}

void solve(int tc) {
    ll n, re, mx, at = 1;
    string s, t, str;

    mx = 0;
    vector<string> X, Y;
    
    while (getline(cin, s))
    {
        re = s.size();
        mx = max(mx, re);
        X.push_back(s);
    }

    str = "";
    for (int i = 0; i < mx + 2; i++)
        str += '*';
    Y.push_back(str);

    for (int i = 0; i < X.size(); i++)
    {
        
        t = "*";
        re = mx - X[i].size();
        if (re % 2 && at % 2 == 0) t += " ";

        for (int j = 0; j < re / 2; j++)
            t += " ";
        t += X[i];
        for (int j = 0; j < re / 2; j++)
            t += " ";

        if (re % 2 && at % 2) t += " ";
        
        if (X[i].size()) at += re % 2;

        t += "*";
        Y.push_back(t);
    }
    Y.push_back(str);

    for (int i = 0; i < Y.size(); i++)
        cout << Y[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
