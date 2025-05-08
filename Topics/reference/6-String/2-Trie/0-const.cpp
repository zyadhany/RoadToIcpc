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
    ll get(string &s) {return (get(0, s, 0));}
    void add(string &s) {add(0, s, 0);}
    Trie() {tree.resize(1, trie_node());}
private:
    vector<trie_node> tree;

    ll get(ll m, string &s, ll idx) {
        if (!s[idx]) return (tree[m].val);
        int nxt = s[idx] - 'a';
        if (tree[m].next[nxt] == -1) return (-1);
        return get(tree[m].next[nxt], s, idx + 1);
    }

    void add(ll m, string &s, ll idx) {
        if (!s[idx]) {
            tree[m].val = 1;
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
