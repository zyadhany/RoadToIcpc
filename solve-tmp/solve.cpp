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
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;

struct item
{
    vi arr;

    item() {
        arr.assign(0, 0);
    }
};


class SegmentTree
{
public:

    ll getrange(int l, int r, ll k) {
        return (getrange(0, 0, size - 1, l, r, k));
    }

    void build(vi& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    ll getitemval(item& a, ll k) {
        ll l;
        l = upper_bound(all(a.arr), k) - a.arr.begin();
        return (l);
    }

    item merge(item& a, item& b) {
        item res = a;
        for (int i = 0; i < b.arr.size(); i++)
            res.arr.push_back(b.arr[i]);
        sortx(res.arr);

        return (res);
    }


    ll getrange(int m, int lx, int rx, int l, int r, ll k) {
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (getitemval(tree[m], k));

        int mid = (lx + rx) / 2;
        ll s1, s2, res;

        s1 = getrange(m * 2 + 1, lx, mid, l, r, k);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r, k);

        return (s1 + s2);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size())
                tree[m].arr.push_back(X[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }
};


void solve(int tc) {
    ll n, m, q, a, l, r, at, re, k;

    cin >> n >> m >> q;

    vi X(n + 10, INT32_MAX), Z(m);
    vp Y(m);
    SegmentTree sg;

    for (int i = 0; i < m; i++)
        cin >> Y[i].first >> Y[i].second;

    for (ll i = 1; i <= q; i++)
    {
        cin >> a;
        X[a] = min(X[a], i);
    }
    
    sg.build(X);

    for (int i = 0; i < m; i++)
    {
        k = (Y[i].second - Y[i].first) / 2 + 1;
        l = 1, r = q + 1;
        while (l < r)
        {
            at = (l + r) / 2;

            re = sg.getrange(Y[i].first, Y[i].second, at);
            if (re >= k) r = at;
            else l = at + 1;
        }
        if (l > q) Z[i] = -1;
        else Z[i] = l;
    }
    

    for (int i = 0; i < m; i++)
        cout << Z[i] << ' ';
    cout << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
