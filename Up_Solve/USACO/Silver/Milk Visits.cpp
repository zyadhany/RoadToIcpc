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

const int MODE = 1e9;

using namespace std;


void solve(int tc) {
    ll n, q;
    string s;

    cin >> n >> q;
    cin >> s;

    vii adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n + 1);
    ll at = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        stack<ll> st;
        st.push(i);
        vis[i] = at;
        while (!st.empty())
        {
            ll tp = st.top();
            st.pop();
            for (auto neg : adj[tp]) {
                if (vis[neg] || s[neg - 1] != s[i - 1]) continue;
                vis[neg] = at;
                st.push(neg);
            }
        }
        
        at++;
    }

    while (q--)
    {
        ll l, r; char c;
        cin >> l >> r >> c;
        if (vis[l] != vis[r] || s[l - 1] == c) cout << "1";
        else cout << "0";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
