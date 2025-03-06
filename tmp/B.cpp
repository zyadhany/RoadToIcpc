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

void req(vii &adj, vi &Z, vi &X, ll n) {
    Z[n] += X[n];
    for (auto neg : adj[n]) {
        req(adj, Z, X, neg);
        Z[n] += Z[neg];
    }
}

ll getsol(vii &adj, vi &dp, vi &Z, vi &P, ll n, ll x) {
    ll &res = dp[n];
    if (res != -1) return res;
    if (Z[P[n]] >= x) return res = P[n];
    return res = getsol(adj, dp, Z, P, P[n], x);
}

ll summ(ll n) {
    return n * (n + 1) / 2;
}

void solve(int tc) {
    ll n, x, k;

    cin >> n >> x >> k;

    vi Y(n);
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a; Y.push_back(a);
    }
    
    for (int i = n; i < x; i++)
    {
        Y.push_back(0);
    }
    
    vi X(x);
    for (int i = 0; i < x; i++)
    {
        cin >> X[i];
    }

    sort(X.rbegin(), X.rend());
    sort(Y.rbegin(), Y.rend());

    for (auto a : X) {
        if (Y.back() < a) {
            k -= summ(a) - summ(Y.back());
        }
        Y.pop_back();
    }

    if (k >= 0) YES;
    NO;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("248.in", "r", stdin);
    // freopen("248.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
