#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    map<char, pl> DIR;
    DIR['N'] = {1, 0};
    DIR['S'] = {-1, 0};
    DIR['W'] = {0, 1};
    DIR['E'] = {0, -1};

    map<pl, ll> vis;

    ll mx = INT32_MAX;
    ll time = 0;
    pl at = {0, 0};
    vis[at] = 0;

    for (int i = 0; i < n; i++)
    {
        char c; ll a; cin >> c >> a;
        pl st = DIR[c];
        for (int j = 0; j < a; j++)
        {
            at.first += st.first;
            at.second += st.second;
            time++;
            if (vis.count(at)) {
                mx = min(mx, time - vis[at]);
            }
            vis[at] = time;
        }
    }
    
    if (mx == INT32_MAX) cout << "-1\n";
    else cout << mx << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
