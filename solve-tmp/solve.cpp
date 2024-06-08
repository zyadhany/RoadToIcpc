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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;

/**
 * Search for int in it's binary represenaion.
 * it search for last digit.
 * you can change SIZE higher or lower range.vector<string>* 
*/


class Trie
{
public:
    map<string, int> Y;
    struct trie_node
    {
        string val;
        int oc;
        vector<int> next;

        trie_node() {
            val = "-1";
            oc = 0;
            next.resize(26, -1);
        }
    };

    string get(string &s) {
        return (get(0, s, 0));
    }

    void add(string &s) {
        Y[s]++;
        add(0, s, 0, Y[s]);
    }

    Trie() {
        tree.resize(1, trie_node());
    }

private:
    vector<trie_node> tree;

    string get(ll at, string &s, ll k) {
        if (!s[k]) return (tree[at].val);
        int nxt = s[k] - 'a';
        if (tree[at].next[nxt] == -1) return (trie_node().val);
        return get(tree[at].next[nxt], s, k + 1);
    }

    void add(ll at, string &s, ll k, ll oc) {
        //cout << k << "|" << endl;
        int re = tree[at].oc;
        
        if (re < oc) tree[at].val = s, tree[at].oc = oc;
        else if (re == oc && s < tree[at].val) tree[at].val = s, tree[at].oc = oc;

        if (!s[k]) {
            return;
        }
        int nxt     = s[k] - 'a';

        if (tree[at].next[nxt] == -1) {
            tree[at].next[nxt] = tree.size();
            tree.push_back(trie_node());
        }

        add(tree[at].next[nxt], s, k + 1, oc);
    }
};


void solve(ll tc) {
    ll n, q;
    string s;
    Trie tr;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        tr.add(s);
    }
    
    cin >> q;
    while (q--)
    {
        cin >> s;
        string t = tr.get(s);
        if (t != "-1") cout << t << ' ' << tr.Y[t] << '\n';
        else cout << "-1\n";
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}