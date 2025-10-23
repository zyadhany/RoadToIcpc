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

const ll INF = 1e16;

void solve(int tc) {
    ll n;

    cin >> n;

    vector<vp> adj(n+1);

    for (int i = 0; i < n-1; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vi Y;

    for (int i = 1; i <= n; i++)
    {
        ll summ = INF;
        for (auto [j, w] : adj[i])
        {
            summ = min(summ, w);
        }
        Y.push_back(summ);
    }
    sortx(Y);
    reverse(all(Y));

    ll q; cin >> q;
    vp Q(q);
    vi res(q);
    for (int i = 0; i < q; i++)
    {
        ll k; cin >> k;
        Q[i] = {k, i};
    }
    sortx(Q);

    ll summ = 0;
    ll cnt = 0;
    ll ls = 0;
    for (auto [k, i] : Q) {
        summ += (k - ls) * cnt;
        ls = k;
        while (!Y.empty() && Y.back() <= k) {
            summ += k - Y.back();
            Y.pop_back();
            cnt++;
        }
        // cout << k << ' ' << summ << ln;
        res[i] = summ ;
    }

    for (auto a : res) cout << a << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}