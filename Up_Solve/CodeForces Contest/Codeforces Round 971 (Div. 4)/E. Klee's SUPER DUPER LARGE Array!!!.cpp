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
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

ll summtion(ll n) {
    return n * (n + 1) / 2;
}

ll getsol(ll n, ll k, ll i) {
    ll summ = summtion(n - 1) - 2 * summtion(i);
    summ += (n - i - 1) * k;
    summ -= (i + 1) * k;
    return abs(summ);
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    if (n == 2) {
        cout << "1\n";
        return;
    }

    ll l = 0, r = n - 2;
    ll mn = INT64_MAX;
    while (l <= r)
    {
        ll mid = (l + r) / 2;

        ll at = getsol(n, k, mid);
        ll nxt = getsol(n, k, mid + 1);
        mn = min(mn, at);
        if (at >= nxt) l = mid + 1;
        else r = mid - 1;
    }

    cout << mn << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
