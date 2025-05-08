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

struct trie_node
{
    ll val;
    int next[2];

    trie_node() {
        val = 0;
        next[0]=next[1]=-1;
    }
};

class Trie
{
public:
    ll get(ll n) {return (get(0, n, SIZE - 1));}
    void add(ll n, ll v) {add(0, n, SIZE - 1, v);} // To remove add with v=-1.
    Trie() {tree.resize(1, trie_node());}
private:
    int SIZE = 32;
    vector<trie_node> tree;

    ll get(ll m, ll k, ll idx) {
        if (idx == -1) return (0);
        int re =  (k >> idx) & 1;
        if (tree[m].next[!re] != -1 && tree[tree[m].next[!re]].val)
           return get(tree[m].next[!re], k, idx - 1) | (1ll << idx);
        return get(tree[m].next[re], k, idx - 1);
    }

    void add(ll m, ll n, ll idx, ll v) {
        tree[m].val += v;
        if (idx == -1) return;
        int re = (n >> idx) & 1;
        if (tree[m].next[re] == -1) {
            tree[m].next[re] = tree.size();
            tree.push_back(trie_node());
        }
        add(tree[m].next[re], n, idx - 1, v);
    }
};


void solve(int tc)  {
    ll n; cin >> n;

    vi X(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        X[i] ^= X[i-1];
    }
    
    Trie tr;
    tr.add(0, 1);
    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, tr.get(X[i]));
        tr.add(X[i], 1);
    }
    
    cout << mx << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    // freopen("dec.in", "r", stdin);
    // freopen("dec.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}
