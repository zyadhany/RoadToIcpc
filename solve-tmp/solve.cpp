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

ll req(ll a, ll b, ll n) {
    ll summ = 0;
    for (int i = a; i < n; i+=a)
        if ((n - i) % b == 0) summ ++;
    return (summ);
}

void solve(int tc) {
    ll n, m, summ, re;

    cin >> n >> m;

    summ = 0;
    vi X(m);
    pl k;    

    for (int i = 0; i < m; i++)
        cin >> X[i];
    sortx(X);

    for (int i = 0; i < m; i++)
    {
        if (n % X[i] == 0) summ++;
        for (int j = i + 1; j < m; j++)
        {
            re = req(X[i], X[j], n);
            summ += re;
        }
    }
    
    cout << summ << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
