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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


class SegmentTree
{
public:

    pl getrange(int l, int r, ll k, ll cnt) {
        return (getrange(0, 0, size - 1, l, r, k, cnt));
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

    pl getitemval(item& a, ll k) {
        ll l;
        l = lower_bound(all(a.arr), k) - a.arr.begin();
        return (a.pref[l]);
    }

    item merge(item& a, item& b) {
        item res = a;
        for (int i = 0; i < b.arr.size(); i++)
            res.arr.push_back(b.arr[i]);
        sortx(res.arr);

        res.pref.assign(res.arr.size() + 1, 0);

        for (int i = 1; i <= res.arr.size(); i++)
            res.pref[i] = res.pref[i - 1] + res.arr[i - 1];

        return (res);
    }

    pl getrange(int m, int lx, int rx, int l, int r, ll k, ll cnt) {
        if (rx < l || r < lx) return {0, -1};
        if (l <= lx && rx <= r) {

            return (getitemval(tree[m], k));
        }

        int mid = (lx + rx) / 2;
        pl s1, s2, res;

        s1 = getrange(m * 2 + 1, lx, mid, l, r, k, cnt);

        if (s1.second == cnt) return (s1);
        return getrange(m * 2 + 2, mid + 1, rx, l, r, k, cnt - s1.second);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size())
                tree[m].arr.push_back(X[lx]), tree[m].pref.push_back(X[lx]);
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
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
