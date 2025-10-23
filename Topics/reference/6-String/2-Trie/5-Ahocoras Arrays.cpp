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

const int MAX_N = 1e6;
const int SIGMA = 26;

int nodes = 1;
int trie[MAX_N][SIGMA];
int fail[MAX_N];  // fail[u] = the failure link for node
vi seen[MAX_N];  // check if a node has been visited in trie
int ans[MAX_N];   // ans[i] = the number of occurrences of word i

// leaf[node] stores the indices of the words ending in node
vector<int> leaf[MAX_N];
vector<int> g[MAX_N];

void init() {
    for (int i = 0; i <= nodes; i++)
    {
        fill(trie[i], trie[i] + SIGMA, 0);
        fail[i] = 0;
        ans[i] = 0;
        seen[i].clear();
        leaf[i].clear();
        g[i].clear();
    }
    nodes = 1;
}

/** Add a word to the trie */
void add_word(const string &word, const int &idx) {
    int node = 1;
    for (char ch : word) {
        if (trie[node][ch-'a'] == 0) { trie[node][ch-'a'] = ++nodes; }
        node = trie[node][ch-'a'];
    }
    leaf[node].push_back(idx);
}

/** BFS to building the failure and suffix links */
void build() {
    queue<int> q;
    int node = 1;
    fail[node] = 1;
    for (int i = 0; i < SIGMA; i++) {
        if (trie[node][i]) {
            fail[trie[node][i]] = node;
            q.push(trie[node][i]);
        } else {
            trie[node][i] = 1;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < SIGMA; i++) {
            if (trie[node][i]) {
                fail[trie[node][i]] = trie[fail[node]][i];
                q.push(trie[node][i]);
            } else {
                trie[node][i] = trie[fail[node]][i];
            }
        }
    }
    for (int i = 2; i <= nodes; i++) { g[fail[i]].push_back(i); }
}


void solve(int n) {
    init();
    string s;
    vi X(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        add_word(s, i);
        X[i] = s.size();
    }
    build();

    getline(cin, s);

    vii res(n);    
    for (int i = 0, j = 1; i < s.size(); i++)
    {
        j = trie[j][s[i]-'a'];
        int prv = j;
        for (int p = j; p > 1; p = fail[p]) {
            if (leaf[p].empty()) continue;
            if (prv != p) fail[prv] = p;
            for (auto idx : leaf[p]) {
                res[idx].push_back(i-X[idx]+1);
            }
            prv = p;
        }
        fail[prv] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (auto a : res[i]) cout << a << ' ';
        cout << '\n';
    }
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
