#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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

void solve(int tc)  {
    ll n ,k;
    string s;
    cin >> n >> k;
    cin >> s;

    deque<ll> X(n);
    for (int i = 0; i < n; i++)
    {
        X[i] = s[i] - '0';
    }
    vii IND(10);
    for (int i = 0; i < n; i++)
    {
        IND[X[i]].push_back(i);
    }

    vi vis(n);
    ll at = 0;
    while (at < n)
    {
        ll re = n;
        for (int i = 0; i < X[at]; i++)
        {
            ll l = lower_bound(all(IND[i]), at) - IND[i].begin();
            if (l != IND[i].size()) {
                re = min(re, IND[i][l]);
            }
        }
        
        if (re - at <= k) {
            for (int i = at; i < re; i++)
            {
                vis[i] = 1;
                k--;
            }
        } else at++;
    }

    deque<ll> res;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]) res.push_back(X[i]);
    }
    while (k && !res.empty())
    {
        k--;
        res.pop_back();
    }
    while (!res.empty() && res.front() == 0)
    {
        res.pop_front();
    }
    if (res.empty()) cout << "0\n";
    else {
        for (auto a : res) cout << a;
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("tree.in", "r", stdin);
    // freopen("island.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
