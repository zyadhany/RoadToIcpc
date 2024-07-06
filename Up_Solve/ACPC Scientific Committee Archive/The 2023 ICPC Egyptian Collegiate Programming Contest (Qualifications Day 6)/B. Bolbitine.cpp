#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vp res;
    vii X(n + 1, vi(3));
    vector<vp> Y(n + 1);
    vector<vp> Z(n + 1, vp(1, {0, 0}));

    for (int i = 1; i <= q; i++)
    {
        ll opp, l, r;
        cin >> opp;

        if (opp == 3) {
            cin >> l;
            Y[l].push_back({i, Y[l].back().second});
            res.push_back({l, i});
            continue;
        }

        cin >> l >> r;
        if (opp == 1) Y[l].push_back({i, r});
        else Z[l].push_back({i, r + Z[l].back().second});
    }
    
    for (int i = 1; i <= n; i++)
        if (!Y[i].empty()) X[i][2] = Y[i][0].second;


    vii div(q + 1);

    for (int i = 1; i <= q; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j) continue;
            div[i].push_back(j);
            if (j * j != i) div[i].push_back(i / j);
        }
    }
    

    for (int i = 0; i < res.size(); i++)
    {
        ll s = res[i].first;
        while (Y[s][X[s][0]].first < res[i].second)
        {
            ll summ = 0;
            ll l, r;
            l = Y[s][X[s][0]].first, r = Y[s][X[s][0] + 1].first;
        

            //cout << X[s][2] << "|\n";
            for (auto g : div[X[s][2]]) {
                //cout << X[s][2] << ' ' << g << "|\n";
                pl k = {l, 0};
                ll a = lower_bound(all(Z[g]), k) - Z[g].begin();
                k = {r, INT64_MAX};
                ll b = upper_bound(all(Z[g]), k) - Z[g].begin() - 1;
                if (a != Z[g].size()) summ += Z[g][b].second - Z[g][a - 1].second;
            }

            X[s][0]++;
            X[s][1] += summ;
            X[s][2] = Y[s][X[s][0]].second;
        }
        
        cout << X[s][1] << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
    