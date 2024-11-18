#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, x, h, m, s;
    cin >> n >> x >> h >> m >> s;

    m += h * 60;
    s += m * 60;
    n -= x * s;

    cout << max(0ll, n) << '\n';
}
