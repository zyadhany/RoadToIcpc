#include<bits/stdc++.h>
#include <algorithm>
#include<numeric>
 
#define vi vector<int>
 
using namespace std;
 
int gcd(int a, int b)
{
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}
 
void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
 
void solve() {
	int n, m, req, summ;
	cin >> n >> m;
 
	summ = (n / 2) * m + (n%2)*m/2;
	cout << summ;
}
 
int main()
{
	FP();
	int size = 1;
	//cin >> size;
	while (size--)
	{
		solve();
	}
 
}