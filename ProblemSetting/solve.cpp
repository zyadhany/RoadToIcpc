#include <bits/stdc++.h>

using namespace std;

long long gcdExtended(long long a, long long b, long long* x, long long* y)
{
    if (a == 0) {
        *x = 0, * y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

void solve(int tc) {
    long long n, m, summ, re;

    cin >> n >> m;

    summ = 0;

    cout << summ << '\n';    
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
