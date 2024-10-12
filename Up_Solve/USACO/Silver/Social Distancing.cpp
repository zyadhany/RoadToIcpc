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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vp X(m);
    for (int i = 0; i < m; i++)
        cin >> X[i].first >> X[i].second;
    sortx(X);

    ll l = 1, r = 1e18;
    while (l < r)
    {
        ll mid = l + (r - l + 1) / 2;
        ll cnt = 1;
        ll at = X[0].first;

        for (int i = 0; i < m; i++)
            while (at + mid <= X[i].second && cnt < n)
            {   
                at = max(at + mid, X[i].first);
                cnt++;
            }

        if (cnt >= n) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
