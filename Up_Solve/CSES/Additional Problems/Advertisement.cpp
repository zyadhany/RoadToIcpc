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

const ll INF = 1e16;

vp MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vp Z(n, {-1, n});

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second].second = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }
    while(!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second].first = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }
    return (Z);
}


void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    vp Z = MonomaticStack(X);

    ll mx = 0;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, X[i] * (Z[i].second - Z[i].first - 1));
    }
    
    cout << mx << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("walk.in", "r", stdin);
    // freopen("walk.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
