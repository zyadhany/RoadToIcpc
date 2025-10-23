#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
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

const int K = 128;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    vi adj;

    vi ind; // ind of pattern

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

const int MXTRIE = 5e5;
int curnd = 0;
Vertex t[MXTRIE];

struct AhoCorasick {
    void add_string(string const& s, int ind = -1) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = ++curnd;
                t[curnd] = Vertex(v, ch);
            }
            v = t[v].next[c];
        }
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


void solve(int n) {
    AhoCorasick ah;
    string s;
    vi X(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        ah.add_string(s);
        X[i] = s.size();
    }

    getline(cin, s);
    
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n;
    while (cin >> n)
    {
        cin.ignore();
        solve(n);
    }
    


    // cin >> size;
    // for (int i = 1; i <= size; i++)
    //     solve(i);
}
