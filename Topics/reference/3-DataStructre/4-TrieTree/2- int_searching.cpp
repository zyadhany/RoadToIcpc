/**
 * Search for int in it's binary represenaion.
 * it search for last digit.
 * you can change SIZE higher or lower range.
 * 
*/

struct trie_node
{
    ll val;
    vector<int> next;

    trie_node() {
        val = -1;
        next.resize(2, -1);
    }
};

class Trie
{
public:
    ll get(ll n) {
        return (get(0, n, SIZE - 1));
    }

    void add(ll n) {
        add(0, n, SIZE - 1);
    }

    Trie() {
        tree.resize(1, trie_node());
    }
private:
    int SIZE = 32;
    vector<trie_node> tree;

    ll get(ll at, ll n, ll k) {
        if (k == -1) return (tree[at].val);
        int re = (n >> k) & 1;
        if (tree[at].next[re] == -1) return (-1);
        return get(tree[at].next[re], n, k - 1);
    }

    void add(ll at, ll n, ll k) {
        if (k == -1) {
            tree[at].val = 1;
            return;
        }
        int re = (n >> k) & 1;

        if (tree[at].next[re] == -1) {
            tree[at].next[re] = tree.size();
            tree.push_back(trie_node());
        }

        add(tree[at].next[re], n, k - 1);
    }
};
