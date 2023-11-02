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
#define all(X) (X.begin(),X.end());
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

ll req(ll n) {
    ll re = 0;

    while (n % 2 == 0)
        n /= 2, re++;

    return (re);
}

void solve(int tc) {
    ll n, a, summ = 0;

    cin >> n;

    vi X(n);

    for (int i = 0; i < n; i++) {
        cin >> a;
        X[i] = req(a);
    }
    sortx(X);

    summ = X[0];

    for (int i = 1; i < n; i++)
        summ += (X[i] > 0);

    cout << summ << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
