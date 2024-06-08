
class Trie
{
public:
    struct trie_node
    {
        ll val;
        vector<int> next;

        trie_node() {
            val = -1;
            next.resize(26, -1);
        }
    };

    ll get(string &s) {
        return (get(0, s, 0));
    }

    void add(string &s) {
        add(0, s, 0);
    }

    Trie() {
        tree.resize(1, trie_node());
    }

private:
    vector<trie_node> tree;

    ll get(ll at, string &s, ll k) {
        if (!s[k]) return (tree[at].val);
        int nxt = s[k] - 'a';
        if (tree[at].next[nxt] == -1) return (-1);
        return get(tree[at].next[nxt], s, k + 1);
    }

    void add(ll at, string &s, ll k) {
        if (!s[k]) {
            tree[at].val = 1;
            return;
        }
        int nxt = s[k] - 'a';

        if (tree[at].next[nxt] == -1) {
            tree[at].next[nxt] = tree.size();
            tree.push_back(trie_node());
        }

        add(tree[at].next[nxt], s, k + 1);
    }
};
