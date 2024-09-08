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

    vi Z(n + 1);
    vii Y(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        Y[u].push_back(v);
        Y[v].push_back(u);
    }
    
    vi col(n + 1);
    for (int i = 1; i <= n; i++)
    {
        set<ll> st({1, 2, 3, 4});

        for (auto j : Y[i])
            if (st.count(col[j])) st.erase(col[j]);

        col[i] = *st.begin();

        cout << col[i];
    }
    
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
