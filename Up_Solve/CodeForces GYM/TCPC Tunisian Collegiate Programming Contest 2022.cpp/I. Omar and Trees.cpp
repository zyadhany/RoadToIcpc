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
#define YES {cout << "YES\n"; continue;}
#define NO {cout << "NO\n"; continue;}

const int MODE = 1e9 + 7;

using namespace std;

class Graph {
public:
    int size;
    vi vis;
    vii adj;

    vi Travese, Indeg, SubSize;

    ll dfs(int n, int p) {
        ll summ = 1;
        Indeg[n] = Travese.size();
        Travese.push_back(n);
        for (auto neg : adj[n])
            if (neg != p) summ += dfs(neg, n);
        return (SubSize[n] = summ);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        SubSize.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


typedef long long item;

class SegmentTree
{
public:


    void set(int l, int r, ll value) {
        set(0, 0, size - 1, l, r, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
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
        item res = a + b;
        return (res);
    }

    void checkLazy(int m, ll lx, ll rx) {
        if (!lazy[m]) return;
        tree[m] = lazy[m] * (rx - lx + 1ll);
        
        if (lx != rx) {
            lazy[2 * m + 1] = lazy[m];
            lazy[2 * m + 2] = lazy[m];
        }

        lazy[m] = 0;
    }

    void set(int m, int lx, int rx, int l, int r, ll val) {
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

vi prime(1e7 + 10, 0);
vi primes;

void INIT() {
    for (int i = 0; i < prime.size(); i++) prime[i] = i;
    for (int i = 2; i * i <= 1e7; ++i) if (prime[i] == i)
        for (int j = i; j <= 1e7; j += i) prime[j] = i;
    for (int i = 2; i <= 1e7; i++) if(prime[i] == i) primes.push_back(i);
}


void solve(ll test) {
    ll n;

    cin >> n;

    Graph gr(n);
    vi X(n + 1), Z;

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
        gr.addEdge(v, u);
    }
    gr.dfs(1, 0);

    for (auto m : gr.Travese) Z.push_back(X[m]);
    
    SegmentTree sg;
    sg.build(Z);

    ll q; cin >> q;
    while (q--)
    {
        ll opp; cin >> opp;

        if (opp == 1) {
            ll l, r;
            cin >> l >> r;
            ll a = gr.Indeg[l];
            ll b = a + gr.SubSize[l] - 1;
            sg.set(a, b, r);            
        } else
        {
            ll l; cin >> l;
            ll a = gr.Indeg[l];
            ll b = a + gr.SubSize[l] - 1;
            ll summ = sg.getrange(a, b);

            if (summ <= 3) NO;
            if (summ % 2 == 0) YES;
            bool isit = 1;
            
            summ -= 2;
            for (auto p : primes) {
                if (p * p > summ) break;
                if (summ % p == 0) {
                    isit = 0;
                    break;
                }
            }
            
            if (isit) YES;
            NO;
        }   
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    INIT();
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
