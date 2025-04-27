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

ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}


ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

ll modeenv(ll n) {
    ll x, y;
    gcdExtended(n, MODE, &x, &y);
    return (x + MODE) % MODE;
}

void solve(int tc) {
    ll n;
    cin >> n;

    vi X(n);

    ll summ = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        summ = (summ + X[i]) % MODE;
    }
    
    vi dp(n, -1);
    for (int st = 1; st < n; st++)
    {
        ll g = gcd(st, n);
        if (dp[g] != -1) {
            summ = (summ + dp[g]) % MODE;
            continue;
        }
        ll &res = dp[g];
        res = 0;

        vp Y(g);
        for (int i = 0; i < n; i++)
        {
            Y[i % g].first = (Y[i % g].first + X[i]) % MODE;
            Y[i % g].second++;
        }

        for (auto p : Y) {
            res = (res + (p.first * p.second) % MODE) % MODE;
        }

        summ = (summ + res) % MODE;
    }
    


    // for (int i = 0; i < n; i++)
    // {
    //     cin >> X[i];
    // }
    
    // ll md = sqrt(n);

    // vector<vp> Z(md, vp(md, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < md; j++)
    //     {
            
    //     }
        
    // }
    

    // ll summ = 0;
    // for (int st = 0; st < n; st++)
    // {
    //     ll cnt = 0;
    //     for (int cur = 0; cur < n; cur++)
    //     {
    //         vi Y(X);
    //         ll at = cur;
    //         while(Y[at])
    //         {
    //             summ += Y[at];
    //             summ %= MODE;
    //             Y[at] = 0;
    //             at = (at + st) % n;
    //         }
    //     }
    // }

    summ *= modeenv(n * n);
    summ %= MODE;
    cout << summ << '\n';
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
