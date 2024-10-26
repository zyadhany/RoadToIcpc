#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s;
    ll a, b, ang;
    double res;

    cin >> s;
    cin >> a >> b >> ang;

    if (s == "cliff") res = a * b * sin(ang * PI / 180);
    else res = a * b * cos(ang * PI / 180);

    cout << fixed << setprecision(6) << abs(res) << endl;
}
