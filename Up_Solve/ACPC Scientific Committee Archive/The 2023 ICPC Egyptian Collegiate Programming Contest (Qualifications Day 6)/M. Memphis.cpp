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
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;

vi fac(1e6 + 1, 1);
vi sol(1e6 + 1, -1);

ll req(ll n) {
    ll &res = sol[n];
    if (~res) return (res);
    return res = (fac[n - 1] + (n * req(n - 1))) % MODE;
}

void solve(int tc) {
    ll n;
    cin >> n;
    cout << req(n) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 1; i < fac.size(); i++)
        fac[i] = (fac[i - 1] * i) % MODE;
    sol[1] = 1; sol[2] = 3;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
