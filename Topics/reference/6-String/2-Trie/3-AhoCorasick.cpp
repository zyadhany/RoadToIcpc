
const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    vi ind; // ind of pattern

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

const int MXTRIE = 3e6;
int curnd = 0;
Vertex t[MXTRIE];

struct AhoCorasick {
    void add_string(string const& s, int ind = -1) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = curnd;
                t[++curnd] = Vertex(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].output = true;
        t[v].ind.push_back(ind);
    }

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }
    int go(int v, char ch) {
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }

    AhoCorasick() {
        t[0] = Vertex();
        curnd = 1;
    }
};