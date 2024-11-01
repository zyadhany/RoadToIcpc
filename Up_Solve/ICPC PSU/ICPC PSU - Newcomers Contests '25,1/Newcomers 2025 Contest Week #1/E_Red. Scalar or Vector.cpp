#include <bits/stdc++.h>

#define ll long long

using namespace std;

const double PI = acos(-1);

int main()
{
    string s;
    ll a, b, ang;
    cin >> s;
    cin >> a >> b >> ang;

    double sol, theta;
    theta = ang * PI / 180.0;
  
    if (s == "cliff") sol = a * b * sin(theta);
    else sol = a * b * cos(theta);

    cout << fixed << setprecision(6) << abs(sol) << '\n';
}
