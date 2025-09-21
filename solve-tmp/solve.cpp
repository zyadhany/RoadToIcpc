// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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

const int lg = 33;
const ll INF = 1e16;

#include <bits/stdc++.h>
using namespace std;



typedef long long item;
struct item
{
    ll val, l, r, mx, cnt;

    item(){
        val = cnt = 0;
        l = r = mx = -1;
    }
    item(ll ind, ll v) {
        l = r = ind;
        val = cnt = 1;
        mx = max(v, ind);
    }
};

class SegmentTree
{
public:

    void set(int index, ll value) {
        set(0, 0, size - 1, index, value);
    }
    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }
    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, 0);
    }

    void build(vi& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, 0);

        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item &a, item &b) {
        item res;
        res.val = a.val + b.val;

        ll lim = b.r - b.cnt + 1;
        
        res.l = a.l;
        res.r = b.r;
        return (res);
    }

    void set(int m, int lx, int rx, int pos, ll val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = item(lx, val);
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
        if (rx < l || r < lx) return item();
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = item(lx, X[lx]);
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
    ll n, q;

    cin >> n >> q;

    vi P(n), S(n);
    for (int i = 0; i < n; i++)
    {
        cin >> P[i]; P[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> S[i]; S[i]--;
    }
    

    vi PS(n), SP(n);
    for (int i = 0; i < n; i++) {
        PS[P[i]] = S[i];
        SP[S[i]] = P[i];
    }

    while (q--)
    {
        ll ty, l, r;
        cin >>ty >> l >> r;
        l--, r--;

        sg.set(P[l], PS[P[r]]);
        sg.set(P[r], PS[P[l]]);
        swap(PS[P[l]], PS[P[r]]);
        swap(SP[S[l]], SP[S[r]]);
        if (ty == 1) {
            swap(P[l], P[r]);
        } else {
            swap(S[l], S[r]);
        }

        ll res2 = n * (n-1) / 2;
        res2 += sg.getrange(0, n-1);
        // ll mn = n-1;
        // ll mx = n-1;
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     mn = min(mn, PS[i]);
        //     if (mn == i) {
        //         ll len = mx - mn + 1;
        //         res2 += len * (len + 1) / 2;
        //         // cout << len << "||\n";
        //         mn = mx = i-1;
        //     }
        // }
        cout << res2 << '\n';
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
