#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll a, b;

    cin >> a >> b;

    b += a;
    b -= b % a;
    cout << b << '\n';
}
