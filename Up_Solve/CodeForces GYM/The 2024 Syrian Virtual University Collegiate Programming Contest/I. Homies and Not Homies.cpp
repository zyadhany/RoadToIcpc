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

vi Z(64, -1);
ll req(ll n) {
    if (n == -1) return 0;
    ll &res = Z[n];
    if (~res) return (res);
    res = req(n - 1);

    ll re = (1 << (n - 1));
    res += re;
    for (int i = 1; i < n; i++)
        if (i % 2 == 0) res += (re >> 1);
    
    return (res);
}

ll getsol(ll n) {
    ll summ = 0;

    for (int i = 1; i <= n; i++)
    {
        ll re = i;
        vi X;
        while (re)
        {
            X.push_back(re % 2);
            re /= 2;
        }
        reverse(all(X));
        for (int j = 0; j < X.size(); j++)
        {
            if (j % 2 == 0) summ += X[j];
        }
        
    }

    return (summ);
}

void solve(int tc) {
    ll n;
    Z[0] = 1;
    Z[1] = 2;
    cin >> n;

    ll lg = log2(n);
    ll summ = req(lg);

    ll lf = n - (1 << lg);
    summ += lf;

    lf++;
    for (ll i = 1, cnt = (1 << (lg - 1)); i <= lg; i++, cnt>>=1)
    {
        if (i % 2) continue;
        ll a = lf / cnt;
        summ += (a / 2) * cnt;
        if (a % 2) summ += lf % cnt;
    }
    
    cout << summ << '\n';
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