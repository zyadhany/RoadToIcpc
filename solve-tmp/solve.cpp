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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
 
const int MODE = 1e9 + 7;
 
using namespace std;




typedef long long item;

class SegmentTreeMAX
{
public:

    void set(int index, pl value) {
        set(0, 0, size - 1, index, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(vector<item>& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;

    item merge(item a, item b) {
        item res = max(a, b);
        return (res);
    }

    void set(int m, int lx, int rx, int pos, pl val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            while (tree[m] > 1 && val.second) {
                tree[m] = (tree[m] + val.first - 1) / val.first;
                val.second--;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, pos, val);
        set(m * 2 + 2, mid + 1, rx, pos, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vector<item>& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = X[lx];
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

vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1],
               table[i + (1 << (j - 1))][j - 1]);

    return (table);
}
 
long long query(vii &table, int L, int R) 
{ 
    int j = (int)log2(R - L + 1); 
    return min (table[L][j], table[R - (1 << j) + 1][j]);
}

ll req(vi &X, vi &Y, map<ll, vi> &mpind, SegmentTreeMAX &sg, vii &table, int l, int r) {
    if (l > r) return 0;
    ll mx = sg.getrange(l, r);
    ll mn = query(table, l, r);
    if (mx == 1) return 0;
    ll sol = (mx + mn - 1) / mn;


    ll mxindval = 0;
    vi &ind = mpind[mn];
    ll st = lower_bound(all(ind), l) - ind.begin();

    for (int i = st; i < ind.size() && ind[i] <= r; i++){
        mxindval = max(mxindval, sg.getrange(ind[i], ind[i]));
    }


    // {div, l, r}
    vii RAN;

    ll prev = l;
    for (int i = st; i < ind.size() && ind[i] <= r; i++) {
        if (ind[i] == prev) {
            prev++;
            continue;
        }
        ll mxrange = sg.getrange(prev, ind[i] - 1);
        mxrange = (mxrange + mn - 1) / mn;
        RAN.push_back({mxrange, prev, ind[i] - 1});
        prev = ind[i] + 1;
    }
    if (prev <= r) {
        ll mxrange = sg.getrange(prev, r);
        mxrange = (mxrange + mn - 1) / mn;
        RAN.push_back({mxrange, prev, r});
    }
    sortx(RAN);

    ll summprev = 0;
    ll got = (mxindval + mn - 1) / mn;

    for (int i = l; i <= r; i++)
        sg.set(i, make_pair(mn, got));

    for (int i = 0; i < RAN.size(); i++)
    {
        summprev += req(X, Y, mpind, sg, table, RAN[i][1], RAN[i][2]);
        if (summprev <= RAN[i][0] - got) continue;
        ll nd = RAN[i][0] - got;
        summprev = 0;
        
        for (int j = i + 1; j < RAN.size(); j++)
            for (int k = RAN[j][1]; k <= RAN[j][2]; k++)
                sg.set(k, make_pair(mn, nd));

        got += nd;
    }
    return min(sol, got + summprev);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    vi Y(n);
    map<ll, vi> mpind;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 0; i < n; i++) {
        cin >> Y[i];
        mpind[Y[i]].push_back(i);
    }
    
    SegmentTreeMAX sg; sg.build(X);
    vii table = buildSparseTable(Y);

    cout << req(X, Y, mpind, sg, table, 0, n - 1) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    // freopen("sumdiv.in", "r", stdin);
    // freopen("sumdiv.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}