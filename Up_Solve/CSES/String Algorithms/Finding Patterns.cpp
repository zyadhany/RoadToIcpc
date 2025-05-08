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
 
 
const int sigma = 26;
struct AhoVertex {
    int next[sigma];
    
    int link = -1; // failer link
    int p=-1; // parent node
    char ch='\0'; // char from parent
    vi adj;
 
    bool exist=0;
    vi IDX; // occuorance index
 
    AhoVertex(int p=-1, char ch='\0'): p(p), ch(ch) {
        memset(next, -1, sizeof(next));  
    }
};
 
const int MXTRIE = 1e6;
int curnd = 0;
AhoVertex tree[MXTRIE];
 
struct AhoCorasick {
    void add_string(string &s, int ind) {
        int v = 0;
        for (auto ch : s) {
            int c = ch - 'a';
            if (tree[v].next[c] == -1) {
                tree[v].next[c] = curnd;
                tree[++curnd] = AhoVertex(v, ch);
            }
            v = tree[v].next[c];
        }
        tree[v].exist = true;
        tree[v].IDX.push_back(ind);
    }
 
    void build() {
        queue<ll> q;
        tree[0].link = 0;
        for (int i = 0; i < sigma; i++)
        {
            if (tree[0].next[i] != -1) {
                tree[tree[0].next[i]].link = 0;
                q.push(tree[0].next[i]);
            } else tree[0].next[i] = 0;
        }
        
        while (!q.empty())
        {
            ll v = q.front(); q.pop();
            for (int i = 0; i < sigma; i++)
            {
                if (tree[v].next[i] != -1) {
                    tree[tree[v].next[i]].link = tree[tree[v].link].next[i];
                    q.push(tree[v].next[i]);
                } else tree[v].next[i] = tree[tree[v].link].next[i];
            }
        }
    
        for (int i = 1; i < curnd; i++) { 
            tree[tree[i].link].adj.push_back(i);
        }    
    }
 
    ll dfs(vi& seen, vi& vis, int v) {
        ll cnt = seen[v];
        for (auto x : tree[v].adj) {
            cnt += dfs(seen, vis, x);
        }
        for (auto x : tree[v].IDX) vis[x] = cnt;
        return cnt;
    }
        
    vi search(string const& s, int n) {
        int v = 0;
        vi vis(n, 0);
        vi seen(curnd, 0);
        for (auto c : s) {
            v = tree[v].next[c - 'a'];
            seen[v]++;
        }
 
        dfs(seen, vis, 0);
        return vis;
    }
    
    AhoCorasick() {
        tree[0] = AhoVertex(); curnd=1;
    }
};
 
 
void solve(int tc)  {
    string s;
    cin >> s;
 
    ll n; cin >> n;
    vector<string> X(n);
    AhoCorasick ac;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        ac.add_string(X[i], i);
    }
 
    ac.build();
    vi vis = ac.search(s, n);
    for (auto x : vis) if (x) cout << "YES\n";
    else cout << "NO\n";
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
