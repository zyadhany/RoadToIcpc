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
    ll n;

    cin >> n;

    vp X(n);
    vector<vp> Y(11);
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        X[i] = {x, y};
        Y[y].push_back({x, i});
    }
    for (int i = 0; i < X.size(); i++)
    {
        sortx(Y[i]);
    }
    
    ll res = 0;

    priority_queue<vi, vector<vi>, greater<vi>> pq;
    vector<bool> visited(n + 1, false);
    
    pq.push({0, 0, 0});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        
        int wt = p[0];
        int u = p[2];
        // if(visited[u]) continue;
        visited[u] = true; 
        res += wt;

        vi Z = {INT64_MAX, 0,0};

        for (int j = 0; j < 11; j++)
        {
            ll ind = lower_bound(all(Y[j]), pl(X[u].first, 0)) - Y[j].begin();
            if (j == X[u].second) ind++;

            if (ind < Y[j].size()) {
                ll v = Y[j][ind].second;
                ll dist = (X[v].first - X[u].first) * (X[v].first - X[u].first);
                dist += (X[v].second - X[u].second) * (X[v].second - X[u].second);
                if (!visited[v])
                Z = min(Z, {{dist, u, v}});
            }

            ind--;
            if (j == X[u].second) ind--;
            if (ind >= 0) {
                ll v = Y[j][ind].second;
                ll dist = (X[v].first - X[u].first) * (X[v].first - X[u].first);
                dist += (X[v].second - X[u].second) * (X[v].second - X[u].second);
                if (!visited[v])
                Z = min(Z, {{dist, u, v}});
            }
        }

        u = p[1];
        for (int j = 0; j < 11; j++)
        {
            ll ind = lower_bound(all(Y[j]), pl(X[u].first, 0)) - Y[j].begin();
            if (j == X[u].second) ind++;

            if (ind < Y[j].size()) {
                ll v = Y[j][ind].second;
                ll dist = (X[v].first - X[u].first) * (X[v].first - X[u].first);
                dist += (X[v].second - X[u].second) * (X[v].second - X[u].second);
                if (!visited[v])
                Z = min(Z, {{dist, u, v}});
            }

            ind--;
            if (j == X[u].second) ind--;
            if (ind >= 0) {
                ll v = Y[j][ind].second;
                ll dist = (X[v].first - X[u].first) * (X[v].first - X[u].first);
                dist += (X[v].second - X[u].second) * (X[v].second - X[u].second);
                if (!visited[v])
                Z = min(Z, {{dist, u, v}});
            }
        }

        if (Z[0] != INT64_MAX) pq.push(Z);
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("math.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
