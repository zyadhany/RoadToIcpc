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


typedef long long item;

class SegmentTree
{
public:
    void set(int l, int r, int value) {
        set(0, 0, size - 1, l, r, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, -1);
    }

    void build(vector<item>& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, -1);

        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item a, item b) {
        item res = a + b;
        return (res);
    }

    void checkLazy(int m, ll lx, ll rx) {
        if (lazy[m] == -1) return;
        tree[m] = lazy[m] * (rx - lx + 1);
        
        if (lx != rx) {
            lazy[2 * m + 1] = lazy[m];
            lazy[2 * m + 2] = lazy[m];
        }

        lazy[m] = -1;
    }

    void set(int m, int lx, int rx, int l, int r, int val) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return;
        if (l <= lx && rx <= r)
        {
            lazy[m] = val;
            checkLazy(m, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, l, r, val);
        set(m * 2 + 2, mid + 1, rx, l, r, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        checkLazy(m, lx, rx);
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

vi MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vi Z(n, -1);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first >= X[i]) {
            Z[s.top().second] = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}


void solve(int tc) {
    ll n, k, q;

    cin >> n >> k >> q;

    vi X(n), res(n + 2);
    mi Z;
    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    ll at = 0;
    multiset<ll> st;

    for (int i = 0; i < n; i++)
        st.insert(0);
    
    for (int i = 0; i < n; i++)
    {
        st.erase(st.find(Z[X[i] - i]));
        Z[X[i] - i]++;
        st.insert(Z[X[i] - i]);
        if (i - at + 1 == k) {
            auto it = st.end(); it--;
            res[at + 1] = k - *it;
            
            st.erase(st.find(Z[X[at] - at]));
            Z[X[at] - at]--;
            st.insert(Z[X[at] - at]);
            at++;
        }
    }

    SegmentTree sg;
    sg.build(res);

    vector<vp> Query(n + 1);
    vi sol(q);

    for (int i = 0; i < q; i++)
    {
        ll l, r; cin >> l >> r;
        Query[l].push_back({r, i});
    }
    
    auto mono = MonomaticStack(res);
    
    for (int i = n - k + 1; i >= 1; i--)
    {
        sg.set(i, mono[i] - 1, res[i]); 
        for (auto m : Query[i]) {
            sol[m.second] = sg.getrange(i, m.first - k + 1);
        }
    }
    
    for (int i = 0; i < q; i++)
        cout << sol[i] << '\n';    
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
