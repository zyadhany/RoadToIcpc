#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>


#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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

bool isLogx(vi& X, vi& Y) {
    ll l, r;

    for (int i = 'a'; i <= 'z'; i++)
    {
        if (X[i]) l = i;
        if (Y[i]) r = i;
    }
    if (r != 'a') return (1);
    if (l != 'a') return (0);
    return (X[l] < Y[r]);
}

void solve(int tc) {
    ll q, op, k;
    string s;

    cin >> q;

    vii Y(3, vi(255));

    Y[1]['a'] = Y[2]['a'] = 1;

    while (q--)
    {
        cin >> op >> k >> s;
        for (int i = 0; i < s.size(); i++)
            Y[op][s[i]] += k;
    
        if (isLogx(Y[1], Y[2])) cout << "Yes\n";
        else cout << "NO\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}