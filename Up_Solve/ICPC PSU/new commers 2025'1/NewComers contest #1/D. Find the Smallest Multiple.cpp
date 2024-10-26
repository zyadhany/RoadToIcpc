#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    cout << (b / a + 1) * a << '\n'; 
}
