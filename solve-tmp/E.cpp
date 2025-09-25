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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MODE = 1e9+9;
const int K = uniform_int_distribution<ll>(0, MODE - 1)(rng);

mi F({{0,0}});
ll get(ll v) {
    auto it = F.find(v);
    if (it != F.end()) return it->second;
    return F[v] = uniform_int_distribution<ll>(0, MODE>>1)(rng);
}


ll hashval(ll v) {
    return (v + K) % MODE;
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;
    vi X(n);
    for (int i = 1; i <= n; i++)
    {
        
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
