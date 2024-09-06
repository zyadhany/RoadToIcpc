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

ll req(ll k, ll x) {
    ll l = 0;
    ll r = 0;
    ll t = 0;

    for (int i = 1; ; i++)
    {
        l += i;
        t++;
        if (l + r >= k) return t;

        if (i >= x) {
            r += i;
            t++;
            if (l + r >= k) return t;
        }
    }
}

void solve(int tc) {
    ll k, n;

    cin >> k >> n;

    while (n--)
    {
        ll x; cin >> x;
        cout << req(k, x) << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
