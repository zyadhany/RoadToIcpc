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


const int MODE = 998244353;

using namespace std;    

struct cow
{
    int x, y;
    char dir;
};

pl collsion(cow a, cow b) {
    if (a.dir == b.dir) {
        if (a.dir == 'N')
            swap(a.x, a.y), swap(b.x, b.y);
        if (b.y != a.y || b.x <= a.x) return {-1, -1};
        return {b.x - a.x, 0};
    }
    if (a.dir == 'N') {
        swap(a.x, a.y), swap(b.x, b.y);
    }
    if (a.x > b.x || b.y > a.y) return {-1, -1};
    ll l = b.x - a.x;
    ll r = a.y - b.y;

    if (r >= l) return {-1, -1};

    return {l, r};
}

void solve(int tc) {
    ll n;

    cin >> n;

    vector<cow> X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i].dir >> X[i].x >> X[i].y;

    vii col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            pl re = collsion(X[i], X[j]);
            if (re.first != -1) {
                col.push_back({re.first, re.second, i, j});
            }
        }
    }
    sortx(col);
    vi Z(n, INT32_MAX);
    vi par(n);
    vi C(n);

    for (int i = 0; i < n; i++)
        par[i] = i;    

    for (int i = 0; i < col.size(); i++)
    {
        ll t = col[i][0];
        ll tnd = col[i][1];
        ll a = col[i][2];
        ll b = col[i][3];
        if (Z[a] != INT32_MAX) continue;
        if (Z[b] >= tnd) {
            Z[a] = t;
            par[a] = b;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        ll at = i;
        while (at != par[at])
        {
            at = par[at];
            C[at]++;
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << C[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("mountains.in", "r", stdin);
    //freopen("mountains.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
