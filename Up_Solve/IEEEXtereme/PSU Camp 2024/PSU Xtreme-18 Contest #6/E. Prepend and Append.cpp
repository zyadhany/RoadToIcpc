#include<bits/stdc++.h>


#define vi vector<int>
#define vc vector<char>
#define vii vector<vi>
#define vcc vector<vc>
#define ll long long
#define forx(n,X) for (ll i = 0; i < n; i++)cin >> X[i];
#define forxx(n,m,X) for (ll i = 0; i < n; i++)for (ll j = 0; j < m; j++)cin >> X[i][j];
#define sortx(X) sort(X.begin(),X.end());


using namespace std;



void FP()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int fac(vi X, int n) {

	int a = 0, b = 0;

	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			if (X[i] + X[j] == n)
			{
				a = X[i]; b = X[j];
				goto XX;
			}

	return 1;
XX:;  
	return fac(X, a)+ fac(X, b);

}

void solve() {
	int n , summ = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] + s[n - 1 - i] - 2 * '0' == 1)
		{
			summ += 2;
		}
		else break;
	}
	cout << n - summ << '\n';
}

int main()
{
	FP();
	int size = 1;
	cin >> size;
	while (size--)
	{
		solve();
	}
}
