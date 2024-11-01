#include <bits/stdc++.h>

#define ll long long

using namespace std;

const double PI = acos(-1);

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    cout << max(1ll, min(n, a + b - n + 1)) << ' ' << min(n, a + b - 1);
}
