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

const int MODE = 998244353;

using namespace std;

ll MXN = 2e5 + 1;
vi PAR(MXN);
vi SZ(MXN, 1);

ll get(ll n) {
    if (n == PAR[n]) return n;
    return PAR[n] = get(PAR[n]);
}

void add(ll u, ll v) {
    ll a = get(u), b = get(v);
    if (a == b) return;
    PAR[b] = a;
    SZ[a] += SZ[b];
}

void INIT() {
    for (int i = 0; i < MXN; i++)
        PAR[i] = i;    
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi Q(n);
    for (int i = n - 1; i >= 0; i--)
        cin >> Q[i];
    
    vi res(1,1);
    
    vi open(n + 1);
    ll st = Q[0];
    open[st] = 1;
    for (int i = 1; i < n; i++)
    {
        for (auto neg : adj[Q[i]]) if (open[neg]) {
            add(neg, Q[i]);
        }
        open[Q[i]] = 1;
        res.push_back(SZ[get(st)] == i + 1);
    }
    
    reverse(all(res));
    for (auto a : res) if (a) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    INIT();

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
