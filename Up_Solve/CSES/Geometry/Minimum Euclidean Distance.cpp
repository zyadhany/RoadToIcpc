#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
#define int ll
 
typedef pair<ll, ll> P;
 
const pair<P, P>INF = {{-1e9, -1e9}, {1e9, 1e9}};
 
ll dis(const pair<P, P> &a) {
    ll d1 = a.first.first - a.second.first;
    ll d2 = a.first.second - a.second.second;
    return d1 * d1 + d2 * d2;
}
 
pair<P, P> get_closest_points(const pair<P, P> &a,
    const pair<P, P> &b) {
return dis(a) < dis(b) ? a : b;
}
 
pair<P, P> getsolvec(vector<P> &X) {
    auto re = INF;
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = i + 1; j < X.size() && j - i < 9; j++)
        {
            re = get_closest_points(re, {X[i], X[j]}); 
        }
    }
    
    return re;
}
 
pair<P, P> sol(vector<P> &X, ll l , ll r) {
    if (l == r) return  INF;
    ll m = (l + r) / 2;
    auto A = sol(X, l, m);
    auto B = sol(X, m+1, r);
    
    
    pair<P, P> res = get_closest_points(A, B);
    ll d = sqrtl(dis(res));
    
    vector<P> Z;
    P mid = X[m];
    for (int i = l; i < r; i++)
    {
        if (abs(X[i].first-mid.first) <= d) Z.push_back(X[i]);
    }
    sort(Z.begin(), Z.end(), [](P &a, P &b){
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    });
 
    return get_closest_points(res, getsolvec(Z));
}
 
void solve(ll tc) {
    ll n;
    cin >> n;
    vector<P> X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }   
    sort(X.begin(), X.end(), [](P &a, P &b){
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
 
    cout << dis(sol(X, 0, n)) << '\n';
}
 
int32_t main()
{
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}