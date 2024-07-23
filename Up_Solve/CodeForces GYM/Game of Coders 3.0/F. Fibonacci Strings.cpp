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
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;


void solve(int tc) {
    ll n, m;
    string s, t;

    cin >> n >> m;
    cin >> s >> t;

    ll d, k;
    cin >> d >> k;

    vi fib(200, 0);
    fib[0] = n;
    fib[1] = m;


    ll at;
    for (int i = 2; ; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] >= k) {
            at = i;
            break;
        }
    }

    if (d <= 2) at = d - 1;
    while (at >= 2)
    {
        ll l = fib[at - 1];
        if (k > l) at-=2, k-=l;
        else  at--;
    }
    
    if (at) cout << t[k - 1];
    else cout << s[k - 1];
    cout << '\n';
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