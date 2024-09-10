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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n;

    cin >> n;

    ll root = -1;
    vi X(n + 1), Y(n), vis(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        if (X[i] == i) root = i;
    }
    
    bool issolved = 1;

    ll a; cin >> a;
    if (a != root) issolved = 0;
    vis[root] = 0;
    ll cnt = 0;
    
    vi res(n + 1);

    for (int i = 1; i < n; i++) {
        cin >> a;

        ll re = vis[X[a]];
        if (re == -1) issolved = 0;
        cnt += 1;
        vis[a] = cnt;
        res[a] = cnt - re;
    }
    
    if (!issolved) MUN;

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
