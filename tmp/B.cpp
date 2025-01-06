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


/**
 * usage:-
 * creat tree element.
 * SegmentTree sg;
 * 
 * Functions you can use:
 * @set: set index or range to value.
 * @geteange: get value of given range.
 * @build: build tree with given vector or size.
 * 
 * make sure to look at item typedef.
 * you can change merge function to change it's oppration.
 * it you want to make change to segment work in checkLazy().
*/

typedef pair<pl, pl> item;

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
        lazy.assign(size * 2, 0);
    }

    void build(vector<ll>& X) {
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

    item merge(item a, item b) {
        item res;
        if (a.first.first > b.first.first) res.first = a.first;
        else res.first = b.first;

        if (a.second.first < b.second.first) res.second = a.second;
        else res.second = b.second;
        return (res);
    }

    void set(int m, int lx, int rx, int pos, int val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = {{val, pos}, {val, pos}};
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
        if (rx < l || r < lx) return {{INT_MIN, -1}, {INT_MAX, -1}};
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vector<ll>& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = {{X[lx], lx,}, {X[lx], lx}};
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

void clc(SegmentTree& sgl, SegmentTree& sgr, vi& L, vi& R, vii &adj, vector<pair<pl, pl>>& res, multiset<ll>& st, ll k) {
    auto ZZ =adj[k];
    adj[k].clear();
    for (auto i : adj[k])
    {
        // if (res[i].first.second == k) {
        //     st.erase(st.find(res[i].first.first));
        //     res[i].first = {-1, -1};
        // }
        // if (res[i].second.second == k) {
        //     st.erase(st.find(res[i].second.first));
        //     res[i].second = {-1, -1};
        // }
        clc(sgl, sgr, L, R, adj, res, st, i);
    }
    if (res[k].first.first != -1) {
        st.erase(st.find(res[k].first.first));
        res[k].first = {-1, -1};
    }
    if (res[k].second.first != -1) {
        st.erase(st.find(res[k].second.first));
        res[k].second = {-1, -1};
    }

    if (k) {
        auto a = sgl.getrange(0, k - 1);
        pl mn = a.second;
        ll vmx;
        vmx = L[k] - mn.first;
        // if (k == 7) cout << mn.first << ' ' << L[k] << ' ' << vmx << '\n';
        res[k].first = {vmx, mn.second};
        adj[mn.second].push_back(k);
        st.insert(vmx);
    }
    if (k < L.size() - 1) {
        auto a = sgr.getrange(k + 1, L.size() - 1);
        pl mn = a.second;
        ll vmx;
        vmx = R[k] - mn.first;
        res[k].second = {vmx, mn.second};
        adj[mn.second].push_back(k);
        st.insert(vmx);
    }


    if (k) {
        auto a = sgr.getrange(0, k - 1);
        pl mx = a.first;
        ll vmn;
        vmn = mx.first - R[k];


        if (res[mx.second].second.first < vmn) {
            if (res[mx.second].second.first != -1) {
                st.erase(st.find(res[mx.second].second.first));
            }
            res[mx.second].second = {vmn, k};
            adj[k].push_back(mx.second);
            st.insert(vmn);
        }
    }
    if (k < L.size() - 1) {
        auto a = sgl.getrange(k + 1, L.size() - 1);
        pl mx = a.first;
        ll vmn;
        vmn = mx.first - L[k];
        
        if (res[mx.second].first.first < vmn) {
            if (res[mx.second].first.first != -1) {
                st.erase(st.find(res[mx.second].first.first));
            }
            res[mx.second].first = {vmn, k};
            adj[k].push_back(mx.second);
            st.insert(vmn);
        }
    }
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vi L(n), R(n);
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        L[i] = a - i;
        R[i] = a + i;
    }
    SegmentTree sgl, sgr;
    sgl.build(L);
    sgr.build(R);

    multiset<ll> st;
    st.insert(0);
    vector<pair<pl, pl>> res(n, {{-1, -1}, {-1, -1}});
    vii adj(n);

    for (int i = 0; i < n; i++)
    {
        clc(sgl, sgr, L, R, adj, res, st, i);
    }

    cout << *prev(st.end()) << '\n';

    // return;
    while (q--)
    {
        ll p, x;
        cin >> p >> x;
        p--;
        
        L[p] = x - p;
        R[p] = x + p;
        sgl.set(p, L[p]);
        sgr.set(p, R[p]);
        clc(sgl, sgr, L, R, adj, res, st, p);

        // if (q == 0)
        // for (auto i : res)
        // {
        //     cout << i.first.first << ' ' << i.first.second << " | " << i.second.first << ' ' << i.second.second << '\n';
        // }
        cout << *prev(st.end()) << '\n';
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
