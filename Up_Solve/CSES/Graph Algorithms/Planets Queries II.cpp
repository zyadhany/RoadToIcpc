#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
const int MODE = 998244353;
const int MXN = 2e5+10, MXL = 20; 
int LEN[MXN], MTN[MXN], STP[MXN];
int CY[MXN], vis[MXN], PAR[MXN];
int SPT[MXN][MXL];

bool iscycle;
ll cycnd;
ll cur_cycle;

void req(ll n) {
    if (vis[n] == 1) return;
    if (vis[n] == 2) {
        iscycle = 1;
        cycnd = n;
        return;
    }
    vis[n] = 2;

    req(PAR[n]);

    if (iscycle) {
        MTN[n] = LEN[cur_cycle]++;
        STP[n] = 0;
        CY[n] = cur_cycle;
        if (n == cycnd) iscycle = 0;
    } else {
        CY[n] = CY[PAR[n]];
        MTN[n] = MTN[PAR[n]];
        STP[n] = STP[PAR[n]] + 1;
    }
    vis[n] = 1;
}

ll getpw(ll n, ll k) {
    if (SPT[n][k]) return SPT[n][k];
    ll re;
    if (k == 0) re = n;
    else if (k == 1) re = PAR[n];
    else re = getpw(getpw(n, k-1),k-1);
    return SPT[n][k] = re;
}

ll get_kth(ll n, ll k) {
    for (int i = 0; i < MXL; i++) {
        if (k & (1 << i)) n = getpw(n, i+1);
    }
    return n;
}
 
void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> PAR[i];
    }
    
    cur_cycle = 0;
    for (int i = 1; i <= n; i++)
    {
        iscycle = 0;
        cycnd = -1;
        req(i);
        cur_cycle++;
    } 

    while (q--)
    {
        ll u, v; cin >> u >> v;
        ll st = -1;

        if (CY[u] == CY[v]) {
            if (STP[v] == 0) {
                st = (MTN[u]-MTN[v]+LEN[CY[u]])%LEN[CY[u]];
                st += STP[u];
            } else if (STP[u] >= STP[v]) {
                ll p = get_kth(u, STP[u] - STP[v]);
                if (p == v) st = STP[u] - STP[v];
            }
        }

        cout << st << endl;
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
