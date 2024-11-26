#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<int, int>
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
    ll n, m;

    cin >> n >> m;

    vi X(n);
    vp Y(m);
    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 0; i < m; i++)
        cin >> Y[i].first >> Y[i].second;
    vi ava(n);
    ava[0] = 1;

    for (int step = 0; step < m; step++)
    {
        vi vis(n);
        auto [h, k] = Y[step];
        stack<ll> st;

        for (int j = 0; j < n; j++)
            if (ava[j] && X[j] <= h) {
                st.push(j);
                vis[j] = 1;
            }

        while (!st.empty())
        {
            ll tp = st.top();
            st.pop();

            for (int i = max(0ll, tp - k); i <= min(n - 1, tp + k); i++)
            {
                if (vis[i] || X[i] > h) continue;
                vis[i] = ava[i] = 1;
                st.push(i);
            }
        }
                
        if (ava[n - 1]) {
            cout << step << '\n';
            break;
        }
    }
}  

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
