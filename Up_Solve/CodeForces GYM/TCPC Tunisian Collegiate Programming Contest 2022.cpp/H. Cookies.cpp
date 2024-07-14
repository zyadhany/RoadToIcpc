#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll , null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update>
*/
/*
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC target("aes,pclmul,rdrnd")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast,inline")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("movbe")
#pragma GCC optimize("O3")
#undef _GLIBCXX_DEBUG
*/
/*
__int128 read() { __int128 x = 0, f = 1; char ch = getchar(); while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); } while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); } return x * f; }
void print(__int128 x) { if (x < 0) { putchar('-'); x = -x; } if (x > 9) print(x / 10); putchar(x % 10 + '0'); }
//__int128 a = read();
//print(a);
*/
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<ll>> vii;
typedef vector<vector<char>> vcc;
typedef vector<ll> vi;
typedef vector<char> vc;
typedef vector<pair<ll,ll>> vp;
typedef map<ll,ll> mi;
typedef map<char,ll> mc;
#define Gendy ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cerr.tie(nullptr);
#define ln  "\n"
#define cin_vii(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout_vii(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define fixed(n) fixed << setprecision(n)
#define all(p)           p.begin(),p.end()
#define rall(v)          v.rbegin(),v.rend()
#define F                     first
#define S                     second
#define cin(v) for (auto &_ : v) cin >> _;
#define cout(v) for (auto &_: v) cout << _ << " " ;
void pre(vi& v) { for (ll i = 1; i < v.size(); ++i) v[i] += v[i - 1];}
void suf(vi& v) { for (ll i = v.size() - 2; i >= 0; --i) v[i] += v[i + 1];}
ll gcd(ll a,ll b) { return (__gcd(a,b));}
ll lcm(ll a,ll b) { return ((a / gcd(a, b)) * b);}
ll sum(ll n){return n * (n + 1) / 2;}
bool valid(ll x, ll y, ll n) { if (x<0 || y<0 || x>= n || y >= n) return false; return true;}
#define ch(cond) {cout<<(cond?"YES\n":"NO\n");return;}
#define pi  3.14159265358979323846
ll MOD =  998244353;


ll dx[] = {1,  0, 0, -1};
ll dy[] = {0,  1,-1,  0};


void solve(ll test) {

    ll n,m,k;cin>>n>>m>>k;
    ll s = n-k;
    if (s >= m)
    {
        cout<<k<<"\n";
    }
    else
    {
        n -= s;
        m -= s;
        cout<<k-m<<"\n";
    }
}


int main() {
    Gendy
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll codeKiller = 1;
    cin >> codeKiller;
    for (ll i = 1; i <= codeKiller; ++i) {
        solve(i);
    }
}