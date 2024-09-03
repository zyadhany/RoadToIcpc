#define _CRT_SECURE_NO_WARNINGS
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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, b;

    cin >> n;
    
    vp X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;
    sortx(X);

    ll mn = n;
    for (int i = n / 4; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll l = X[i].first + 1;
            ll r = X[j].second + 1;

            ll a, b, c, d;
            a = b = c = d = 0;
            ll re = 0;

            for (int k = 0; k < n && re < mn; k++)
            {
                ll x = X[k].first;
                ll y = X[k].second;

                if (x > l && y > r) a++;
                else if (x < l && y > r) b++;
                else if (x > l && y < r) c++;
                else d++;
                re = max(max(a, b), max(c, d));
            }
         
            mn = min(mn, re);        
        }
    }
            
    cout << mn << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
