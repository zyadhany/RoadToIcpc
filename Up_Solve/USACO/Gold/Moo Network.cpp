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

const int MODE = 1e9 + 7;

using namespace std;

const int MXN = 1e6+10;
int PAR[MXN], R[MXN];

ll get(ll n) {
    if (n == PAR[n]) return n;
    return PAR[n]=get(PAR[n]); 
}

bool add(ll u, ll v) {
    u = get(u), v = get(v);
    if (u == v) return 0;
    if (R[v] > R[u]) swap(u,v);
    R[u] += (R[v] == R[u]);
    PAR[v] = u;
    return 1;
}

void INIT() {
    for (int i = 0; i < MXN; i++)
    {
        PAR[i] = i;
        R[i] = 0;
    }
    
}

void solve(int tc) {
    ll n;

    cin >> n;

    vp X(n);
    vector<vp> Y(11);
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        X[i] = {x, y};
        Y[y].push_back({x, i});
    }
    for (int i = 0; i < Y.size(); i++)
    {
        sortx(Y[i]);
    }
    
    vii E;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            ll ind = lower_bound(all(Y[j]), pl(X[i].first, 0)) - Y[j].begin();
            if (j == X[i].second) ind++;
            if (ind < Y[j].size()) {
                ll v = Y[j][ind].second;
                ll dist = (X[v].first - X[i].first) * (X[v].first - X[i].first);
                dist += (X[v].second - X[i].second) * (X[v].second - X[i].second);
                E.push_back({dist, i, v});
            }
        }
    }
    ll res = 0;
    INIT();
    sortx(E);
    for (auto e : E) {
        if (add(e[1], e[2])) res += e[0];
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("math.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
