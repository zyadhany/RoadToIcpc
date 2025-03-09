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

typedef ll item;

class SegmentTree
{
public:
    void set(int index, int value) {
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

    item merge(item &a, item &b) {
        item res = (a + b) % MODE;
        return (res);
    }

    void set(int m, int lx, int rx, int pos, int val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] += val;
            tree[m] %= MODE;
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
        if (rx < l || r < lx) return 0;
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = {X[lx]};
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
    ll n; 

    cin >> n;

    vp X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first; X[i].second = i;
    }
    sortx(X);
    SegmentTree sg; sg.build(n + 1);
    for (int i = 0; i <= n; i++)
    {
        sg.set(i, 1);
    }
    
    ll at = 0;
    ll sol = 0;
    for (int i = 0; i < n; i++)
    {
        while (at < X.size() && X[at].first < i)
        {
            sol += sg.getrange(0, X[at].second - 1);
            sg.set(X[at].second, -1);
            at++;
        }
        
        cout << sol << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
