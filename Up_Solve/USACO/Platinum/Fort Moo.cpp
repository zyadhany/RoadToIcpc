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

typedef long long item;
/*
struct item
{
    int val;

    item(){
        val = 0;
    }
};
*/

class SegmentTree
{
public:
    int get(ll ind, ll k) {
        return get(0, 0, size - 1, k, ind);
    }
    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, 0);
    }

    void build(vector<item>& X) {
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
        item res= max(a, b);
        return (res);
    }

    ll get(int m, int lx, int rx, int k, int re) {
        if (tree[m] < k || rx < re)
            return (-1);
        if (lx == rx)
            return (lx);
    
        ll mid = (lx + rx) / 2, s1, s2;
        s1 = tree[m * 2 + 1];
        s2 = tree[m * 2 + 2];
    
        ll res = get(m * 2 + 1, lx, mid, k, re);
    
        if (res != -1)
            return (res);
    
        return (get(m * 2 + 2, mid + 1, rx, k, re));
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


void solve(int tc) {
    ll n, m;
    
    cin >> n >> m;

    vector<string> X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    vector<vi> R(n, vi(m));
    vector<vi> C(n, vi(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!i) R[i][j] = (X[i][j] == '.');
            else if (X[i][j] == '.') R[i][j] = R[i-1][j] + 1;

            if (!j) C[i][j] = (X[i][j] == '.');
            else if (X[i][j] == '.') C[i][j] = C[i][j-1] + 1;
        }
    }
    
    vector<SegmentTree> SG(n);

    for (int i = 0; i < n; i++)
    {
        SG[i].build(R[i]);
    }
    
    ll sol = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int a = i; a > i-R[i][j]; a--)
            {
                ll l = j - min(C[a][j], C[i][j]) + 1;
                ll b = SG[i].get(l, i-a+1);
                if(b == -1) continue;
                ll re = (j-b+1) * (i-a+1);
                sol = max(sol, re);
            }
        }        
    }
    
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("fortmoo.in", "r", stdin);
    freopen("fortmoo.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
