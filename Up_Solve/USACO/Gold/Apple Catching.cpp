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

struct cow
{
    ll l, r, num, typ;
};

bool cmp(cow &a, cow &b) {
    if (a.l != b.l) return a.l < b.l;
    return a.typ > b.typ;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vector<cow> X(n);
    set<ll> ptr;

    for (int i = 0; i < n; i++)
    {
        ll x, t;
        cin >> X[i].typ;
        cin >> t >> x;
        cin >> X[i].num;
        X[i].l = x - t;
        X[i].r = x + t;

        ptr.insert(X[i].l);
        ptr.insert(X[i].r);
    }
    sort(all(X), cmp);

    ll sol = 0;
    mi mp;

    for (int i = 0; i < n; i++)
    {
        if (X[i].typ == 2) {
            mp[X[i].r] += X[i].num;
            continue;
        }

        ll r = X[i].r;
        ll num = X[i].num;
        while (num)
        {
            auto it = mp.lower_bound(r);
            if (it == mp.end()) break;
            
            ll mn = min(num, it->second);
            it->second -= mn;
            num -= mn;
            sol += mn;
            
            if (!it->second) mp.erase(it->first);
        }
    }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("berries.in", "r", stdin);
    //freopen("berries.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
