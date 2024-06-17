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


void solve(ll tc) {
    ll n, mx;

    cin >> n;

    mx = 0;
    vii X(n, vi(3));
    priority_queue<pl, vp, greater<pl>> pq;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> X[i][j];
    sortx(X);    

    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top().first < X[i][0])
        {
            mx = max(mx, pq.top().second);
            pq.pop();
        }
        
        pq.push({X[i][1], mx + X[i][2]});
    }
    
    while (!pq.empty())
    {
        mx = max(mx, pq.top().second);
        pq.pop();
    }

    cout << mx << '\n';
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
