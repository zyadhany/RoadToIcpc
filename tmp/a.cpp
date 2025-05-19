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
 
const int MODE = 998244353;

ll nor(ll a, ll b, ll k) {
    ll re = 0;
    for (int i = 0; i < k; i++)
    {
        ll l = (a >> i) & 1;
        ll r = (b >> i) & 1;
        if (!l && !r) re |= (1<<i);
    }
    return re;
}

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n);
    for (int i = 0; i < n; i++) cin >> X[i];

    vp Y(k, {X[0], 0});
    vii Z;
    ll bg = X[0];
    for (int i = 1; i < n; i++)
    {
        bg = nor(bg, X[i], k);
        Z.push_back({0, i, bg});
        for (int j = 0; j < k; j++)
        {
            Y[j].first = nor(Y[j].first, X[i], k);
            Z.push_back({Y[j].second, i, Y[j].first});
        }
        for (int j = 0; j < k; j++)
            if (X[i] & (1<<j)) Y[j] = {X[i], i};
    }


    vector<multiset<ll>> in(n+10), out(n+10);

    vi res(all(X));
    for (auto &p : Z) {
        in[p[0]].insert(p[2]);
        out[p[1]+1].insert(p[2]);
    }

    for (auto p : Z) {
        for (int i = p[0]; i <= p[1]; i++)
        {
            res[i] = max(res[i], p[2]);
        }
        
    }

    // multiset<ll> st;
    // for (int i = 0; i < n; i++)
    // {
    //     for (auto a : out[i]) st.erase(st.find(a));
    //     for (auto a : in[i]) st.insert(a);

    //     if (!st.empty()) res[i] = max(res[i], *prev(st.end()));
    // }

    for (auto a : res) cout << a << ' ';
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
  
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}
