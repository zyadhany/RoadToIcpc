#include <bits/stdc++.h>
#include <cstdio>
 
//My codes-------------->>>>
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vii vector<vi>
#define vcc vector<vc>
#define mi map<int,int>
#define mc map<char,int>
#define ll long long
#define ld long double
#define sortx(X) sort(X.begin(),X.end());
 
using namespace std;
 
void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
 
const int MODE = 1000000007;
 
 
void solve() {
	ll n;
	cin >> n;
	vector<vector<char>> X(n + 1, vector<char>(n + 1, '.'));
	vector<vector<ll>> Z(n+1, vector<ll>(n+1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> X[i][j];
		}
	}
 
	if (X[0][0] == '*')
	{
		cout << 0;
		return;
	}
 
	Z[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (X[i][j+1] != '*')
			{
				Z[i][j + 1] += Z[i][j];
				Z[i][j + 1] %= MODE;
			}
			if (X[i + 1][j] != '*')
			{
				Z[i + 1][j] += Z[i][j];
				Z[i][j + 1] %= MODE;
			}
		}
	}
	cout << Z[n-1][n-1];
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
