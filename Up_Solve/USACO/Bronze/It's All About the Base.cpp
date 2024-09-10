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
    ll a, b;

    cin >> a >> b;

    ll x = 10;
    bool isit = 0;

    while (!isit)
    {
        ll y;
        ll l = 10, r = 15000;
        ll k = conveBase(a, x);

        while (l <= r)
        {
            ll at = (l + r) / 2; 
            ll re = conveBase(b, at);
            if (re == k) {
                isit = 1;
                y = at;
                break;
            } else if (re < k) l = at + 1;
            else r = at - 1;
        }

        if (isit) cout << x << ' ' << y << '\n';
        else x++;
    }   
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
