#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll sh, sm, eh, em;
    cin >> sh >> sm >> eh >> em;

    ll s = sh * 60 + sm;
    ll e = eh * 60 + em;

    if (s > e) e += 24 * 60;

    ll ans = (e - s) / 60;
    cout << ans << " " << (e - s) % 60 << endl;
}
