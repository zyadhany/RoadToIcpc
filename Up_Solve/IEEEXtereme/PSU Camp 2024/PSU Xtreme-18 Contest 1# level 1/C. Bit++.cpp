#include<bits/stdc++.h>
 
 
#define vi vector<int>
#define vc vector<char>
#define vii vector<vi>
#define vcc vector<vc>
#define ll long long
#define forx(n,X) for (ll i = 0; i < n; i++)cin >> X[i][j];
#define forx(n,m,X) for (ll i = 0; i < n; i++)for (ll j = 0; j < m; j++)cin >> X[i][j];
 
 
using namespace std;
 
int gcd(int a, int b)
{
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}
 
int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
 
void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
 
 
 
void solve() {
	int n , X=0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s[0] == '+' || s[1] == '+')
		{
			X++;
		}
		else X--;
	}
	cout << X;
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