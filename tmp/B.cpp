#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>

#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

typedef pl item;

class SegmentTree
{
public:

    void set(int index, pl value) {
        set(0, 0, size - 1, index, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, {INT32_MAX, 0});
    }

private:
    int size;
    vector<item> tree;

    item merge(item a, item b) {
        item res = min(a, b);
        return (res);
    }

    void set(int m, int lx, int rx, int pos, pl val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = min(val, tree[m]);
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
        if (rx < l || r < lx) return {INT32_MAX, 0};
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }
};

vector<pair<ll, ll>> generateRandomPairs(ll n, ll minVal, ll maxVal) {
    vector<pair<ll, ll>> vec;
    random_device rd;
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dis(minVal, maxVal);
    
    for (ll i = 0; i < n; i++) {
        ll first = dis(gen);
        ll second = dis(gen);
        vec.emplace_back(first, second);
    }
    return vec;
}

int cnt = 0;
void solve(ll tc) {
    ll n;
    set<ll> cst;

    cin >> n;
    n = 1000;
    auto X = generateRandomPairs(n, -10000000, 10000000);
    for (auto [a, b] : X) cst.insert({a, b});
    
    if (!n) exit(0);

    // vp X(n);
    // for (int i = 0; i < n; i++)
    // {
    //     string s, t; cin >> s >> t;
    //     X[i].first = stof(s) * 100;
    //     X[i].second = stof(t) * 100;
    //     cst.insert({X[i].first, X[i].second});
    // }
    sortx(X);

    ll imn = INT32_MAX;
    ll ia, ib;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll dis = abs(X[i].first - X[j].first) + abs(X[i].second - X[j].second);
            if (dis <= imn) {
                imn = dis, ia = i, ib = j;
            }
        }
        
    }
    
    // cout << imn << "|\n";
    // cout << fixed << setprecision(2) << X[ia].first/100.0 << ' ' << X[ia].second/100.0 << ' ';
    // cout << fixed << setprecision(2) << X[ib].first/100.0 << ' ' << X[ib].second/100.0 << '\n';


    mi CO;
    vi IND;
    for (auto a : cst) {
        CO[a] = IND.size();
        IND.push_back(a);
    }
    
    SegmentTree sgpos, sgneg;
    sgpos.build(IND.size());
    sgneg.build(IND.size());
    ll mn = INT32_MAX;
    ll inda, indb;

    for (int i = 0; i < n; i++) {
        ll x = X[i].first, y = X[i].second;
        ll l = CO[x], r = CO[y];
        
        auto [a, ia] = sgneg.getrange(0, r);
        auto [b, ib] = sgpos.getrange(r, IND.size()-1);
        
        if (x+y+a <= mn) {
            mn = x+y+a;
            inda = ia;
            indb = i;
        }
        if (x-y+b <= mn) {
            mn = x-y+b;
            inda = ib;
            indb = i;
        }

        sgpos.set(r, {y-x, i});
        sgneg.set(r, {-y-x, i});
    }

    // cout << mn << "|\n";
    // cout << fixed << setprecision(2) << X[inda].first/100.0 << ' ' << X[inda].second/100.0 << ' ';
    // cout << fixed << setprecision(2) << X[indb].first/100.0 << ' ' << X[indb].second/100.0 << '\n';

    if (pl(ia, ib) != pl(inda, indb)) {
        cout << "NO\n";
        for (auto [a, b] : X) {
            cout << a << ' ' << b << "|\n";
        }
    } cnt++;
    // cout << X[0].first << ' ' << X[0].second << "|\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    cin >> size;
    for (int tc = 1; tc <= size; tc++){
        // while (true) 
        solve(tc);
       // if (tc != size) cout << '\n';
    }

    cout << cnt << "|\n";
}
