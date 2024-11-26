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


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<vp> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        char c; ll u, v;
        cin >> c >> u >> v;
        adj[u].push_back({v, c == 'S'});
        adj[v].push_back({u, c == 'S'});
    }

    vi vis(n + 1, -1);
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != -1) continue;
        cnt++;
        stack<ll> st;
        st.push(i);
        vis[i] = i;
        while (!st.empty())
        {
            ll tp = st.top();
            st.pop();

            for (auto neg : adj[tp]) {
                if (vis[neg.first] == -1) {
                    vis[neg.first] = (vis[tp] ^ 1 ^ neg.second);
                    st.push(neg.first);
                } else if (vis[neg.first] == vis[tp] ^ neg.second)
                {
                    cout << "0\n";
                    return;                    
                }
            }
        }
    }

    cout << "1";
    for (int i = 0; i < cnt; i++)
        cout << "0";    
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
