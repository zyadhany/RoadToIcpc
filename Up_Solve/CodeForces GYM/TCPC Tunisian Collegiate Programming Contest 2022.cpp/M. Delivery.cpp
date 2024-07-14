#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; continue;}
#define NO {cout << "NO\n"; continue;}

const int MODE = 1e9 + 7;

using namespace std;

ll summtion (ll n) {
    return n * (n + 1) / 2;
}

void solve(ll test) {
    ll n;

    cin >> n;

    ll N = (sqrt((8 * n) + 1) + 1) / 2 - 1;

    for (int i = 2; i <= N; i++)
    {
        ll l, r, at;
        l = 1, r = n - i;
        while (l < r)
        {
            ll at = (l + r) / 2;
            ll k = summtion(at + i - 1) - summtion(at - 1);
            if (k >= n) r = at;
            else l = at + 1;
        }
        ll k = summtion(l + i - 1) - summtion(l - 1);
        if (k == n) {
            cout << l << ' ' << l + i - 1 << '\n';
            return;
        }
    }
    
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
