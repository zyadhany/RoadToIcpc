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

bool req(vi &X) {
    ll n = X.size();
    deque<stack<ll>> ST;
    
    ll at = 1;
    for (int i = 0; i <= n; i++)
    {
        ll l = 0, r = ST.size();
        while (l < r)
        {
            ll mid = (l + r) / 2;

            if (ST[mid].top() > X[i]) r = mid;
            else l = mid + 1;
        }

        if (l == ST.size()) {
            ST.push_back(stack<ll>({X[i]}));
        } else ST[l].push(X[i]);

        while (!ST.empty() && ST[0].top() == at) {
            ST[0].pop();
            if (ST[0].empty()) ST.pop_front();
            at++;
        }
    }
    
    return at > n;
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    vi Y(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        Y[X[i]] = i;
    }

    ll l = 1, r = n;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        vi Z(mid);
        for (int i = 0; i < mid; i++)
            Z[i] = X[i];

        ll at = 1;
        for (int i = 1; i <= n; i++)
            if (Y[i] < mid) Z[Y[i]] = at, at++;
        
        if (req(Z)) l = mid;
        else r = mid - 1;
    }
    
    cout << l << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
