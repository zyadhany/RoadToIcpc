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

vi req(vi &X, ll m) {
    ll n = X.size();
    vi res(n, -1);

    stack<ll> st;
    for (int i = 0; i < n; i++)
    {
        if (X[i] > 0) st.push(i);
        else if (!st.empty()) {
            ll tp = st.top(); st.pop();
            ll ti = (abs(X[i]) - X[tp]) / 2;
            res[i] = res[tp] = ti;
        }
    }

    ll lsl = -1, lsr = -1;
    for (int i = 0; i < n; i++)
    {
        if (res[i] != -1 || X[i] > 0) continue;
        if (lsl == -1) lsl = i;
        else {
            ll ti = abs(X[lsl]) + ((abs(X[i])-abs(X[lsl]))/2);
            res[lsl] = res[i] = ti;
            lsl = -1;
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (res[i] != -1 || X[i] < 0) continue;
        if (lsr == -1) lsr = i;
        else {
            ll ti = m-X[lsr] + ((X[lsr]-X[i])/2);
            res[lsr] = res[i] = ti;
            lsr = -1;
        }
    }

    if (lsr != -1 && lsl != -1) {
        ll a = abs(X[lsl]);
        ll b = X[lsr];
        ll ti = max(a, m-b);

        if (a < ti) a = ti-a;
        else a = 0;
        if (m-b<ti) b = m - (ti - (m-b));
        else b = m;

        ti += (b - a) / 2;
        res[lsl] = res[lsr] = ti;
    }

    return res;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve(int tc)  {
    ll n, m;
    cin >> n >> m;

    vector<vp> P(n+1);
    for (int i = 0; i < m; i++)
    {
        ll x, p, a; cin >> x >> p >> a;
        P[x].push_back({p,a});
    }

    vii adj(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    
    vi dp(1<<n);
    for (int i = 1; i < (1<<n); i++)
    {
        ll cn = __builtin_popcount(i);
        for (int j = 0; j < n; j++)
        {
            if (!(i&(1<<j))) continue;
            ll re = dp[i^(1<<j)] + adj[j][cn-1];
            ll summ = 0;
            for (auto [p, a] : P[cn]) if (re >= p) summ+=a;
            re += summ;
            dp[i] = max(dp[i], re);
        }
    }
    
    cout << dp[(1<<n)-1] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("dec.in", "r", stdin);
    freopen("dec.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
