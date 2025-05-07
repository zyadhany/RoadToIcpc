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


class Trie
{
public:
    struct trie_node
    {
        ll val; 
        int next[26];
        trie_node() {
            val = 0;
            memset(next, -1, sizeof(next));
        }
    };
    void get(string &s, vi &dp) {return (get(0, s, dp, 0));}
    void add(string &s) {add(0, s, 0);}
    Trie() {tree.resize(1, trie_node());}
private:
    vector<trie_node> tree;

    void get(ll m, string &s, vi &dp, ll idx) {
        dp[idx] += tree[m].val;
        if (!s[idx]) return;
        int nxt = s[idx] - 'a';
        if (tree[m].next[nxt] == -1) return;
        get(tree[m].next[nxt], s, dp, idx + 1);
    }

    void add(ll m, string &s, ll idx) {
        if (!s[idx]) {
            tree[m].val++;
            return;
        }
        int nxt = s[idx] - 'a';
        if (tree[m].next[nxt] == -1) {
            tree[m].next[nxt] = tree.size();
            tree.push_back(trie_node());
        }
        add(tree[m].next[nxt], s, idx + 1);
    }
};


const int MODE = 1e9+7;

void solve(int tc)  {
    string s;
    cin >> s;

    Trie tr;
    ll q; cin >> q;
    while (q--)
    {
        string t; cin >> t;
        tr.add(t);
    }
    
    ll n = s.size();
    vi dp(n+1);
    dp[n]=1;

    for (int i = n - 1; i >= 0; i--)
    {
        string t = s.substr(i,n-i);
        vi dp2(t.size()+1);

        tr.get(t, dp2);
        for (int j = 0; j <= t.size(); j++)
        {
            dp[i] = (dp[i]+dp[i+j]*dp2[j]) % MODE;
        }
    }
    
    cout << dp[0];
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("dec.in", "r", stdin);
    // freopen("dec.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}