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


using namespace std;

const int MODE = 1e9 + 7;

ll fpow(ll x, ll y) {
    ll res = 1;
    x %= MODE;
    while (y > 0) {
        if (y & 1) res = (res * x) % MODE;
        x = (x * x) % MODE;
        y >>= 1;
    }
    return res;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi Z(n * 2 + 10);

    for (int i = 0; i < n; i++)
    {
        ll a, b; cin >> a >> b;
        Z[a]++, Z[b + 1]--;
    }
    
    for (int i = 1; i <= 2 * n; i++)
        Z[i] += Z[i - 1];

    ll sol = 0;
    stack<pl> st;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!st.empty() && Z[i] == st.top().first) {
            sol = (sol + fpow(2, n - st.size())) % MODE;
            st.pop();
        } else st.push({Z[i], i});
    }

    cout << sol << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
