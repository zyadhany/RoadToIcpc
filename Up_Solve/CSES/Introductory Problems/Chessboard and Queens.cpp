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

void setque(vii &vis, ll l, ll r, ll val){

    for (int i = 0; i < 8; i++)
    {
        vis[l][i] += val;
        vis[i][r] += val;
        if (l + i < 8 && r + i < 8) 
            vis[l + i][r + i] += val;
        if (l - i >= 0 && r + i < 8) 
            vis[l - i][r + i] += val;
        if (l + i < 8 && r - i >= 0) 
            vis[l + i][r - i] += val;
        if (l - i >= 0 && r - i >= 0) 
            vis[l - i][r - i] += val;
    }
    
}

ll req(vector<string> &X, vii &vis, ll at, ll hv) {
    int l, r;
    l = at / 8, r = at % 8;

    if (hv == 8) return (1); 
    if (at == 64) return (0);
    if (vis[l][r] || X[l][r] == '*')
        return req(X, vis, at + 1, hv);

    ll a, b;

    setque(vis, l, r, 1);
    a = req(X, vis, at + 1, hv + 1);
    setque(vis, l, r, -1);
    b = req(X, vis, at + 1, hv);

    return (a + b);
}

void solve(ll tc) {
    vector<string> X(8);
    vii vis(8, vi(8));

    for (int i = 0; i < 8; i++)
        cin >> X[i];

    cout << req(X, vis, 0, 0);     
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
