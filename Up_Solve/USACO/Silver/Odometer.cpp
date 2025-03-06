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

const int MODE = 998244353;

using namespace std;

ll dp[20][20][20][2][2];

ll req(string &s, ll ind, ll k, ll k2, ll zer, ll grt, ll v, ll v2) {
    ll &res = dp[ind][k][k2][zer][grt];
    if (res != -1) return res;

    ll haf = (s.size() + 1) / 2;
    if (ind == s.size()) {
        return res = ((k>=haf)&&(k2>=haf));
    }

    res = 0;
    ll st = 0;
    ll lim = 10;
    ll at = s[ind] - '0';
    ll ad = 0;

    if (!zer) {
        res += req(s, ind + 1, k, k2, 0, 1, v, v2);
        ll nd = (s.size() - ind + 1) / 2;
        ad = haf - nd;
        st = 1;
    }

    if (!grt) {
        res += req(s, ind + 1, k + (at == v) + ad, k2 + (at == v2) + ad, 1, 0, v, v2);
        lim = at;
    }

    for (int i = st; i < lim; i++)
    {
        res += req(s, ind + 1, k + (i == v) + ad, k2 + (i == v2) + ad, 1, 1, v, v2);        
    }

    return res;
}

void reset() {
    for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
    for (int j1 = 0; j1 < 20; j1++)
    for (int j2 = 0; j2 < 2; j2++)
    for (int j3 = 0; j3 < 2; j3++)
        dp[i][j][j1][j2][j3] = -1;
}

ll sol(ll n) {
    string s = to_string(n);
    ll res = 0;
    
    for (int i = 0; i < 10; i++)
    {
        reset();
        res += req(s, 0, 0, 0, 0, 0, i, i);
    }
    
    ll dub = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i+1; j < 10; j++)
        {
            reset();
            dub += req(s, 0,0,0,0,0,i,j);
        }
    }
    
    res -= dub;
    return res;
}

void solve(int tc) {
    ll a, b;

    cin >> a >> b;

    cout << sol(b) - sol(a-1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}
