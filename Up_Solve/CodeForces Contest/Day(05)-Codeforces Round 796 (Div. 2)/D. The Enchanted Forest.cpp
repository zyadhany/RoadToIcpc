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

ll summtion(ll n) {
    return n * (n + 1) / 2;
}

void solve(int tc) {
    ll n, k, summ = 0, mx = 0;
    
    cin >> n >> k;

    vi X(n + 1), Y(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        Y[i] = X[i] + Y[i - 1];
    }

    for (int i = min(k, n); i <= n; i++)
        mx = max(mx, Y[i] - Y[max(i - k, 0ll)]);
    
    if (k > n) summ = (k - 1ll + k - n) * n / 2;
    else summ = summtion(k - 1);

    cout << summ + mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}