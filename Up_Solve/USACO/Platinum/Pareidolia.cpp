#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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
using namespace std;
 
const int MODE = 1e9+7;

ll ssz;
struct Matrix {
    ll a[8][8];
    Matrix() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                a[i][j] = (i==j);
    }
    Matrix(char c, ll pos=0) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                a[i][j] = 0;
                
        if (c=='#');
        else if (c == 'b') {
            a[0][1] = a[1][1] = a[7][1] = 1;
            a[2][2] = a[3][3] = a[4][4]= a[5][5] = a[6][6] = a[7][7] = 1;
        } else if (c == 'e') {
            a[5][0] = a[7][0] = a[0][0] = 1;
            a[1][2] = a[2][2] = 1;
            a[3][3] =  1;
            a[4][4] = 1;
            a[6][6] = 1;
            a[5][6] = ssz - pos;
            a[7][7] = 1;
        } else if (c == 's') {
            a[7][0] = a[0][0] = 1;
            a[1][1] = 1;
            a[2][3] =  1;
            a[4][4] = a[3][4] = 1;
            a[5][5] = 1;
            a[6][6] = 1;
            a[7][7] = 1;
        } else if (c == 'i') {
            a[7][0] = a[0][0] = 1;
            a[1][1] = 1;
            a[2][2] = 1;
            a[3][3] =  1;
            a[5][5] = a[4][5] = 1;
            a[6][6] = 1;
            a[7][7] = 1;
        } else {
            a[7][0] = a[0][0] = 1;
            a[1][1] = 1;
            a[2][2] = 1;
            a[3][3] =  1;
            a[4][4] = 1;
            a[5][5] = 1;
            a[6][6] = 1;
            a[7][7] = 1;
        }
    }

    Matrix operator*(const Matrix &b) const {
        Matrix c('#');
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]);
                }
            }
        }
        return c;
    }
};

typedef Matrix item;

class SegmentTree
{
public:

    void set(int index, char value) {
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

    void build(string& X) {
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

    
    item merge(item &a, item&b) {
        return a * b;
    }

    void set(int m, int lx, int rx, int pos, char val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = item(val, pos);
            return;
        }
        int mid = (lx + rx) / 2;
        set(m * 2 + 1, lx, mid, pos, val);
        set(m * 2 + 2, mid + 1, rx, pos, val);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        if (rx < l || r < lx) return item();
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1 = getrange(m * 2 + 1, lx, mid, l, r);
        item s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);
        return merge(s1, s2);
    }

    void build(string& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = item(X[lx], lx);
            return;
        }
        int mid = (lx + rx) / 2;
        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }
};

void solve(int tc)  {
    string s;
    cin >> s;

    ssz = s.size();
    SegmentTree sg;
    sg.build(s);
    
    cout << sg.getrange(0, s.size() - 1).a[7][6] << '\n';
    ll q; cin >> q;
    while (q--)
    {
        ll ind; char c;
        cin >> ind >> c; ind--;
        sg.set(ind, c);
        cout << sg.getrange(0, s.size() - 1).a[7][6] << '\n';
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    // freopen("optmilk.in", "r", stdin);
    // freopen("optmilk.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}
