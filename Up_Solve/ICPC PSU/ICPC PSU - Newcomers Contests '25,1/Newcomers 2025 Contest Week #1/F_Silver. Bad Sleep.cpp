#include <bits/stdc++.h>

#define ll long long

using namespace std;

const double PI = acos(-1);

int main()
{
    ll h1, m1;
    ll h2, m2;

    cin >> h1 >> m1 >> h2 >> m2;

    m1 += h1 * 60;
    m2 += h2 * 60;

    if (m2 <= m1) m2 += 60 * 24;

    ll total = m2 - m1;

    ll hf = total / 60;
    ll mf = total % 60;

    cout << hf << ' ' << mf << '\n';
}
  