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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;


void solve(ll tc) {
    ll n, mx, at;

    cin >> n;

    mx = 0;
    vp X(n);
    priority_queue<pl, vp, greater<pl>> L;

    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;
    sortx(X);

    at = 0;
    L.push({INT32_MAX, 0});
    for (int i = 0; i < n; i++)
    {
        while (L.top().first <= X[i].first)
        {
            at = max(L.top().second, at);
            L.pop();
        }
        L.push({X[i].second, at + 1});
        mx = max(mx, at + 1);
    }

    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}
