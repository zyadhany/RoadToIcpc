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
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; continue;}
#define NO {cout << "NO\n"; continue;}

const int MODE = 1e9 + 7;

using namespace std;

/*
* get ind of first greater element to right for each element
* if you want to make it to left, reverse loop (n - 1 -> 0).
* you can change oppration:
* >, first element less than.
* <=, first element greater than or equal.
*/
vi MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vi Z(n, n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second] = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}

vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = max(table[i][j - 1],
               table[i + (1 << (j - 1))][j - 1]);

    return (table);
}

// optmization to get in O(1)
long long query(vii &table, int L, int R) 
{
    int j = (int)log2(R - L + 1); 
    return max(table[L][j], table[R - (1 << j) + 1][j]);
}

void solve(ll test) {
    ll n, q;
    string s;

    cin >> n >> q;
    cin >> s;

    vi pref(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '*') pref[i] = 1;
        else pref[i] = -1;
        pref[i] += pref[i - 1];
    }

    auto Z = MonomaticStack(pref);
    auto st = buildSparseTable(pref);

    while (q--)
    {
        ll l, r; cin >> l >> r;
        ll re = Z[l - 1];
        ll mx = query(st, l, min(re, r)) - pref[l - 1];
        
        ll res;

        if (re > r) res = mx + 1; // don't cont zero
        else if (mx == -1) res = 2; // 1 and 0
        else res = mx + 2; // 0, 1 and count
        
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}