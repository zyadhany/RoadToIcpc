#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == c || b == d) cout << "YES\n";
    else cout << "NO\n";
}
