#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll n;
    cin >> n;

    cout << n % 10;
    n /= 10;
    cout << n % 10;
    n /= 10;
    cout << n % 10;
    n /= 10;
    cout << n % 10;
}
