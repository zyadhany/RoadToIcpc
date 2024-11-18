<<<<<<< HEAD
    #define _CRT_SECURE_NO_WARNINGS
=======
>>>>>>> 988bda4496b712bb8fd6eb3c4ebfec62f0229e3c
#include <bits/stdc++.h>

#define ll long long

using namespace std;

<<<<<<< HEAD
void solve(int tc) {
    ll n;

    cin >> n;

    vi pw3(3e5 + 1, 1);
    vi pw20(3e5 + 1, 1);
    vi pw7(3e5 + 1, 1);
    for (int i = 1; i < pw3.size(); i++) {
        pw3[i] = (pw3[i - 1] * 3) % MODE;
        pw20[i] = (pw20[i - 1] * 20) % MODE;
        pw7[i] = (pw7[i - 1] * 7) % MODE;
    }
    
    ll sol = 0;
    for (int i = 0; i < n; i++)
    {
        ll re = ((pw7[i] * 20) % MODE * pw3[n * 3 - (i + 1) * 3]) % MODE;
        sol = (sol + re) % MODE;
    }

    cout << sol << '\n';
}
=======
const double PI = acos(-1);
>>>>>>> 988bda4496b712bb8fd6eb3c4ebfec62f0229e3c

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    cout << max(1ll, min(n, a + b - n + 1)) << ' ' << min(n, a + b - 1);
}
