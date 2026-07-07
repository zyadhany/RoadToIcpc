// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}

using namespace std;

const int MODE = 998244353;
const ll INF = 1e16;

bool isplan(ll n) {
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}

const int N = 2e6+10;
vi IDN[N];

void solve(int tc) {
    vi P;
    ll cnt = 0;
    for (int i = 2; i < N; i++)
    {
        if (isplan(i)) P.push_back(i);
    }

    ll n, q;

    cin >> n >> q;
    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }

    vii Q;
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
        
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}