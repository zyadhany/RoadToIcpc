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
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n, odd, mx;

    cin >> n;

    odd = 0;
    mx = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        ll re = 0, k = a % 2;
        odd += k;
        while (a % 2 != k ^ 1)
        {
            re++;
            a /= 2;
        }
        mx = min(mx, re);
    }
    
    if (odd % 2) cout << mx << '\n';
    else cout << 0 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);

    cin >> size;
    for (int i = 1; i <= size; i++)
            solve(i);
}
