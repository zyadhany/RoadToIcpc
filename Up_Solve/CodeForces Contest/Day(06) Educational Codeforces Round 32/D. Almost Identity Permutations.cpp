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
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}

using namespace std;

//nPr = fac(n) / fac(n - r)
ll nPr(ll n, ll r) {
    ll summ = 1;
    for (int i = n; i > n - r; i--)
        summ *= i;
    return (summ);
}

void solve(int tc) {
    ll n, k, summ = 1;

    cin >> n >> k;

    if (k >= 2) summ += nPr(n, 2) / 2;
    if (k >= 3) summ += nPr(n, 3) / 3;
    if (k >= 4) summ += (nPr(n, 4) / 24ll) * 9ll;

    cout << summ << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}