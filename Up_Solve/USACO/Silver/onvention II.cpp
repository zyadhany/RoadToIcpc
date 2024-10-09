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

    vii X(n, vi(3));

    for (int i = 0; i < n; i++)
    {
        cin >> X[i][0] >> X[i][2];
        X[i][1] = -i;
    }
    sortx(X);

    ll at = 0;
    ll time = 0;
    ll mx = 0;
    priority_queue<pl> pq;

    while (at < n || !pq.empty())
    {
        if (pq.empty() && time < X[at][0]) time = X[at][0];
        while (at < n && time >= X[at][0])
        {
            pq.push({X[at][1], at});
            at++;
        }

        mx = max(mx, time - X[pq.top().second][0]);
        time += X[pq.top().second][2];
        pq.pop();
    }

    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
