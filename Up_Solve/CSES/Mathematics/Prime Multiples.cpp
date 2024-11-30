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

const int MODE = 998244353;

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}

ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    ll sol = 0;
    vector<ll> X(m);
    for (int i = 0; i < m; i++)
        cin >> X[i];
    
    for (int i = 1; i < (1 << m); i++)
    {
        ll cnt = 0;
        ll re = 1;
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j)) {
                cnt++;
                if (n / re < X[j]) {
                    re = n + 1;
                    break;
                }
                re *= X[j];
            }
        }
        
        if (cnt % 2) sol += n / re;
        else sol -= n / re;
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("cruise.in", "r", stdin);
    // freopen("cruise.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
