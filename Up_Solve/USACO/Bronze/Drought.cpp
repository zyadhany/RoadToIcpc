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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll conveBase(ll n, ll b) {
    ll summ = 0;

    string s = to_string(n);
    reverse(all(s));
    ll pw = 1;
    for (int i = 0; i < s.size(); i++)
    {
        summ += (s[i] - '0') * pw;
        pw *= b;
    }
    
    return summ;
}

void solve(int tc) {
    ll n;

    cin >> n;

    ll summ = 0;
    vi X(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        summ += X[i];
    }
    
    for (int i = 1; i <= n - 1; i++)
    {

        if (X[i] > X[i + 1] &&  i % 2) MUN;
        if (X[i] < X[i + 1])
        {
            ll re = X[i + 1] - X[i];
            if (i == n - 1 || re > X[i + 2]) MUN;
            X[i + 1] -= re;
            X[i + 2] -= re;
        }
    }

    ll res = summ - X.back() * n;
    cout << res << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("whatbase.in", "r", stdin);
    //freopen("whatbase.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
