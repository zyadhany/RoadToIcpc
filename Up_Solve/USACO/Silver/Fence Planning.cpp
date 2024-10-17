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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vp X(n + 1);
    vii Y(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> X[i].first >> X[i].second;
    
    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }  
    
    ll mn = INT32_MAX;
    vi vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;

        ll x1, x2, y1, y2;
        x1 = y1 = INT32_MAX;
        x2 = y2 = 0;

        stack<ll> st;
        st.push(i);
        vis[i] = 1;
        while (!st.empty())
        {
            ll at = st.top();
            st.pop();

            x1 = min(x1, X[at].first);
            x2 = max(x2, X[at].first);
            y1 = min(y1, X[at].second);
            y2 = max(y2, X[at].second);

            for (auto neg : Y[at])
                if (!vis[neg]) {
                    vis[neg] = 1;
                    st.push(neg);
                }
        }

        ll dia = (x2 - x1 + y2 - y1) * 2;
        mn = min(mn, dia);
    }

    cout << mn << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
