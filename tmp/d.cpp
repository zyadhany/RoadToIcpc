#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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

struct query{
    int u, v, c, r;
    query(ll u, ll v, ll c, ll r) : u(u), v(v), c(c), r(r){}
    bool operator<(const query& q) {
        return c < q.c;
    }
};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;
    vector<query> Q;
    
    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        ll u, v, c, r; cin >> u >> v >> c >> r;
        u--, v--;
        Q.push_back(query(u, v, c, r));
    }
    sortx(Q);

    vector<vector<vector<query>>> Y(n, vector<vector<query>>(n));

    for (auto p : Q) {
        while (!Y[p.u][p.v].empty() && Y[p.u][p.v].back().r >= p.r) Y[p.u][p.v].pop_back();
        Y[p.u][p.v].push_back(p);
    }

    ll l = 1, r = 1e18;
    while (l < r)
    {
        ll mid = (l+r)>>1;
        bool isok = 1;

        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                cout << mid << "|\n"; 
                for (auto &p : Y[u][v]) {
                    ll tank = mid, ref = 0;

                    for (int h = u+1; h <= v; h++)
                    {
                        tank -= (X[h]-X[h-1])*p.c;
                        if (tank < 0) {
                            tank = mid - (X[h]-X[h-1])*p.c;
                            ref++;
                            if (ref > p.r || tank < 0) {
                                isok = 0;
                                goto out;
                            }
                        }
                    }
                }
            }
        }
        out:;

        if (isok) r = mid;
        else l = mid+1;
    }
    
    cout << l << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("cbarn.in", "r", stdin);
    // freopen("cbarn.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}