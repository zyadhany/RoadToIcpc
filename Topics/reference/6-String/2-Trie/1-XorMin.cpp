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
        if (tree[m].next[re] != -1 && tree[tree[m].next[re]].val)
           return get(tree[m].next[re], k, idx - 1);
        return get(tree[m].next[!re], k, idx - 1) | (1ll << idx);
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


// Array not vector
const int MXN = 5e6;
int curtree = 0;
trie_node tree[MXN];

Trie() {tree[0]=trie_node(); curtree = 1;}
void add(ll m, ll n, ll idx, ll v) {
    tree[m].val += v;
    if (idx == -1) return;
    int re = (n >> idx) & 1;
    if (tree[m].next[re] == -1) {
        tree[m].next[re] = curtree;
        tree[++curtree]=trie_node();
    }
    add(tree[m].next[re], n, idx - 1, v);
}
